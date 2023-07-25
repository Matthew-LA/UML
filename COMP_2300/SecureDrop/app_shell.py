from cmd import Cmd


class AppPrompt(Cmd):

    prompt = "secure_drop> "
    intro = "Welcome to SecureDrop.\n Type \"help\" For Commands."

    # Prints the available commands in the program if "help" command used.
    def do_help(self, inp):
        print(
            "\"add\"  -> Add a new contact\n"
            "\"list\" -> List all online contacts\n"
            "\"send\" -> Transfer file to contact\n"
            "\"exit\" -> Exit SecureDrop"
        )

    # Exit the program on "exit" command.
    def do_exit(self, inp):
        quit()

    def do_add(self, inp):
        print("Module 3 not implemented!")  # TODO: Milestone 3 to be completed

    def do_list(self, inp):
        print("Module 4 not implemented!")  # TODO: Milestone 4 to be completed

    def do_send(self, inp):
        print("Module 5 not implemented!")  # TODO: Milestone 5 to be completed

    def default(self, inp):
        print("Enter a valid command!")

# Run the program shell on loop until break condition is not match.
def start_cmd():
    AppPrompt().cmdloop()
