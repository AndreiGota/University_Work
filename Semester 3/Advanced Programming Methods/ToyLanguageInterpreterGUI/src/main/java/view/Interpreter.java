package view;

import controller.Controller;
import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.expression.*;
import model.statement.*;
import model.statement.file_statements.CloseReadFile;
import model.statement.file_statements.OpenReadFile;
import model.statement.file_statements.ReadFile;
import model.type.BoolType;
import model.type.IntType;
import model.type.RefType;
import model.type.StringType;
import model.utils.MyDictionary;
import model.utils.MyHeap;
import model.utils.MyList;
import model.utils.MyStack;
import model.value.BoolValue;
import model.value.IntValue;
import model.value.StringValue;
import repository.IRepository;
import repository.Repository;

import java.io.IOException;

public class Interpreter {
    public static void main(String[] args) throws UtilsException {
        // create the program state
        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));

        IStatement ex1 = new CompStatement(new VarDeclStatement("v", new IntType()),
                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VarExpression("v"))));

        try {
            ex1.typeCheck(new MyDictionary<>());
            ProgramState prg1 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex1);
            IRepository repo1;
            repo1 = new Repository(prg1, "log1.txt");
            Controller ctrl1 = new Controller(repo1);
            menu.addCommand(new RunExampleCommand("1", ex1.toString(), ctrl1));
        } catch (Exception e) {
            e.printStackTrace();
        }

        IStatement ex2 = new CompStatement(new VarDeclStatement("a", new BoolType()),
                new CompStatement(new VarDeclStatement("b", new IntType()),
                        new CompStatement(new AssignStatement("a", new ArithExpression('+', new ValueExpression(new IntValue(2)), new
                                ArithExpression('*', new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStatement(new AssignStatement("b", new ArithExpression('+', new VarExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStatement(new VarExpression("b"))))));

        try {
            ex2.typeCheck(new MyDictionary<>());
            ProgramState prg2 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex2);
            IRepository repo2;
            repo2 = new Repository(prg2, "log2.txt");
            Controller ctrl2 = new Controller(repo2);
            menu.addCommand(new RunExampleCommand("2", ex2.toString(), ctrl2));
        } catch (Exception e) {
            System.out.println("type check failed for ex2!");
            e.printStackTrace();
        }

        IStatement ex3 = new CompStatement(new VarDeclStatement("a", new BoolType()),
                new CompStatement(new VarDeclStatement("v", new IntType()),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompStatement(new IfStatement(new VarExpression("a"),
                                        new AssignStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VarExpression("v"))))));

        try {
            ex3.typeCheck(new MyDictionary<>());
            ProgramState prg3 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex3);
            IRepository repo3;
            repo3 = new Repository(prg3, "log3.txt");
            Controller ctrl3 = new Controller(repo3);
            menu.addCommand(new RunExampleCommand("3", ex3.toString(), ctrl3));
        } catch (Exception e) {
            e.printStackTrace();
        }

        IStatement ex4 = new CompStatement(new VarDeclStatement("varf", new StringType()),
                new CompStatement(new AssignStatement("varf", new ValueExpression(new StringValue("test.in"))),
                        new CompStatement(new OpenReadFile(new VarExpression("varf")),
                                new CompStatement(new VarDeclStatement("varc", new IntType()),
                                        new CompStatement(new ReadFile(new VarExpression("varf"), "varc"),
                                                new CompStatement(new PrintStatement(new VarExpression("varc")),
                                                        new CompStatement(new ReadFile(new VarExpression("varf"), "varc"),
                                                                new CompStatement(new PrintStatement(new VarExpression("varc")),
                                                                        new CloseReadFile(new VarExpression("varf"))))))))));

        try {
            ex4.typeCheck(new MyDictionary<>());
            ProgramState prg4 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex4);
            IRepository repo4;
            repo4 = new Repository(prg4, "log4.txt");
            Controller ctrl4 = new Controller(repo4);
            menu.addCommand(new RunExampleCommand("4", ex4.toString(), ctrl4));
        } catch (Exception e) {
            e.printStackTrace();
        }

        IStatement ex5 = new CompStatement(new VarDeclStatement("a", new IntType()),
                new CompStatement(new VarDeclStatement("b", new IntType()),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new IntValue(5))),
                                new CompStatement(new AssignStatement("b", new ValueExpression(new IntValue(7))),
                                        new IfStatement(new RelationExpression(">", new VarExpression("a"),
                                                new VarExpression("b")), new PrintStatement(new VarExpression("a")),
                                                new PrintStatement(new VarExpression("b")))))));

        try {
            ex5.typeCheck(new MyDictionary<>());
            ProgramState prg5 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex5);
            IRepository repo5;
            repo5 = new Repository(prg5, "log5.txt");
            Controller ctrl5 = new Controller(repo5);
            menu.addCommand(new RunExampleCommand("5", ex5.toString(), ctrl5));
        } catch (Exception e) {
            e.printStackTrace();
        }

        IStatement ex6 = new CompStatement(new VarDeclStatement("v", new RefType(new IntType())),
                new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VarDeclStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new model.statement.HeapAllocationStatement("a", new VarExpression("v")),
                                        new CompStatement(new PrintStatement(new VarExpression("v")), new PrintStatement(new VarExpression("a")))))));

        try {
            ex6.typeCheck(new MyDictionary<>());
            ProgramState prg6 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex6);
            IRepository repo6;
            repo6 = new Repository(prg6, "log6.txt");
            Controller controller6 = new Controller(repo6);
            menu.addCommand(new RunExampleCommand("6", ex6.toString(), controller6));
        } catch (Exception e) {
            e.printStackTrace();
        }

        IStatement ex7 = new CompStatement(new VarDeclStatement("v", new RefType(new IntType())),
                new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new BoolValue(true))),
                        new CompStatement(new VarDeclStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new model.statement.HeapAllocationStatement("a", new VarExpression("v")),
                                        new CompStatement(new PrintStatement(new ReadHeapExpression(new VarExpression("v"))),
                                                new PrintStatement(new ArithExpression('+',new ReadHeapExpression(new ReadHeapExpression(new VarExpression("a"))), new ValueExpression(new IntValue(5)))))))));
        try {
            ex7.typeCheck(new MyDictionary<>());
            ProgramState prg7 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex7);
            IRepository repo7;
            repo7 = new Repository(prg7, "log7.txt");
            Controller controller7 = new Controller(repo7);
            menu.addCommand(new RunExampleCommand("7", ex7.toString(), controller7));
        } catch (Exception e) {
            System.out.println("type check failed for ex7");
            e.printStackTrace();
        }

        IStatement ex8 = new CompStatement(new VarDeclStatement("v", new RefType(new IntType())),
                new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement( new PrintStatement(new ReadHeapExpression(new VarExpression("v"))),
                                new CompStatement(new model.statement.WriteHeapStatement("v", new ValueExpression(new IntValue(30))),
                                        new PrintStatement(new ArithExpression('+', new ReadHeapExpression(new VarExpression("v")), new ValueExpression(new IntValue(5))))))));

        try {
            ex8.typeCheck(new MyDictionary<>());
            ProgramState prg8 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex8);
            IRepository repo8;
            repo8 = new Repository(prg8, "log8.txt");
            Controller controller8 = new Controller(repo8);
            menu.addCommand(new RunExampleCommand("8", ex8.toString(), controller8));
        } catch (Exception e) {
            e.printStackTrace();
        }

        IStatement ex9 = new CompStatement(new VarDeclStatement("v", new RefType(new IntType())),
                new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VarDeclStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new model.statement.HeapAllocationStatement("a", new VarExpression("v")),
                                        new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new IntValue(30))),
                                                new PrintStatement(new ReadHeapExpression(new ReadHeapExpression(new VarExpression("a")))))))));

        try {
            ex9.typeCheck(new MyDictionary<>());
            ProgramState prg9 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex9);
            IRepository repo9;
            repo9 = new Repository(prg9, "log9.txt");
            Controller controller9 = new Controller(repo9);
            menu.addCommand(new RunExampleCommand("9", ex9.toString(), controller9));
        } catch (Exception e) {
            e.printStackTrace();
        }

        IStatement ex10 = new CompStatement(new VarDeclStatement("v", new IntType()),
                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(4))),
                        new CompStatement(new model.statement.WhileStatement(new RelationExpression(">", new VarExpression("v"), new ValueExpression(new IntValue(0))),
                                new CompStatement(new PrintStatement(new VarExpression("v")), new AssignStatement("v",new ArithExpression('-', new VarExpression("v"), new ValueExpression(new IntValue(1)))))),
                                new PrintStatement(new VarExpression("v")))));

        try {
            ex10.typeCheck(new MyDictionary<>());
            ProgramState prg10 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex10);
            IRepository repo10;
            repo10 = new Repository(prg10, "log10.txt");
            Controller controller10 = new Controller(repo10);
            menu.addCommand(new RunExampleCommand("10", ex10.toString(), controller10));
        } catch (Exception e) {
            e.printStackTrace();
        };

        IStatement ex11 = new CompStatement(new VarDeclStatement("v", new IntType()),
                new CompStatement(new VarDeclStatement("a", new RefType(new IntType())),
                        new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(10))),
                                new CompStatement(new HeapAllocationStatement("a", new ValueExpression(new IntValue(22))),
                                        new CompStatement(new ForkStatement(new CompStatement(new WriteHeapStatement("a", new ValueExpression(new IntValue(30))),
                                                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(32))),
                                                        new CompStatement(new PrintStatement(new VarExpression("v")), new PrintStatement(new ReadHeapExpression(new VarExpression("a"))))))),
                                                new CompStatement(new PrintStatement(new VarExpression("v")), new PrintStatement(new ReadHeapExpression(new VarExpression("a")))))))));
        try {
            ex11.typeCheck(new MyDictionary<>());
            ProgramState prg11 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex11);
            IRepository repo11;
            repo11 = new Repository(prg11, "log11.txt");
            Controller controller11 = new Controller(repo11);
            menu.addCommand(new RunExampleCommand("11", ex11.toString(), controller11));
        } catch (Exception e) {
            e.printStackTrace();
        }

        IStatement ex12 = new CompStatement(
                new VarDeclStatement("a", new RefType(new IntType())),
                new CompStatement(
                        new VarDeclStatement("counter", new IntType()),
                        new WhileStatement(
                            new RelationExpression("<", new VarExpression("counter"), new ValueExpression(new IntValue(10))),
                            new CompStatement(
                                    new ForkStatement(
                                            new ForkStatement(
                                                    new CompStatement(
                                                        new HeapAllocationStatement("a", new VarExpression("counter")),
                                                            new PrintStatement(new VarExpression("counter"))
                                                  )
                                            )
                                    ),
                                    new AssignStatement("counter", new ArithExpression('+', new VarExpression("counter"), new ValueExpression(new IntValue(1))))

                        )
                )));

        try {
            ex12.typeCheck(new MyDictionary<>());
            ProgramState prg12 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex12);
            IRepository repo12;
            repo12 = new Repository(prg12, "log12.txt");
            Controller controller12 = new Controller(repo12);
            menu.addCommand(new RunExampleCommand("12", ex12.toString(), controller12));
        } catch (Exception e) {
            e.printStackTrace();
        }

        menu.show();
    }
}
