import random

from domain.question import Question
from repository.file_repo import FileRepo
import copy


class Service:
    def __init__(self, repo: FileRepo):
        """
        Initialize Service object with a FileRepo object.
        :param repo: FileRepo object used to store Question objects.
        """
        self.__repo = repo

    def add_question(self, id, text, answers, correct_answer, difficulty):
        """
        Add a new question to the repository.
        :param id: integer representing the question ID.
        :param text: string representing the question text.
        :param answers: list of 3 strings representing the possible answers to the question.
        :param correct_answer: string representing the correct answer to the question.
        :param difficulty: string representing the difficulty level of the question (easy, medium or hard).
        """
        question = Question(id, text, answers, correct_answer, difficulty)

        self.__repo.add(question)

    def __count_by_difficulty(self, difficulty):
        """
        Count the number of questions in the repository with the given difficulty.
        :param difficulty: string representing the difficulty level of the question (easy, medium or hard).
        :return: integer representing the number of questions with the given difficulty in the repository.
        """
        counter = 0

        for question in self.__repo.get_all():
            if question.difficulty == difficulty:
                counter += 1

        return counter

    def __get_questions(self, difficulty, number_of_questions):
        """
        Create a list of questions for a quiz with the given difficulty and number of questions.
        :param difficulty: string representing the difficulty level of the question (easy, medium or hard).
        :param number_of_questions: integer representing the number of questions to include in the quiz.
        :return: list of Question objects representing the quiz questions.
         """
        questions = copy.deepcopy(self.__repo.get_all())
        quiz = []

        half = number_of_questions // 2 + number_of_questions % 2

        while len(quiz) < half:
            question = random.choice(questions)
            questions.remove(question)

            if question.difficulty == difficulty:
                quiz.append(question)

        while len(quiz) < number_of_questions:
            question = random.choice(questions)
            questions.remove(question)
            quiz.append(question)

        return quiz

    @staticmethod
    def __save_quiz_to_file(quiz, file_name):
        """
        Save a list of questions to a file.
        :param quiz: list of Question objects representing the questions in the quiz.
        :param file_name: string representing the name of the file to save the quiz to.
        """
        with open(file_name, 'wt') as file:
            for question in quiz:
                file.write(f'{question.id};{question.text};{question.answers[0]};{question.answers[1]};'
                           f'{question.answers[2]};{question.correct_answer};{question.difficulty}\n')

    def create_quiz(self, difficulty, number_of_questions, file_name):
        """
        Create a quiz with the given difficulty and number of questions, and save it to a file.
        :param difficulty: string representing the difficulty level of the question (easy, medium or hard).
        :param number_of_questions: integer representing the number of questions to include in the quiz.
        :param file_name: string representing the name of the file to save the quiz to.
        """
        if difficulty not in ['easy', 'medium', 'hard']:
            raise ValueError('Difficulty is not easy/medium/hard!')

        if number_of_questions <= 0:
            raise ValueError('Number of questions must be an positive integer!')

        if len(self.__repo) < number_of_questions:
            raise ValueError(f'Quiz cannot be created because there are not at least {number_of_questions} questions!')

        question_with_difficulty = self.__count_by_difficulty(difficulty)

        if question_with_difficulty < number_of_questions // 2 + number_of_questions % 2:
            raise ValueError(f'Quiz cannot be created because there are not at least '
                             f'{number_of_questions // 2 + number_of_questions % 2} '
                             f'questions with difficulty {difficulty}!')

        quiz = self.__get_questions(difficulty, number_of_questions)

        self.__save_quiz_to_file(quiz, file_name)

    @staticmethod
    def __load_quiz(file_name):
        """
        Load a list of questions from a file.
        :param file_name: string representing the name of the file to load the quiz from.
        :return: list of Question objects representing the quiz questions.
        """
        quiz = []

        try:
            file = open(file_name, 'rt')
        except IOError:
            return quiz

        for line in file.readlines():
            question_args = line.strip().split(';')

            id = int(question_args[0])
            text = question_args[1]
            answers = question_args[2:5]
            correct_answer = question_args[5]
            difficulty = question_args[6]

            question = Question(id, text, answers, correct_answer, difficulty)
            quiz.append(question)

        return quiz

    def start_quiz(self, file_name):
        """
        Load a quiz from a file and sort the questions by ID.
        :param file_name: string representing the name of the file to load the quiz from.
        :return: list of Question objects representing the sorted quiz questions.
        """
        quiz = self.__load_quiz(file_name)

        sorted_quiz = sorted(quiz)

        return sorted_quiz

    @staticmethod
    def compute_score(quiz, quiz_answers):
        """
        Compute the score of a quiz given a list of answers.
        :param quiz: list of Question objects representing the quiz questions.
        :param quiz_answers: list of strings representing the answers to the quiz questions.
        :return: integer representing the score of the quiz.
        """
        score = 0
        for i in range(len(quiz)):
            if quiz[i].correct_answer == quiz_answers[i]:
                if quiz[i].difficulty == 'easy':
                    score += 1

                elif quiz[i].difficulty == 'medium':
                    score += 2

                elif quiz[i].difficulty == 'hard':
                    score += 3

        return score
