package model.expression;

import exceptions.ExpEvalException;
import exceptions.UtilsException;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.value.Value;

public class VarExpression implements Expression {
    String id;

    public VarExpression(String id) {
        this.id = id;
    }

    @Override
    public Value eval(IDictionary<String, Value> tbl, IHeap heap) throws ExpEvalException, UtilsException {
        return tbl.lookUp(id);
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeEnv) throws ExpEvalException, UtilsException {
        return typeEnv.lookUp(id);
    }

    @Override
    public String toString() {
        return this.id;
    }
}
