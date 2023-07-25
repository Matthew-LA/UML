import re
import crypt
import string
import json
from getpass import getpass
from Crypto.Cipher import AES
from Crypto.PublicKey import RSA
from Crypto.Protocol.KDF import PBKDF2

MAX_TIMES_ALLOWED_TO_ENTER = 3
USER_LIST = "./users.json"
USER_EMAIL = ""
USER_NAME = ""
USER_PASS = ""

def password_check(password):
    """
    Verify the strength of 'password'
    Returns a dict indicating the wrong criteria
    A password is considered strong if:
        8 characters length or more
        1 digit or more
        1 symbol or more
        1 uppercase letter or more
        1 lowercase letter or more
    """
    # length
    length_error = len(password) < 8

    # searching for digits
    digit_error = re.search(r"\d", password) is None

    # searching for uppercase
    uppercase_error = re.search(r"[A-Z]", password) is None

    # searching for lowercase
    lowercase_error = re.search(r"[a-z]", password) is None

    # searching for symbols
    symbol_error = re.search(r"\W", password) is None

    # overall result
    password_ok = not (
        length_error
        or digit_error
        or uppercase_error
        or lowercase_error
        or symbol_error
    )

    return {
        "password_ok": password_ok,
        "length_error": length_error,
        "digit_error": digit_error,
        "uppercase_error": uppercase_error,
        "lowercase_error": lowercase_error,
        "symbol_error": symbol_error,
    }

def get_password():
    password = getpass("Enter password: ")
    return password

def register_email():
    email = input("Enter email: ")
    return email

def get_email_and_password():
    password = get_password()
    email = register_email()
    return (email, password)

def check_email():
    # function check_email allows the user to attempt to enter their password 3 times before exiting

    # regular expression for validating email
    regex = "^[a-z0-9]+[\._]?[a-z0-9]+[@]\w+[.]\w{2,3}$"

    email_enter_attempts = 0

    while email_enter_attempts < MAX_TIMES_ALLOWED_TO_ENTER:
        email = input("Enter email: ")
        if re.search(regex, email):
            email_enter_attempts = MAX_TIMES_ALLOWED_TO_ENTER
            return email
        else:
            print("Invalid Email")
            email_enter_attempts += 1
    return None

def hash_password(password, salt):
    return crypt.crypt(password, salt)
    
def contacts_add():
    contacts_file = open("contacts.json","r+")
    contacts_json = json.load(contacts_file)
    
    email = check_email()
    name = input("Enter Full Name: ")
    info = {"name":name,"email":email}
    
    Contacts = contacts_json["contacts"]
	
    # if contact is already in list update
    do_append = True
    for contact in Contacts:
        if str(contact["email"]).__eq__(email):
            contact["name"] = name
            print("Contact has been updated\n")
            do_append = False
    
    # else append to list
    if do_append:
        Contacts.append(info)
        print("Contact has been added")
        
    contacts_file.seek(0)
    json.dump(contacts_json, contacts_file, indent=4)
    contacts_file.close()
   
# key generation for contacts encryption
def contacts_gen_key (password, user_salt):
    salt = str(user_salt).encode()
    key = PBKDF2(password,user_salt,32)
    return key

# endcrypt contact using AES and the generated key
def contacts_encrypt (key):
    contacts_file = open("contacts.json","r+")
    info = ""
    for i in contacts_file:
        info+=i
        
    contacts_file.truncate(0)
    contacts_file.close()

    cipher = AES.new(key, AES.MODE_EAX)
    ciphertext, tag = cipher.encrypt_and_digest(info.encode())

    # Opens "contacts.json" in byte mode and writes
    # nonce, tag, and ciphertext generated the a cipher
    contacts_byte_file = open("contacts.json","wb")
    [ contacts_byte_file.write(j) for j in (cipher.nonce, tag, ciphertext) ]
    contacts_byte_file.close()

# decrypt contacts
def contacts_decrypt (key):
    # Opens "contacts.json" in byte mode and read in three separate parts,
    # with the first two being read as 16 bytes each and the third being read until
    # the end of the file (-1). The resulting three parts are then assigned to the
    # variables nonce, tag, and ciphertext, respectively.
    contacts_file = open("contacts.json","rb")
    nonce, tag, ciphertext = [ contacts_file.read(j) for j in (16, 16, -1) ]
    contacts_file.close()

    cipher = AES.new(key, AES.MODE_EAX, nonce)
    
    # try to decrypt contacts
    try:
        info = cipher.decrypt_and_verify(ciphertext, tag)
    
    # failure results in removal of contact file and generate the template
    except:
        contacts_file = open("contacts.json","r+")
        contacts_file.truncate(0)
        contacts_file.write("{\n\t\"contacts\": [] \n}")
        contacts_file.seek(0)
        contacts_encrypt(key)
        print("***Error: Verification of contacts has failed***\n")
        print("***Contact list has been cleared for security reasons***")
        exit()
   
    contacts_file = open("contacts.json","r+")
    contacts_file.truncate(0)
    contacts_file.write(info.decode())
    
def gen_RSA_keys ():
    key = RSA.generate(2048)
    private_key = key.export_key()
    private_key_file = open("private_key.pem", "wb")
    private_key_file.write(private_key)
    private_key_file.close()

    public_key = key.publickey().export_key()
    public_key_file = open("public_key.pem", "wb")
    public_key_file.write(public_key)
    public_key_file.close()

def get_public_key ():
    key = RSA.import_key(open("public_key.pem").read())
    return str(key.export_key())
    
def tcp_alert ():
    response = input("Do you want to receive the file? (yes/no) ")
    return response

def list_commands ():
    print ("\"add\"  -> Add a new contact")
    print ("\"list\" -> List all online contacts")
    print ("\"send\" -> Transfer file to contacts")
    print ("\"exit\" -> Exit SecureDrop")
