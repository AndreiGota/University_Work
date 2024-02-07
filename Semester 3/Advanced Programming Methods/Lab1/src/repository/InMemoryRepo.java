package repository;

import CustomExceptions.AnimalNotFound;
import CustomExceptions.OutOfBounds;
import model.Animal;

public class InMemoryRepo implements IRepository{
    Animal[] animals;
    int len;

    public InMemoryRepo() {
        this.animals = new Animal[5];
        len = 0;
    }
    @Override
    public void addAnimal(Animal animal) throws OutOfBounds {
        if (len == this.animals.length)
            throw new OutOfBounds("capacity exceeded");
        this.animals[len++] = animal;
    }

    @Override
    public void removeAnimal(Animal animal) throws AnimalNotFound {
        int indexToRemove = -1;
        for (int i = 0; i < len; i++) {
            if (animals[i] != null && animals[i].equals(animal)) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove != -1) {
            for (int i = indexToRemove; i < len - 1; i++) {
                animals[i] = animals[i + 1];
            }
            animals[len - 1] = null;
            len--;
        } else {
            throw  new AnimalNotFound("Animal doesn't exist");
        }
    }

    @Override
    public Animal[] getAll() {
        return animals;
    }

    @Override
    public int getCurrLen() {
        return this.len;
    }
}
