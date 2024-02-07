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

public class HeapAllocationStatement implements IStatement {
    private final String varName;
    private final Expression expression;

    public HeapAllocationStatement(String varName, Expression expression) {
        this.varName = varName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        IDictionary<String, Value> symTable = state.getSymTable();
        IHeap heap = state.getHeap();

        if (symTable.containsKey(varName)) {
            Value varValue = symTable.lookUp(varName);

            if ((varValue.getType() instanceof RefType)) {
                Value evaluated = expression.eval(symTable, heap);
                Type locationType = ((RefValue) varValue).getLocationType();

                if (locationType.equals(evaluated.getType())) {
                    int newPosition = heap.add(evaluated);
                    symTable.put(varName, new RefValue(newPosition, locationType));
                    state.setSymTable(symTable);
                    state.setHeap(heap);
                } else
                    throw new StmtExeException(String.format("%s not of %s", varName, evaluated.getType()));
            } else {
                throw new StmtExeException(String.format("%s in not of RefType", varName));
            }
        } else {
            throw new StmtExeException(String.format("%s not in symTable", varName));
        }
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        Type typeVar = typeEnv.lookUp(varName);
        Type typeExpr = expression.typeCheck(typeEnv);
        if (typeVar.equals(new RefType(typeExpr)))
            return typeEnv;
        else
            throw new StmtExeException("Heap allocation statement: right hand side and left hand side have different types!");
    }

    @Override
    public String toString() {
        return String.format("New(%s, %s)", this.varName, this.expression);
    }
}
