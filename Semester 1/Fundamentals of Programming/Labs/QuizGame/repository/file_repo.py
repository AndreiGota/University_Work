from domain.question import Question
from repository.memory_repo import MemoryRepo


class FileRepo(MemoryRepo):
    def __init__(self, file_name='question list.txt'):
        """
        Initialize a new FileRepo object.
        :param file_name: str, the name of the file to load/save the questions from/to.
        """
        super().__init__()
        self.__file_name = file_name

        # Load questions from file on initialization
        self.load_file()

    def load_file(self):
        """
        Load questions from file and add them to the repository.
        """
        try:
            file = open(self.__file_name, 'rt')
        except IOError:
            # If the file cannot be opened, simply return
            return

        # Parse each line of the file and create a Question object from it
        for line in file.readlines():
            question = line.strip()
            if question == '':
                continue

            question_args = question.split(';')
            id = int(question_args[0])
            text = question_args[1]
            choices = question_args[2:5]
            correct_choice = question_args[5]
            difficulty = question_args[6]

            item = Question(id, text, choices, correct_choice, difficulty)

            # Add the question to the repository
            super().add(item)

        file.close()

    def save_file(self):
        """
        Save all questions to file.
        """
        file = open(self.__file_name, 'wt')

        # Write each question to file as a separate line
        for question in self.get_all():
            file.write(f'{question.id};{question.text};{question.answers[0]};{question.answers[1]};'
                       f'{question.answers[2]};{question.correct_answer};{question.difficulty}\n')

        file.close()

    def add(self, item):
        """
        Add a new question to the repository and save it to file.
        :param item: Question, the question to be added.
        """
        super().add(item)
        self.save_file()

    def remove_by_id(self, item_id):
        """
        Remove a question from the repository by its ID and save the updated repository to file.
        :param item_id: int, the ID of the question to be removed.
        """
        super().remove_by_id(item_id)
        self.save_file()
