package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.type.Type;
import model.utils.IDictionary;
import model.value.Value;

public class VarDeclStatement implements IStatement {
    String name;
    Type type;

    public VarDeclStatement(String name, Type type) {
        this.name = name;
        this.type = type;
    }

    @Override
    public String toString() {
        return this.type.toString() + " " + this.name;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        // get the symbol table and check if the variable is already declared in it and if not add it to the symbol table
        IDictionary<String, Value> symTable = state.getSymTable();

        if (symTable.containsKey(this.name))
            throw new StmtExeException("Variable " + this.name + " already declared!");

        symTable.put(this.name, this.type.defaultValue());
        state.setSymTable(symTable);
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        typeEnv.put(name, type);
        return typeEnv;
    }
}
