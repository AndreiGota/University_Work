package model.statement;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.type.Type;
import model.utils.IDictionary;

public interface IStatement {
    ProgramState execute(ProgramState state) throws UtilsException, ExpEvalException, StmtExeException;
    IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws StmtExeException, ExpEvalException, UtilsException;
}
