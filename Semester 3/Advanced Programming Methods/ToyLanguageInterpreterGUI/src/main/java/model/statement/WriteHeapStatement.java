package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.expression.Expression;
import model.type.RefType;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.value.RefValue;
import model.value.Value;

public class WriteHeapStatement implements IStatement {
    private final String varName;
    private final Expression expression;

    public WriteHeapStatement(String varName, Expression expression) {
        this.varName = varName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        IDictionary<String, Value> symTable = state.getSymTable();
        IHeap heap = state.getHeap();

        if (symTable.containsKey(varName)) {
            Value value = symTable.lookUp(varName);

            if (value.getType() instanceof RefType) {
                RefValue refValue = (RefValue) value;

                if (heap.containsKey(refValue.getAddress())) {
                    Value evaluated = expression.eval(symTable, heap);

                    if (evaluated.getType().equals(refValue.getLocationType())) {
                        heap.update(refValue.getAddress(), evaluated);
                        state.setHeap(heap);
                    } else
                        throw new StmtExeException(String.format("%s not of %s", evaluated, refValue.getLocationType()));
                } else
                    throw new StmtExeException(String.format("The RefValue %s is not defined in the heap", value));
            } else
                throw new StmtExeException(String.format("%s not of RefType", value));
        } else
            throw new StmtExeException(String.format("%s not present in the symTable", varName));
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        if (typeEnv.lookUp(varName).equals(new RefType(expression.typeCheck(typeEnv))))
            return typeEnv;
        else
            throw new StmtExeException("WriteHeap: right hand side and left hand side have different types!");
    }

    @Override
    public String toString() {
        return String.format("WriteHeap(%s, %s)", this.varName, this.expression);
    }
}
