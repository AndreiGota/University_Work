package repository;


import CustomExceptions.AnimalNotFound;
import CustomExceptions.OutOfBounds;
import model.Animal;

public interface IRepository {
    void addAnimal(Animal animal) throws OutOfBounds;
    void removeAnimal(Animal animal) throws AnimalNotFound;
    Animal[] getAll();
    int getCurrLen();
}
