from repository.memory_repo import MemoryRepo

'''
This module extends the MemoryRepo class and overrides its constructor to load sentences
from a file into the repository. It also defines a load_file method to handle the file reading 
and sentence adding. The method opens the file, reads each line, and adds each non-empty 
line to the repository using the parent class's add method.
'''


class FileRepo(MemoryRepo):
    def __init__(self, file_name='input.txt'):
        # call the parent class constructor to initialize an empty list to store the sentences
        super().__init__()

        # set the file name for the repository
        self.__file_name = file_name

        # load the sentences from the file into the repository
        self.load_file()

    def load_file(self):
        try:
            # open the file in read mode
            file = open(self.__file_name, 'rt')
        except IOError:
            # if the file cannot be opened, return without doing anything
            return

        # read each line in the file
        for line in file.readlines():
            # remove any leading or trailing whitespace from the line
            sentence = line.strip()

            # if the line is empty, skip to the next line
            if sentence == '':
                continue

            # add the sentence to the repository using the parent class's add method
            super().add(sentence)

        # close the file when finished
        file.close()
