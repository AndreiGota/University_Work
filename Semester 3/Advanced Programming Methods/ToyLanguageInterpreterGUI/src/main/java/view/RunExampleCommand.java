package view;

import controller.Controller;
import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;

import java.io.IOException;
import java.util.Objects;
import java.util.Scanner;

public class RunExampleCommand extends Command {
    private final Controller controller;

    public RunExampleCommand(String key, String description, Controller controller) {
        super(key, description);
        this.controller = controller;
    }
    @Override
    public void execute() {
        try {
            //execute all steps
            System.out.println("Display the steps?[yes/no]");
            Scanner readOption = new Scanner(System.in);
            String option = readOption.next();
            controller.setDisplayFlag(Objects.equals(option, "yes"));
            controller.allSteps();
        } catch (InterruptedException exception) {
            System.out.println(exception.getMessage());
        }
    }
}