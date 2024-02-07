package model.expression;

import exceptions.ExpEvalException;
import exceptions.UtilsException;
import model.type.BoolType;
import model.type.IntType;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.value.BoolValue;
import model.value.IntValue;
import model.value.Value;

import java.util.Objects;

public class RelationExpression implements Expression {
    Expression exp1;
    Expression exp2;
    String op;

    public RelationExpression(String op, Expression exp1, Expression exp2) {
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.op = op;
    }

    @Override
    public Value eval(IDictionary<String, Value> tbl, IHeap heap) throws ExpEvalException, UtilsException {
        Value v1, v2;
        v1 = this.exp1.eval(tbl, heap);

        if (v1.getType().equals(new IntType())) {
            v2 = this.exp2.eval(tbl, heap);

            if (v2.getType().equals(new IntType())) {
                IntValue i1 = (IntValue) v1;
                IntValue i2 = (IntValue) v2;
                int n1, n2;
                n1 = i1.getVal();
                n2 = i2.getVal();

                if (Objects.equals(this.op, "<"))
                    return new BoolValue(n1 < n2);
                else if (Objects.equals(this.op, "<="))
                    return new BoolValue(n1 <= n2);
                else if (Objects.equals(this.op, ">"))
                    return new BoolValue(n1 > n2);
                else if (Objects.equals(this.op, ">="))
                    return new BoolValue(n1 >= 2);
                else if (Objects.equals(this.op, "=="))
                    return new BoolValue(n1 == n2);
                else if (Objects.equals(this.op, "!="))
                    return new BoolValue(n1 != n2);
                else
                    throw new ExpEvalException("operand is not well defined!");
            } else
                throw new ExpEvalException("Second operand is not integer!");
        } else
            throw new ExpEvalException("First operand is not integer!");
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeEnv) throws ExpEvalException, UtilsException {
        Type type1, type2;
        type1 = exp1.typeCheck(typeEnv);
        type2 = exp2.typeCheck(typeEnv);
        if (type1.equals(new IntType())) {
            if (type2.equals(new IntType())) {
                return new BoolType();
            } else
                throw new ExpEvalException("Second operand is not an integer!");
        } else
            throw new ExpEvalException("First operand is not an integer!");
    }

    @Override
    public String toString() {
        return this.exp1.toString() + " " + this.op + " " + this.exp2.toString();
    }
}
