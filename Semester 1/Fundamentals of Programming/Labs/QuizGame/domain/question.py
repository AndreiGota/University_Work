class Question:
    def __init__(self, id, text, answers, correct_answer, difficulty):
        """
        Constructor method that initializes the attributes of the Question object.

        Parameters:
        - id (int): the unique identifier of the question
        - text (str): the text of the question
        - answers (list of str): the possible answers to the question
        - correct_answer (str): the correct answer to the question
        - difficulty (str): the difficulty level of the question, which can be "easy", "medium", or "hard"
        """
        self.__id = id
        self.__text = text
        self.__answers = answers
        self.__correct_answer = correct_answer
        self.__difficulty = difficulty

    @property
    def id(self):
        """
        Getter method that returns the value of the id attribute.
        """
        return self.__id

    @property
    def text(self):
        """
        Getter method that returns the value of the text attribute.
        """
        return self.__text

    @property
    def answers(self):
        """
        Getter method that returns the value of the answers attribute.
        """
        return self.__answers

    @property
    def correct_answer(self):
        """
        Getter method that returns the value of the correct_answer attribute.
        """
        return self.__correct_answer

    @property
    def difficulty(self):
        """
        Getter method that returns the value of the difficulty attribute.
        """
        return self.__difficulty

    def __lt__(self, other):
        """
        Special method that defines the less-than operator (<) for Question objects. It returns True if the difficulty of the current
        question is lower than the difficulty of the other question, according to the following rules:
        - if the difficulty of the current question is "easy", it is always lower than the difficulty of any other question
        - if the difficulty of the current question is "medium", it is lower than the difficulty of the other question only if the
          other question is "hard" or "medium"
        - if the difficulty of the current question is "hard", it is lower than the difficulty of the other question only if the
          other question is "hard"

        Parameters:
        - other (Question): the other question to compare with

        Returns:
        - bool: True if the difficulty of the current question is lower than the difficulty of the other question, False otherwise.
        """
        if self.__difficulty == 'easy':
            return True

        if self.__difficulty == 'medium' and other.__difficulty in ['medium', 'hard']:
            return True

        if self.__difficulty == 'hard' and other.__difficulty == 'hard':
            return True

        return False
