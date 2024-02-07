package model.statement.file_statements;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.expression.Expression;
import model.statement.IStatement;
import model.type.IntType;
import model.type.StringType;
import model.type.Type;
import model.utils.IDictionary;
import model.value.IntValue;
import model.value.StringValue;
import model.value.Value;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements IStatement {
    private final Expression expression;
    private final String varName;

    public ReadFile(Expression expression, String varName) {
        this.expression = expression;
        this.varName = varName;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        //function that reads a file and puts the value in the symbol table
        IDictionary<String, Value> symTable = state.getSymTable();
        IDictionary<String, BufferedReader> fileTable = state.getFileTable();

        if (symTable.containsKey(varName)) { //check if the variable is defined
            Value val = symTable.lookUp(varName);

            if (val.getType().equals(new IntType())) { //check if the variable is an integer
                val = expression.eval(symTable, state.getHeap());

                if (val.getType().equals(new StringType())) { //check if the expression is a string
                    StringValue castValue = (StringValue) val;

                    if (fileTable.containsKey(castValue.getVal())) { //check if the file is open
                        BufferedReader br = fileTable.lookUp(castValue.getVal());

                        try {
                            String line = br.readLine(); //read the next line from the file
                            if (line == null) //if the line is null, put 0 in the variable
                                line = "0";
                            symTable.put(varName, new IntValue(Integer.parseInt(line))); //put the value in the symbol table
                        } catch (IOException e) {
                            throw new StmtExeException(String.format("Could not read from file %s", castValue));
                        }
                    } else
                        throw new StmtExeException(String.format("The file table does not contain %s", castValue));
                } else
                    throw new StmtExeException(String.format("%s does not evaluate to StringType", val));
            } else
                throw new StmtExeException(String.format("%s is not of type IntType", val));
        } else
            throw new StmtExeException(String.format("%s is not present in the symTable.", varName));
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        if (expression.typeCheck(typeEnv).equals(new StringType()))
            if (typeEnv.lookUp(varName).equals(new IntType()))
                return typeEnv;
            else
                throw new StmtExeException("ReadFile requires an int as its variable parameter!");
        else
            throw new StmtExeException("ReadFile requires string as an expression parameter!");
    }

    @Override
    public String toString() {
        return String.format("ReadFile(%s, %s)", expression.toString(), varName);
        //example: ReadFile(var_f, var_c)
    }
}
