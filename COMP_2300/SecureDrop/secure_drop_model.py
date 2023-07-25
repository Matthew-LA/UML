import json
from utilities import *
from Crypto.Hash import SHA256


class User:
    def __init__(self, password):
        user_file = open("users.json", "r+")
        user_json = json.load(user_file)
        user_file.close()

        self.email = user_json["user"][0]["email"]
        self.name = user_json["user"][0]["name"]
        self.password_hash = user_json["user"][0]["password"]
        self.salt = user_json["user"][0]["salt"]
        
        self.contact_list = list()
        self.contact_on_list = list()
        self.contact_ping_list = list()
        self.contact_create_list(password)

    # Print contacts in users contact list
    def get_list(self):
        for item in self.contact_list:
            print(item)

    # Get the contacts from the online contacts list with input of email
    def get_contact(self, email: str):
        for contact in self.contact_on_list:
            if email == contact["email"]:
                return contact
        return None

    # If the contact is online returns true
    def is_contact_on (self, email: str):
        for contact in self.contact_on_list:
            if email == contact["email"]:
                return True
        return False

    def print_contact_on_list(self):
        print("The following contacts are online:")
        for item in self.contact_on_list:
            print(" * " + item["name"] + " <" + item["email"] + ">")

    # Genertates users lists of contacts and if the users ping list is populated from upd process
    # Populate the list of online contacts.
    def contact_create_list(self, password):
        key = contacts_gen_key(password, self.salt)
        contacts_decrypt(key)
        self.contact_list.clear()
        self.contact_on_list.clear()
        contact_file = open("contacts.json")
        contact_json = json.load(contact_file)
        contact_file.close()

        for contact in contact_json["contacts"]:
            self.contact_list.append(contact)

        for contact_dict in self.contact_list:
            for contact_ping in self.contact_ping_list:
                h_email = SHA256.new()
                h_email.update(str(contact_dict['email']).encode())
                t = h_email.hexdigest()
                if t == contact_ping["Email"]:
                    contact_dict["IP"] = contact_ping["IP"]
                    contact_dict["public_key"] = contact_ping["public_key"]
                    if not contact_dict in self.contact_on_list:
                        self.contact_on_list.append(contact_dict)
                    else:
                        pass
                else:
                    pass
        contacts_encrypt(key)
        self.contact_ping_list.clear()
