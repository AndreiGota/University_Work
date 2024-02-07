package model.expression;

import exceptions.ExpEvalException;
import exceptions.UtilsException;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.value.Value;

public interface Expression {
    Value eval(IDictionary<String, Value> tbl, IHeap heap) throws ExpEvalException, UtilsException;
    Type typeCheck(IDictionary<String, Type> typeEnv) throws ExpEvalException, UtilsException;

}
