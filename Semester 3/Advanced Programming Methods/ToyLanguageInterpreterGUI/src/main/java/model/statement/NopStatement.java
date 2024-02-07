package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.type.Type;
import model.utils.IDictionary;

public class NopStatement implements IStatement {
    @Override
    public String toString() {
        return "NopStatement";
    }

    @Override
    public ProgramState execute(ProgramState state) {
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        return typeEnv;
    }
}
