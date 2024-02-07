package textmenu.model.stmt;

import textmenu.model.PrgState;
import textmenu.model.adt.MyException;

public interface IStmt {

    PrgState execute(PrgState prg) throws MyException;
}

