package model.statement.file_statements;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.statement.IStatement;
import model.expression.Expression;
import model.type.StringType;
import model.type.Type;
import model.utils.IDictionary;
import model.value.StringValue;
import model.value.Value;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class OpenReadFile implements IStatement {
    private final Expression expression;

    public OpenReadFile(Expression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws StmtExeException, UtilsException, ExpEvalException {
        //function to open a file and put it in the file table
        Value val = this.expression.eval(state.getSymTable(), state.getHeap());

        if (val.getType().equals(new StringType())) { //check if the expression evaluates to a string
            StringValue fileName = (StringValue) val;
            IDictionary<String, BufferedReader> fileTable = state.getFileTable();

            if (!fileTable.containsKey(fileName.getVal())) { //check if the file is not already open
                BufferedReader br;

                try {
                    br = new BufferedReader(new FileReader(fileName.getVal())); //open the file
                } catch (FileNotFoundException e) {
                    throw new StmtExeException(String.format("%s could not be opened!", fileName.getVal()));
                }

                fileTable.put(fileName.getVal(), br); //put the file in the file table
                state.setFileTable(fileTable); //update the file table
            } else
                throw new StmtExeException(String.format("%s is already opened!", fileName.getVal()));
        } else
            throw new StmtExeException(String.format("%s does not evaluate to StringType", expression.toString()));
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        if (expression.typeCheck(typeEnv).equals(new StringType()))
            return typeEnv;
        else
            throw new StmtExeException("OpenReadFile requires string expression!");

    }

    @Override
    public String toString() {
        return String.format("OpenReadFile(%s)", expression.toString());
        //example: OpenReadFile(var_f)
    }
}
