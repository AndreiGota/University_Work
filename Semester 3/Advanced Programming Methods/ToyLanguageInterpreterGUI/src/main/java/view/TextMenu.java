package view;

import exceptions.UtilsException;
import model.utils.IDictionary;
import model.utils.MyDictionary;

import java.util.Scanner;

public class TextMenu {
    private IDictionary<String, Command> commands;

    public TextMenu() {
        commands = new MyDictionary<>();
    }

    public void addCommand(Command cmd) {
        commands.put(cmd.getKey(), cmd);
    }

    public void printMenu() {
        for (Command cmd: commands.values()) {
            String line = String.format("%4s : %s", cmd.getKey(), cmd.getDescription());
            System.out.println(line);
        }
    }

    public void show() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Toy Language Interpreter");

        while (true) {
            printMenu();
            System.out.println("Input the option: ");
            String key = scanner.nextLine();

            try {
                Command command = commands.lookUp(key);
                command.execute();
            } catch (UtilsException e) {
                System.out.println("Invalid option!");
            }
        }
    }
}
