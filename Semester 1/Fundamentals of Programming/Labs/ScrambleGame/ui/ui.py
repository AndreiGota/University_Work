from service.game_service import Service


class UI:
    def __init__(self, service: Service):
        # Initializes a UI object with an instance of the Service class as its service attribute
        self.__service = service

    def play_game(self):
        # Initializes the game by selecting a sentence and scrambling it
        self.__service.select_sentence()
        self.__service.scramble_sentence()

        while True:
            # Displays the current sentence and scrambled sentence along with the score
            print(self.__service.get_sentence())
            print(self.__service.get_scrambled_sentence(), f'(Score is: {self.__service.get_score()})')

            # Prompts the user to enter a command
            command = input('>>>')

            # Splits the command into its individual arguments and strips each argument of whitespace
            command_args = command.strip().split()

            for arg in command_args:
                arg.strip()

            # Executes the command based on its first argument
            if command_args[0] == 'undo':
                try:
                    # Calls the service's undo method to undo the previous move
                    self.__service.undo()
                except ValueError as ve:
                    # Displays an error message if undo is not possible
                    print(str(ve))

            elif command_args[0] == 'swap':
                if len(command_args) != 6:
                    # Displays an error message if the number of arguments is invalid
                    print('Invalid numbers of arguments!')
                    continue

                try:
                    # Parses the arguments to extract the indices of the two letters to be swapped
                    word1 = int(command_args[1])
                    letter1 = int(command_args[2])
                    word2 = int(command_args[4])
                    letter2 = int(command_args[5])
                except ValueError:
                    # Displays an error message if the arguments are invalid
                    print('Invalid arguments!')
                    continue

                try:
                    # Calls the service's make_swap method to swap the two letters
                    self.__service.make_swap(word1, letter1, word2, letter2)
                except ValueError as ve:
                    # Displays an error message if the swap is not possible
                    print(str(ve))

            else:
                # Displays an error message if the command is not recognized
                print('Invalid command!')

            # Checks if the game is over and ends the loop if it is
            game_status = self.__service.check_if_game_over()
            if game_status == -1:
                print('You lost!')
                break
            elif game_status == 1:
                print(f'You won! (Score: {self.__service.get_score()})')
                break
