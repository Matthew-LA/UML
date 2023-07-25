from utilities import USER_LIST, MAX_TIMES_ALLOWED_TO_ENTER, USER_EMAIL, USER_PASS
from utilities import check_email, get_password, hash_password
import utilities
import json

def user_login():
    # This function allows the user to enter their password a maximum of three times before exiting.
    number_of_password_login_attempts = 0
    do_login = False
    global USER_PASS
    global USER_EMAIL
    email = check_email()
    utilities.USER_EMAIL = email

    json_data = open("users.json")
    jdata = json.load(json_data)
    user_data = jdata["user"]
    # Case where email exists in JSON file
    for user in jdata["user"]:
        if user["email"] == email:
            print("Email exists, you may proceed with the app!")
            while number_of_password_login_attempts < MAX_TIMES_ALLOWED_TO_ENTER:
                password = get_password()
                old_pass = user["password"]
                salt = user["salt"]
                new_pass = hash_password(password, salt)
                if old_pass == new_pass:
                    do_login = True
                    number_of_password_login_attempts = 4
                else:
                    print("Email and Password Combination Invalid.")
                    do_login = False
                    number_of_password_login_attempts += 1
        # Exit if no email found in the file.
        else:
            print("\nNo users are registered with this Email")
            print("Exiting\n")

    if do_login:
        return password
    else:
        exit()


#def user_login():
    # if login_helper fails (returns False), then exit the program as the user mis-entered their email or password more than 3 times
    #if not login_helper():
     #   exit()
