package model.expression;

import exceptions.ExpEvalException;
import exceptions.UtilsException;
import model.type.BoolType;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.value.BoolValue;
import model.value.Value;

import java.util.Objects;

public class LogicExpression implements Expression {
    Expression e1;
    Expression e2;
    String op;

    public LogicExpression(Expression e1, Expression e2, String op) {
        this.e1 = e1;
        this.e2 = e2;
        this.op = op;
    }
    @Override
    public Value eval(IDictionary<String, Value> tbl, IHeap heap) throws ExpEvalException, UtilsException {
        Value v1, v2;
        v1 = this.e1.eval(tbl, heap);

        if (v1.getType().equals(new BoolType())) {
            v2 = this.e2.eval(tbl, heap);

            if (v2.getType().equals(new BoolType())) {
                BoolValue i1 = (BoolValue) v1;
                BoolValue i2 = (BoolValue) v2;
                boolean n1, n2;
                n1 = i1.getVal();
                n2 = i2.getVal();

                if (Objects.equals(this.op, "and"))
                    return new BoolValue(n1 && n2);
                else if (Objects.equals(this.op, "or"))
                    return new BoolValue(n1 || n2);
            } else
                throw new ExpEvalException("Second operand is not bool!");
        } else
            throw new ExpEvalException("First operand is not bool!");
        return null;
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeEnv) throws ExpEvalException, UtilsException {
        Type type1, type2;
        type1 = e1.typeCheck(typeEnv);
        type2 = e2.typeCheck(typeEnv);
        if (type1.equals(new BoolType())) {
            if (type2.equals(new BoolType())) {
                return new BoolType();
            } else
                throw new ExpEvalException("Second operand is not a boolean!");
        } else
            throw new ExpEvalException("First operand is not a boolean!");
    }

    @Override
    public String toString() {
        return e1.toString() + " " + this.op + " " + this.e2.toString();
    }
}
