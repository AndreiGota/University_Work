package textmenu.model.stmt;

import textmenu.model.PrgState;
import textmenu.model.adt.MyException;
import textmenu.model.stmt.IStmt;
import textmenu.model.type.IntType;
import textmenu.model.type.Type;

public class VarDeclStmt implements IStmt {
    String name;
    Type type;

    public VarDeclStmt(String v, Type type) {
        name= v;
        this.type=type;
    }

    @Override
    public PrgState execute(PrgState prg) throws MyException {
        prg.getMySymTable().put(name, type.defaultValue());
        return prg;
    }

    @Override
    public String toString() {
        return type+ " " + name;
    }
}