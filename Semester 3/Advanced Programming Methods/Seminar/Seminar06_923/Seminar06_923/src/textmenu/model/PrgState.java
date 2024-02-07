package textmenu.model;

import textmenu.model.adt.MyIDictionary;
import textmenu.model.adt.MyIStack;
import textmenu.model.adt.MyIList;
import textmenu.model.stmt.IStmt;
import textmenu.model.value.Value;

public class PrgState {

    MyIDictionary<String, Value> mySymTable;
    MyIStack<IStmt> myStack;
    MyIList<Value> myOut;
    IStmt originalProgram;

    public PrgState(MyIStack<IStmt> myStack,MyIDictionary<String, Value> mySymTable,  MyIList<Value> myOut, IStmt original) {
        this.mySymTable = mySymTable;
        this.myStack = myStack;
        this.myOut = myOut;
        this.originalProgram = original;
        this.myStack.push(original);
    }

    public MyIDictionary<String, Value> getMySymTable() {
        return mySymTable;
    }

    public void setMySymTable(MyIDictionary<String, Value> mySymTable) {
        this.mySymTable = mySymTable;
    }

    public MyIStack<IStmt> getMyStack() {
        return myStack;
    }

    public void setMyStack(MyIStack<IStmt> myStack) {
        this.myStack = myStack;
    }

    public MyIList<Value> getMyOut() {
        return myOut;
    }

    public void setMyOut(MyIList<Value> myOut) {
        this.myOut = myOut;
    }

    public IStmt getOriginalProgram() {
        return originalProgram;
    }

    public void setOriginalProgram(IStmt originalProgram) {
        this.originalProgram = originalProgram;
    }

    @Override
    public String toString() {
        return "PrgState:" + "\n"+
                mySymTable + "\n"+
                myStack +  "\n"+
                myOut +  "\n";
    }
}