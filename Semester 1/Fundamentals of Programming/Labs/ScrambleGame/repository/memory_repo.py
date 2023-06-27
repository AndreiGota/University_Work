class MemoryRepo:
    def __init__(self):
        # initialize an empty list to store the sentences
        self._data = []

    def find(self, sentence):
        # search the list of sentences for a match to the given sentence
        for item in self._data:
            if sentence == item:
                # if it finds a match, return the matched sentence
                return item

        # if it does not find a match, return None
        return None

    def add(self, sentence):
        # check if the sentence already exists in the list of sentences
        if self.find(sentence) is not None:
            # if it does, raise a ValueError with the message 'Sentence already in repo!'
            raise ValueError('Sentence already in repo!')

        # if it does not, add the sentence to the list of sentences
        self._data.append(sentence)

    def get_all(self):
        # return a list of all the sentences in the repository
        return self._data
