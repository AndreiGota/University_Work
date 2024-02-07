package model.expression;

import exceptions.ExpEvalException;
import exceptions.UtilsException;
import model.type.RefType;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.value.RefValue;
import model.value.Value;

public class ReadHeapExpression implements Expression {
    private final Expression expression;

    public ReadHeapExpression(Expression exp) {
        this.expression = exp;
    }

    @Override
    public Value eval(IDictionary<String, Value> tbl, IHeap heap) throws ExpEvalException, UtilsException {
        Value value = this.expression.eval(tbl, heap);

        if (value instanceof RefValue) {
            RefValue refValue = (RefValue) value;

            if (heap.containsKey(refValue.getAddress()))
                return heap.get(refValue.getAddress());
            else
                throw new ExpEvalException("The address is not defined on the heap!");
        } else
            throw new ExpEvalException(String.format("%s not of RefType", value));
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeEnv) throws ExpEvalException, UtilsException {
        Type type = expression.typeCheck(typeEnv);
        if (type instanceof RefType) {
            RefType refType = (RefType) type;
            return refType.getInner();
        } else
            throw new ExpEvalException("The rH argument is not a RefType!");
    }

    @Override
    public String toString() {
        return String.format("ReadHeap(%s)", this.expression);
    }
}
