class UndoService:
    def __init__(self):
        # initialize an empty list to store the operations
        self.__operations = []

    def add_operation(self, word1, letter1, word2, letter2):
        # add a new operation to the list
        self.__operations.append([word1, letter1, word2, letter2])

    def get_last_operation(self):
        # check if there are any operations to undo
        if len(self.__operations) == 0:
            # if there are none, raise a ValueError with the message 'No operation to undo!'
            raise ValueError('No operation to undo!')

        # remove and return the most recent operation from the list
        return self.__operations.pop()
