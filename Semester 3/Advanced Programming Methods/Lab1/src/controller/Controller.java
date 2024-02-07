package controller;

import CustomExceptions.AnimalNotFound;
import CustomExceptions.OutOfBounds;
import model.Animal;
import repository.IRepository;

import java.util.ArrayList;
import java.util.List;

public class Controller {
    IRepository repo;
    public Controller(IRepository repo) {
        this.repo = repo;
    }
    public void addAnimal(Animal animal) throws OutOfBounds {
        this.repo.addAnimal(animal);
    }

    public void removeAnimal(Animal animal) throws AnimalNotFound {
        this.repo.removeAnimal(animal);
    }

    public List<Animal> filter() {
        List<Animal> filteredAnimals = new ArrayList<>();
        for (Animal animal: this.getAll()) {
            if (animal.getYear() > 1)
                filteredAnimals.add(animal);
        }

        return filteredAnimals;
    }

    public List<Animal> getAll()
    {
        List<Animal> Animals=new ArrayList<>();
        for(int i = 0; i < this.repo.getCurrLen(); i++)
        {
            Animals.add(this.repo.getAll()[i]);
        }
        return Animals;
    }
}
