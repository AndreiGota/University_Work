package model.expression;

import exceptions.ExpEvalException;
import exceptions.UtilsException;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.value.Value;

public class ValueExpression implements Expression {
    Value e;

    public ValueExpression(Value e) {
        this.e = e;
    }

    @Override
    public Value eval(IDictionary<String, Value> tbl, IHeap heap) throws ExpEvalException {
        return this.e;
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeEnv) throws ExpEvalException, UtilsException {
        return e.getType();
    }

    @Override
    public String toString() {
        return e.toString();
    }
}
