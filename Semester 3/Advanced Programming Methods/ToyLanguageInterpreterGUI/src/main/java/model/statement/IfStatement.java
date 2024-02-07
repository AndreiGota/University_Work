package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.expression.Expression;
import model.type.BoolType;
import model.type.Type;
import model.utils.IDictionary;
import model.utils.IStack;
import model.value.BoolValue;
import model.value.Value;

public class IfStatement implements IStatement {
    Expression exp;
    IStatement thenS;
    IStatement elseS;

    public IfStatement(Expression e, IStatement t, IStatement el) {
        this.exp = e;
        this.thenS = t;
        this.elseS = el;
    }

    @Override
    public String toString() {
        return "(if(" + this.exp.toString() + ") then(" + this.thenS.toString() + ") else(" + this.elseS.toString() + "))";
    }

    @Override
    public ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException {
        // get the stack from the state and the symbol table and set the stack in the state
        Value res = this.exp.eval(state.getSymTable(), state.getHeap());

        if (res.getType().equals(new BoolType())) {
            BoolValue boolRes = (BoolValue) res;
            IStatement toExecute;

            if (boolRes.getVal())
                toExecute = this.thenS;
            else
                toExecute = this.elseS;

            // get the stack from the state
            IStack<IStatement> stk = state.getExeStack();
            stk.push(toExecute);
            state.setExeStack(stk);

            return null;
        } else
            throw new StmtExeException("The condition of if statement has not the type of bool!");
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException {
        Type typeExpr = exp.typeCheck(typeEnv);
        if (typeExpr.equals(new BoolType())) {
            thenS.typeCheck(typeEnv);
            elseS.typeCheck(typeEnv);
            return typeEnv;
        } else
            throw new StmtExeException("The condition of IF does not have the type Bool!");
    }
}
