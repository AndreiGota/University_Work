import CustomExceptions.InputException;
import CustomExceptions.OutOfBounds;
import controller.Controller;
import model.Fish;
import model.Turtle;
import repository.IRepository;
import repository.InMemoryRepo;
import view.View;

public class Main {
    public static void main(String[] args) throws OutOfBounds, InputException {
        Fish fish1 = new Fish(1);
        Fish fish2 = new Fish(2);
        Turtle turtle1 = new Turtle(2);
        Turtle turtle2 = new Turtle(7);
        IRepository repo=new InMemoryRepo();
        Controller ctrl=new Controller(repo);
        ctrl.addAnimal(fish1);
        ctrl.addAnimal(fish2);
        ctrl.addAnimal(turtle1);
        ctrl.addAnimal(turtle2);
        View view=new View(ctrl);
        view.run();
    }
}