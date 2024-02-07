package textmenu.controller;

import textmenu.model.PrgState;
import textmenu.model.adt.MyException;
import textmenu.model.adt.MyIStack;
import textmenu.model.stmt.IStmt;
import textmenu.repository.IRepository;

public class Controller {
    IRepository repo;

    public Controller(IRepository repo) {
        this.repo = repo;
    }

    PrgState oneStep(PrgState state) throws MyException {
        MyIStack<IStmt> stk=state.getMyStack();
        if(stk.isEmpty()) throw new MyException("prgstate stack is empty");
        IStmt crtStmt = stk.pop();
        return crtStmt.execute(state);
    }

    public void allStep() throws MyException {
        PrgState prg = repo.getCrtPrg(); // repo is the controller field of type MyRepoInterface
        System.out.println(prg);
        while (!prg.getMyStack().isEmpty()){
            oneStep(prg);
            System.out.println(prg);
        }
    }
}
