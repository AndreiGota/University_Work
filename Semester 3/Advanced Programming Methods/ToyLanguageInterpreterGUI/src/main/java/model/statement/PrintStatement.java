package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.expression.Expression;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IList;
import model.value.Value;

public class PrintStatement implements IStatement {
    Expression exp; // expression to be printed

    public PrintStatement(Expression exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        return "Print(" + exp.toString() + ")";
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        // evaluate the expression (add it to the output list and update the output list)
        IList<Value> output = state.getOutput();
        output.add(exp.eval(state.getSymTable(), state.getHeap()));
        state.setOutput(output);
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        exp.typeCheck(typeEnv);
        return typeEnv;
    }
}
