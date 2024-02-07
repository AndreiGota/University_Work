package textmenu.view;

        import textmenu.controller.Controller;
        import textmenu.model.PrgState;
        import textmenu.model.adt.*;
        import textmenu.model.stmt.IStmt;
        import textmenu.model.value.Value;
        import textmenu.repository.IRepository;
        import textmenu.repository.Repository;

public class RunExample1 extends Command {
    private IStmt originalProgram;

    public RunExample1(String key, String desc, IStmt originalProgram){
        super(key, desc);

        this.originalProgram = originalProgram;
    }
    @Override
    public void execute() {
        try{
            MyIStack<IStmt> stk1= new MyStack<>();
            MyIDictionary<String, Value> symtbl1 = new MyDictionary<>();
            MyIList<Value> out1 = new MyList<>();

            PrgState prgState1 = new PrgState(stk1, symtbl1, out1, originalProgram);
            IRepository repo1 = new Repository(prgState1);

            Controller ctrl=new Controller(repo1);
            ctrl.allStep(); }
        catch (MyException e) {
            System.out.println(e.getMessage());
        } //here you must treat the exceptions that can not be solved in the controller
    }
}