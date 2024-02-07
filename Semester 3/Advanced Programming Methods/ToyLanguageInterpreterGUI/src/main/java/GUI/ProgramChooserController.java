package GUI;

import controller.Controller;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
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
import java.util.ArrayList;
import java.util.List;

public class ProgramChooserController {
    private ProgramExecutorController programExecutorController;

    public void setProgramExecutorController(ProgramExecutorController programExecutorController) {
        this.programExecutorController = programExecutorController;
    }
    @FXML
    private ListView<IStatement> programsListView;

    @FXML
    private Button displayButton;

    @FXML
    public void initialize() {
        programsListView.setItems(getAllStatements());
        programsListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
    }

    @FXML
    private void displayProgram(ActionEvent actionEvent) {
        IStatement selectedStatement = programsListView.getSelectionModel().getSelectedItem();
        if (selectedStatement == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error encountered!");
            alert.setContentText("No Statements selected!");
            alert.showAndWait();
        } else {
            int id = programsListView.getSelectionModel().getSelectedIndex();
            try {
                selectedStatement.typeCheck(new MyDictionary<>());
                ProgramState programState = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), selectedStatement);
                IRepository repository = new Repository(programState, "log" + (id + 1) + ".txt");
                Controller controller = new Controller(repository);
                programExecutorController.setController(controller);
            } catch (Exception exception) {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error encountered!");
                alert.setContentText(exception.getMessage());
                alert.showAndWait();
            }
        }
    }

    @FXML
    private ObservableList<IStatement> getAllStatements() {
        List<IStatement> allStatements = new ArrayList<>();

        IStatement ex1 = new CompStatement(new VarDeclStatement("v", new IntType()),
                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VarExpression("v"))));

        allStatements.add(ex1);

        IStatement ex2 = new CompStatement(new VarDeclStatement("a", new BoolType()),
                new CompStatement(new VarDeclStatement("b", new IntType()),
                        new CompStatement(new AssignStatement("a", new ArithExpression('+', new ValueExpression(new IntValue(2)), new
                                ArithExpression('*', new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStatement(new AssignStatement("b", new ArithExpression('+', new VarExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStatement(new VarExpression("b"))))));

        allStatements.add(ex2);

        IStatement ex3 = new CompStatement(new VarDeclStatement("a", new BoolType()),
                new CompStatement(new VarDeclStatement("v", new IntType()),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompStatement(new IfStatement(new VarExpression("a"),
                                        new AssignStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VarExpression("v"))))));

        allStatements.add(ex3);

        IStatement ex4 = new CompStatement(new VarDeclStatement("varf", new StringType()),
                new CompStatement(new AssignStatement("varf", new ValueExpression(new StringValue("test.in"))),
                        new CompStatement(new OpenReadFile(new VarExpression("varf")),
                                new CompStatement(new VarDeclStatement("varc", new IntType()),
                                        new CompStatement(new ReadFile(new VarExpression("varf"), "varc"),
                                                new CompStatement(new PrintStatement(new VarExpression("varc")),
                                                        new CompStatement(new ReadFile(new VarExpression("varf"), "varc"),
                                                                new CompStatement(new PrintStatement(new VarExpression("varc")),
                                                                        new CloseReadFile(new VarExpression("varf"))))))))));

        allStatements.add(ex4);

        IStatement ex5 = new CompStatement(new VarDeclStatement("a", new IntType()),
                new CompStatement(new VarDeclStatement("b", new IntType()),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new IntValue(5))),
                                new CompStatement(new AssignStatement("b", new ValueExpression(new IntValue(7))),
                                        new IfStatement(new RelationExpression(">", new VarExpression("a"),
                                                new VarExpression("b")), new PrintStatement(new VarExpression("a")),
                                                new PrintStatement(new VarExpression("b")))))));

        allStatements.add(ex5);

        IStatement ex6 = new CompStatement(new VarDeclStatement("v", new RefType(new IntType())),
                new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VarDeclStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new model.statement.HeapAllocationStatement("a", new VarExpression("v")),
                                        new CompStatement(new PrintStatement(new VarExpression("v")), new PrintStatement(new VarExpression("a")))))));

        allStatements.add(ex6);

        IStatement ex7 = new CompStatement(new VarDeclStatement("v", new RefType(new IntType())),
                new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new BoolValue(true))),
                        new CompStatement(new VarDeclStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new model.statement.HeapAllocationStatement("a", new VarExpression("v")),
                                        new CompStatement(new PrintStatement(new ReadHeapExpression(new VarExpression("v"))),
                                                new PrintStatement(new ArithExpression('+',new ReadHeapExpression(new ReadHeapExpression(new VarExpression("a"))), new ValueExpression(new IntValue(5)))))))));

        allStatements.add(ex7);

        IStatement ex8 = new CompStatement(new VarDeclStatement("v", new RefType(new IntType())),
                new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement( new PrintStatement(new ReadHeapExpression(new VarExpression("v"))),
                                new CompStatement(new model.statement.WriteHeapStatement("v", new ValueExpression(new IntValue(30))),
                                        new PrintStatement(new ArithExpression('+', new ReadHeapExpression(new VarExpression("v")), new ValueExpression(new IntValue(5))))))));

        allStatements.add(ex8);

        IStatement ex9 = new CompStatement(new VarDeclStatement("v", new RefType(new IntType())),
                new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VarDeclStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new model.statement.HeapAllocationStatement("a", new VarExpression("v")),
                                        new CompStatement(new model.statement.HeapAllocationStatement("v", new ValueExpression(new IntValue(30))),
                                                new PrintStatement(new ReadHeapExpression(new ReadHeapExpression(new VarExpression("a")))))))));

        allStatements.add(ex9);

        IStatement ex10 = new CompStatement(new VarDeclStatement("v", new IntType()),
                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(4))),
                        new CompStatement(new model.statement.WhileStatement(new RelationExpression(">", new VarExpression("v"), new ValueExpression(new IntValue(0))),
                                new CompStatement(new PrintStatement(new VarExpression("v")), new AssignStatement("v",new ArithExpression('-', new VarExpression("v"), new ValueExpression(new IntValue(1)))))),
                                new PrintStatement(new VarExpression("v")))));

        allStatements.add(ex10);

        IStatement ex11 = new CompStatement(new VarDeclStatement("v", new IntType()),
                new CompStatement(new VarDeclStatement("a", new RefType(new IntType())),
                        new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(10))),
                                new CompStatement(new HeapAllocationStatement("a", new ValueExpression(new IntValue(22))),
                                        new CompStatement(new ForkStatement(new CompStatement(new WriteHeapStatement("a", new ValueExpression(new IntValue(30))),
                                                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(32))),
                                                        new CompStatement(new PrintStatement(new VarExpression("v")), new PrintStatement(new ReadHeapExpression(new VarExpression("a"))))))),
                                                new CompStatement(new PrintStatement(new VarExpression("v")), new PrintStatement(new ReadHeapExpression(new VarExpression("a")))))))));

        allStatements.add(ex11);

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
        
        allStatements.add(ex12);

        return FXCollections.observableArrayList(allStatements);
    }
}
