class MemoryRepo:
    def __init__(self):
        """
        Initialize an empty list to store data in the repository.
        """
        self.__data = []

    def find_by_id(self, item_id):
        """
        Find and return an item in the repository with the given id.
        :param item_id: the id of the item to search for
        :return: the item in the repository with the given id, or None if no such item is found
        """
        for item in self.__data:
            if item.id == item_id:
                return item

        return None

    def add(self, item):
        """
        Add an item to the repository.
        :param item: the item to add to the repository
        :return:
        :raises: ValueError if an item with the same id already exists in the repository
        """
        if self.find_by_id(item.id) is not None:
            raise ValueError(f'Item with id {item.id} already in repo!')

        self.__data.append(item)

    def remove_by_id(self, item_id):
        """
        Remove an item from the repository with the given id.
        :param item_id: the id of the item to remove from the repository
        :return:
        :raises: ValueError if no item with the given id exists in the repository
        """
        item = self.find_by_id(item_id)

        if item is None:
            raise ValueError(f'Item with id {item_id} not in repo!')

        self.__data.remove(item)

    def get_all(self):
        """
        Return a list of all items in the repository.
        """
        return self.__data

    def __len__(self):
        """
        Return the number of items in the repository.
        """
        return len(self.__data)
