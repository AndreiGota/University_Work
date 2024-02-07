package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.expression.Expression;
import model.type.Type;
import model.utils.IDictionary;
import model.value.Value;

public class AssignStatement implements IStatement {
    private final String id;
    private final Expression exp;

    public AssignStatement(String id, Expression exp) {
        this.id = id;
        this.exp = exp;
    }

    @Override
    public String toString() {
        return this.id + " = " + this.exp.toString();
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        // get the symbol table from the program state and set the symbol table in the program state
        IDictionary<String, Value> symTbl = state.getSymTable();

        if (symTbl.containsKey(id)) {
            Value val = exp.eval(symTbl, state.getHeap());
            Type typeId = (symTbl.lookUp(id)).getType();

            if (val.getType().equals(typeId))
                symTbl.update(id, val);
            else
                throw new StmtExeException("Declared type of variable " + id + " and type of the assigned expression do not match.");
        } else
            throw new StmtExeException("The used variable " + id + " was not declared before.");
        state.setSymTable(symTbl);
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        Type typeVar = typeEnv.lookUp(id);
        Type typeExpr = exp.typeCheck(typeEnv);
        if (typeVar.equals(typeExpr))
            return typeEnv;
        else
            throw new StmtExeException("Assigment: right hand side and left hand side have different types!");
    }
}
