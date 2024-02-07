package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IStack;
import model.utils.MyDictionary;
import model.utils.MyStack;
import model.value.Value;

import java.util.Map;

public class ForkStatement implements IStatement {
    private final IStatement statement;

    public ForkStatement(IStatement statement) {
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        IStack<IStatement> newStack = new MyStack<>();
        newStack.push(this.statement);
        IDictionary<String, Value> newSymTable = new MyDictionary<>();

        for (Map.Entry<String, Value> entry : state.getSymTable().getContent().entrySet()) {
            newSymTable.put(entry.getKey(), entry.getValue());
        }

        return new ProgramState(newStack, newSymTable, state.getOutput(), state.getFileTable(), state.getHeap());
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        statement.typeCheck(typeEnv);
        return typeEnv;
    }

    @Override
    public String toString() {
        return String.format("Fork(%s", this.statement.toString());
    }
}
