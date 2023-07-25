from utilities import register_email, get_password, password_check, check_email
from utilities import hash_password, contacts_gen_key, contacts_encrypt
from getpass import getpass
import json
import secrets

'''User registration Function.  Checks password for complexity and for matching. 
If it passes the checks it then hashes the password and stores
the hash and salt for login later.'''

def user_registration():
    email = check_email()
    name = input("Enter Full name: ")
    password = get_password()
    second_pass = getpass("Re-enter Password: ")
    check = password_check(password)

    # loop until password is correct
    while not check.get("password_ok") or password != second_pass:
        if not check.get("password_ok"):
            # Requirements for a secure password
            print(
                    "Password is not strong enough. A password is considered strong if:"
                    "\n8 characters length or more"
                    "\n1 digit or more"
                    "\n1 symbol or more"
                    "\n1 uppercase letter or more"
                    "\n1 lowercase letter or more."
                    )
            password = getpass("Enter password:")
            second_pass = getpass("Re-enter Password")
            check = password_check(password)
        elif password != second_pass:
            print("Passwords don't match.")
            second_pass = getpass("Re-enter Password: ")
    
    salt = secrets.token_hex(8)
    h_password = hash_password(password, salt)
    contacts_key = contacts_gen_key(password, salt)

    # create user.json file
    users_file = open("users.json", "r+")
    users_json = json.load(users_file)
    info = {"email": email, "name": name, "password": h_password, "salt": salt}
    users_json["user"].append(info)
    users_file.seek(0)
    json.dump(users_json,users_file, indent = 4)
    users_file.close()
    print("\n* users.json * file was successfully created.")

    # creat contacts.json file
    contacts_file = open("contacts.json","w+")
    contacts_file.write("{ \t\"contacts\": [] }")
    contacts_file.seek(0)
    contacts_encrypt(contacts_key)
    contacts_file.close
    print("* contacts.json * file was successfully created and encrypted.")
    
    del password
    del second_pass
    del check
    del contacts_key

    # Requires user to re-login once they have registered
    print("\nUser sucessfully registered, please login again to proceed with the app.")
    exit()
