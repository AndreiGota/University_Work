package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IStack;

public class CompStatement implements IStatement {
    IStatement first;
    IStatement second;
    public CompStatement(IStatement first, IStatement second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public String toString() {
        return "(" + first.toString() + "; " + second.toString() + ")";
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        // create a new stack for the new statement and set the new stack in the state
        IStack<IStatement> stk = state.getExeStack();
        stk.push(second);
        stk.push(first);
        state.setExeStack(stk);
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        return second.typeCheck(first.typeCheck(typeEnv));
    }
}
