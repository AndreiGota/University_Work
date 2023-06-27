import copy
import random

from repository.file_repo import FileRepo
from service.undo_service import UndoService


class Service:
    """
    Initializes the Service class.
    :param repo: FileRepo object
    :param undo_service: UndoService object
    """
    def __init__(self, repo: FileRepo, undo_service: UndoService):
        self.__repo = repo
        self.__undo_service = undo_service
        self.__sentence = []
        self.__scrambled_sentence = []
        self.__score = 0

    def make_swap(self, word1, letter1, word2, letter2):
        """
        Swaps two letters in two different words from scrambled sentence.
        :param word1: string
        :param letter1: string
        :param word2: string
        :param letter2: string
        :return: None
        """
        if word1 < 0 or word1 >= len(self.__sentence):
            raise ValueError('First word index is incorrect!')

        if word2 < 0 or word2 >= len(self.__sentence):
            raise ValueError('Second word index is incorrect!')

        if letter1 < 1 or letter1 >= len(self.__scrambled_sentence[word1]) - 1:
            raise ValueError('First letter index is incorrect!')

        if letter2 < 1 or letter2 >= len(self.__scrambled_sentence[word2]) - 1:
            raise ValueError('Second letter index is incorrect!')

        self.__scrambled_sentence[word1][letter1], self.__scrambled_sentence[word2][letter2] = \
            self.__scrambled_sentence[word2][letter2], self.__scrambled_sentence[word1][letter1]

        self.__undo_service.add_operation(word1, letter1, word2, letter2)
        self.__score -= 1

    def undo(self):
        """
        Reverses the last swap operation made by player.
        :return: None
        """
        operation = self.__undo_service.get_last_operation()
        word1 = operation[0]
        letter1 = operation[1]
        word2 = operation[2]
        letter2 = operation[3]

        self.__scrambled_sentence[word1][letter1], self.__scrambled_sentence[word2][letter2] = \
            self.__scrambled_sentence[word2][letter2], self.__scrambled_sentence[word1][letter1]

    def check_if_game_over(self):
        """
        Function to check if the game ended.
        :return: integer
        Returns 1 if player won, -1 if player lost or 0 if game has not ended
        """
        if self.get_sentence() == self.get_scrambled_sentence():
            return 1

        if self.get_score() == 0:
            return -1

        return 0

    def get_all(self):
        """
        Gets all the sentences from the repository.
        :return: list
        """
        return self.__repo.get_all()

    def select_sentence(self):
        """
        Selects a random sentence from the repository and stores it in the sentence attribute.
        :return: None
        """
        sentences = self.get_all()
        sentence = random.choice(sentences)

        for word in sentence.split():
            letters = []
            for ch in word:
                letters.append(ch)
                self.__score += 1

            self.__sentence.append(letters)

    def __select_words(self):
        """
        Function to select two random words from the sentence and scramble them.
        It will swap two random letters from each word, for 20 times.
        :return: None
        """
        word1 = random.randint(0, len(self.__sentence) - 1)
        word2 = random.randint(0, len(self.__sentence) - 1)

        while len(self.__scrambled_sentence[word1]) <= 2 or len(self.__scrambled_sentence[word2]) <= 2:
            word1 = random.randint(0, len(self.__sentence) - 1)
            word2 = random.randint(0, len(self.__sentence) - 1)

        return word1, word2

    def scramble_sentence(self):
        """
        Scramble the sentence by randomly swapping some of its letters between two words.
        :return: None
        """
        self.__scrambled_sentence = copy.deepcopy(self.__sentence)

        for i in range(20):
            word1, word2 = self.__select_words()

            letter1 = random.randint(1, len(self.__scrambled_sentence[word1]) - 2)
            letter2 = random.randint(1, len(self.__scrambled_sentence[word2]) - 2)

            self.__scrambled_sentence[word1][letter1], self.__scrambled_sentence[word2][letter2] =\
                self.__scrambled_sentence[word2][letter2], self.__scrambled_sentence[word1][letter1]

    def get_sentence(self):
        """
        Function to get the original sentence.
        :return: string
        """
        sentence = ''
        for word in self.__sentence:
            for ch in word:
                sentence += ch

            sentence += ' '

        return sentence

    def get_scrambled_sentence(self):
        """
        Function to get the scrambled sentence.
        :return: string
        """
        scrambled_sentence = ''
        for word in self.__scrambled_sentence:
            for ch in word:
                scrambled_sentence += ch

            scrambled_sentence += ' '

        return scrambled_sentence

    def get_score(self):
        """
        Function to get the current score.
        :return: integer
        """
        return self.__score
