import os.path
import json
import multiprocessing
from threading import *
from utilities import *
from login import user_login
from user_registration import user_registration
from app_shell import start_cmd
from secure_drop_model import User
from secure_drop_services import *

# Handles the initial login. If there are no registered users, then the function
# will run user_registration(file)

def main():
    """
    The user registration is a one-time process. Once a user is registered on a
    client, the login module is activated subsequently. After a successful
    login, a "secure_drop>" shell is started.
    """
    if os.path.isfile(USER_LIST) and os.path.getsize(USER_LIST) > 0:
        password = user_login()
    else:
        print(
                "No users are registered with this client."
                "\nDo you want to register a new user (y/n)?"
                )
        inp = ""
        while inp != "y" and inp != "n":
            inp = input()
            if inp == "y":
                users_file = open("users.json", "w+")
                users_file.write("{ \t\"user\": [] }")
                users_file.seek(0)
                gen_RSA_keys()
                user_registration()
            elif inp == "n":
                exit(1)
    run_app_shell(password)


def run_app_shell(password):
    try:
        # Creates a new instance of the User class and initializes it with the password provided.
        # It then retrieves the user's public key and starts two processes, one for sending UDP messages
        # and another for receiving them. The UDP_client process takes the User instance and a process_q
        # queue as arguments. The process_q queue is used to communicate between the two processes.
        user = User(password)
        public_key = get_public_key()
        encrypt_key = contacts_gen_key(password, user.salt)
        do_run = True

        udp_send_process = multiprocessing.Process(target=UDP_server, args=(user.email, public_key,))
        udp_send_process.start()
        udp_rec_process = multiprocessing.Process(target=UDP_client, args=(user,))
        
        tcp_process = multiprocessing.Process(target=tcp_server)
        tcp_process.start()
        
        process_q = multiprocessing.Queue()

        print("\nWelcome to SecureDrop\n")
        print("Type \"help\" For Commands.\n\n")
    
        while (do_run):
            u_input = input("secure_drop>")
            user_input = u_input.split(" ")
            
            match user_input[0].lower():

                case "help":
                    list_commands()

                case "exit":
                    exit()
                case "quit":
                    exit()
                case "close":
                    exit()

                case "add":
                    contacts_decrypt(encrypt_key)
                    contacts_add()
                    contacts_encrypt(encrypt_key)
                    
                    user.contact_create_list(password)

                case "list":
                    udp_rec_process = multiprocessing.Process(target=UDP_client, args=(user, process_q))
                    udp_rec_process.start()
                    
                    user = process_q.get()
                    user.contact_create_list(password)
                    user.print_contact_on_list()
                    
                    udp_rec_process.kill()
                    
                case "send":
                    receivers_email = user_input[1]
                    file_to_send = user_input[2]
                    file_name = os.path.basename(file_to_send)
                    sender = {"email": user.email, "name": user.name, "file_location": file_to_send, "file_name": file_name}
                    
                    if os.path.exists(file_to_send):
                        tcp_client(user.get_contact(receivers_email), sender)
                    else:
                        print(file_name + " does not exist")
                    

                case _:
                    print("Invalid Command\n")


    finally:
        del password
        del encrypt_key
        del user
        udp_send_process.kill()
        udp_rec_process.kill()
        tcp_process.kill()
        


if __name__ == "__main__":
    main()




            
    




    #start_cmd()
