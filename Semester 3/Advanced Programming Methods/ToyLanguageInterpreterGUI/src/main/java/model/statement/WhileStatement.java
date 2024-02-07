package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.expression.Expression;
import model.type.BoolType;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IStack;
import model.value.BoolValue;
import model.value.Value;

public class WhileStatement implements IStatement {
    private final Expression expression;
    private final IStatement statement;

    public WhileStatement(Expression expression, IStatement statement) {
        this.expression = expression;
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        Value val = expression.eval(state.getSymTable(), state.getHeap());
        IStack<IStatement> stk = state.getExeStack();

        if (!val.getType().equals(new BoolType()))
            throw new StmtExeException(String.format("%s is not of BoolType", val));

        if (!(val instanceof BoolValue))
            throw new StmtExeException(String.format("%s is not a BoolValue", val));

        BoolValue boolValue = (BoolValue) val;

        if (boolValue.getVal())
            stk.push(new CompStatement(statement, this));

        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        Type typeExpr = expression.typeCheck(typeEnv);
        if (typeExpr.equals(new BoolType())) {
            statement.typeCheck(typeEnv);
            return typeEnv;
        } else
            throw new StmtExeException("The condition of WHILE does not have the type Bool!");
    }

    @Override
    public String toString() {
        return String.format("while(%s){%s}", this.expression, this.statement);
    }
}
