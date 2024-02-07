package model.expression;

import exceptions.ExpEvalException;
import exceptions.UtilsException;
import model.type.IntType;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.value.IntValue;
import model.value.Value;

public class ArithExpression implements Expression {
    Expression e1;
    Expression e2;
    char op;

    public ArithExpression(char op, Expression e1, Expression e2) {
        this.e1 = e1;
        this.e2 = e2;
        this.op = op;
    }

    @Override
    public Value eval(IDictionary<String, Value> tbl, IHeap heap) throws ExpEvalException, UtilsException {
        Value v1, v2;
        v1 = this.e1.eval(tbl, heap);
        if (v1.getType().equals(new IntType())) {
            v2 = this.e2.eval(tbl, heap);

            if (v2.getType().equals(new IntType())) {
                IntValue i1 = (IntValue) v1;
                IntValue i2 = (IntValue) v2;
                int n1, n2;
                n1 = i1.getVal();
                n2 = i2.getVal();

                if (this.op == '+')
                    return new IntValue(n1 + n2);
                else if (this.op == '-')
                    return new IntValue(n1 - n2);
                else if (this.op == '*')
                    return new IntValue(n1 * n2);
                else if (this.op == '/') {
                    if (n2 == 0) throw new ExpEvalException("Division by zero!");
                    else return new IntValue(n1 / n2);
                }
            } else
                throw new ExpEvalException("Second operand is not integer!");
        } else
            throw new ExpEvalException("First operand is not integer!");
        return null;
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeEnv) throws ExpEvalException, UtilsException {
        Type type1, type2;
        type1 = e1.typeCheck(typeEnv);
        type2 = e2.typeCheck(typeEnv);
        if (type1.equals(new IntType())) {
            if (type2.equals(new IntType())) {
                return new IntType();
            } else
                throw new ExpEvalException("Second operand is not an integer!");
        } else
            throw new ExpEvalException("First operand is not an integer!");
    }

    @Override
    public String toString() {
        return this.e1.toString() + " " + this.op + " " + this.e2.toString();
    }
}
