package model.statement.file_statements;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.expression.Expression;
import model.statement.IStatement;
import model.type.StringType;
import model.type.Type;
import model.utils.IDictionary;
import model.value.StringValue;
import model.value.Value;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseReadFile implements IStatement {
    private final Expression expression;

    public CloseReadFile(Expression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        // function that closes the file with the given name
        Value val = expression.eval(state.getSymTable(), state.getHeap());

        if (!val.getType().equals(new StringType())) // if the expression is not a string
            throw new StmtExeException(String.format("%s does not evaluate to StringValue", expression));

        StringValue fileName = (StringValue) val; // cast the value to StringValue
        IDictionary<String, BufferedReader> fileTable = state.getFileTable(); // get the file table

        if (!fileTable.containsKey(fileName.getVal())) // if the file is not in the file table
            throw new StmtExeException(String.format("%s is not present in the FileTable", val));

        BufferedReader br = fileTable.lookUp(fileName.getVal()); // get the BufferedReader associated with the file name

        try {
            br.close();
        } catch (IOException e) {
            throw new StmtExeException(String.format("Unexpected error in closing %s", val));
        }

        fileTable.remove(fileName.getVal()); // remove the file from the file table
        state.setFileTable(fileTable); // update the file table

        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        if (expression.typeCheck(typeEnv).equals(new StringType()))
            return typeEnv;
        else
            throw new StmtExeException("CloseReadFile requires string expression!");
    }

    @Override
    public String toString() {
        return String.format("CloseReadFile(%s)", expression.toString());
        // example: CloseReadFile(var_f)
    }
}
