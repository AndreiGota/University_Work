package view;

import CustomExceptions.AnimalNotFound;
import CustomExceptions.InputException;
import CustomExceptions.OutOfBounds;
import controller.Controller;
import model.Animal;
import model.Fish;
import model.Turtle;

import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class View {
    Controller controller;

    public View(Controller ctrl){
        this.controller=ctrl;
    }

    public void printMenu()
    {
        System.out.println("0-exit");
        System.out.println("1-add");
        System.out.println("2-print all");
        System.out.println("3-filter");
        System.out.println("4-remove");
    }

    public void run() throws OutOfBounds, InputException {
        do {
            printMenu();
            Scanner scanner=new Scanner(System.in);
            System.out.println("give option: ");
            String option=scanner.nextLine();
            try {
            switch(option) {
                    case "0":
                        return;
                    case "1":
                        System.out.println("Provide type of animal:");
                        String type = scanner.nextLine();
                        System.out.println("How old is the animal:");
                        String yearInput = scanner.nextLine();
                        int year;
                        year = Integer.parseInt(yearInput);
                        if (Objects.equals(type, "fish")) {
                            Fish fish = new Fish(year);
                            controller.addAnimal(fish);
                        } else {
                            Turtle turtle = new Turtle(year);
                            controller.addAnimal(turtle);
                        }
                        break;
                    case "2":
                        System.out.println("Animals are: ");
                        for (Animal i : this.controller.getAll())
                            System.out.println(i.toString());
                        break;
                    case "3":
                        System.out.println("Animals older than 1 year: ");
                        List<Animal> filteredAnimals = this.controller.filter();
                        for (Animal i : filteredAnimals)
                            System.out.println(i.toString());
                        break;
                    case "4":
                        System.out.println("Type of the animal to delete ");
                        type = scanner.nextLine();
                        System.out.println("Year of the animal to delete ");
                        yearInput = scanner.nextLine();
                        year = Integer.parseInt(yearInput);
                        if (Objects.equals(type, "fish")) {
                            Fish fish = new Fish(year);
                            controller.removeAnimal(fish);
                        } else {
                            Turtle turtle = new Turtle(year);
                            controller.removeAnimal(turtle);
                        }

                        break;
                }
            } catch (NumberFormatException | AnimalNotFound  | OutOfBounds e) {
                System.out.println(e.getMessage());
            }
        }while(true);
    }
}

