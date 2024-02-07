package model;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.statement.IStatement;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.utils.IList;
import model.utils.IStack;
import model.value.Value;

import java.io.BufferedReader;
import java.util.List;

public class ProgramState {
    IStack<IStatement> exeStack;
    IDictionary<String, Value> symTable;
    IList<Value> output;
    IDictionary<String, BufferedReader> fileTable;
    IStatement originalProgram;
    private IHeap heap;
    private int id;
    private static int lastId = 0;


    public ProgramState (IStack<IStatement> exeStack, IDictionary<String, Value> symTable, IList<Value> output, IDictionary<String, BufferedReader> fileTable, IHeap heap, IStatement originalProgram) throws UtilsException {
        this.exeStack = exeStack;
        this.symTable = symTable;
        this.output = output;
        this.fileTable = fileTable;
        this.heap = heap;
        this.originalProgram = originalProgram;
        this.exeStack.push(this.originalProgram);
        this.id = setId();
    }

    public ProgramState(IStack<IStatement> exeStack, IDictionary<String, Value> symTable, IList<Value> output, IDictionary<String, BufferedReader> fileTable, IHeap heap) {
        this.exeStack = exeStack;
        this.symTable = symTable;
        this.output = output;
        this.fileTable = fileTable;
        this.heap = heap;
        this.id = setId();
    }

    public int getId() {
        return this.id;
    }
    public synchronized int setId() {
        lastId++;
        return lastId;
    }

    public boolean isNotCompleted() {
        return exeStack.isEmpty();
    }

    public IStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public void setExeStack(IStack<IStatement> exeStack) {
        this.exeStack = exeStack;
    }

    public IDictionary<String, Value> getSymTable() {
        return this.symTable;
    }

    public void setSymTable(IDictionary<String, Value> symTable) {
        this.symTable = symTable;
    }

    public IList<Value> getOutput() {
        return this.output;
    }

    public void setOutput(IList<Value> output) {
        this.output = output;
    }

    public IDictionary<String, BufferedReader> getFileTable() {
        return fileTable;
    }

    public void setFileTable(IDictionary<String, BufferedReader> fileTable) {
        this.fileTable = fileTable;
    }

    public IHeap getHeap() {
        return this.heap;
    }

    public void setHeap(IHeap newHeap) {
        this.heap = newHeap;
    }

    public ProgramState oneStep() throws UtilsException, StmtExeException, ExpEvalException {
        if (!exeStack.isEmpty()) {
            IStatement currentStatement = exeStack.pop();
            return currentStatement.execute(this);
        }

        return null;
    }

    public String exeStackToString() {
        StringBuilder exeStackStringBuilder = new StringBuilder();
        List<IStatement> stack = exeStack.getReversed();

        for (IStatement statement : stack)
            exeStackStringBuilder.append(statement.toString()).append("\n");

        return exeStackStringBuilder.toString();
    }

    public String symTableToString() throws UtilsException {
        StringBuilder symTableStringBuilder = new StringBuilder();

        for (String key : symTable.keySet())
            symTableStringBuilder.append(String.format("%s -> %s\n", key, symTable.lookUp(key).toString()));

        return symTableStringBuilder.toString();
    }

    public String outputListToString() {
        StringBuilder outputListStringBuilder = new StringBuilder();

        for (Value elem : output.getList())
            outputListStringBuilder.append(String.format("%s\n", elem.toString()));

        return outputListStringBuilder.toString();
    }

    public String fileTableToString() {
        StringBuilder fileTableStringBuilder = new StringBuilder();

        for (String key : fileTable.keySet())
            fileTableStringBuilder.append(String.format("%s\n", key));

        return fileTableStringBuilder.toString();
    }

    public String heapToString() throws UtilsException {
        StringBuilder heapStringBuilder = new StringBuilder();
        for (int key: heap.keySet())
            heapStringBuilder.append(String.format("%d -> %s\n", key, heap.get(key)));

        return heapStringBuilder.toString();
    }


    @Override
    public String toString() {
        return "ID: " + id + "\nExecution stack: \n" + exeStack.getReversed() + "\nSymbol table: \n" + symTable.toString() + "\nOutput list: \n" + output.toString() + "\nFile table:\n" + fileTable.toString() + "\nHeap memory:\n" + heap.toString() + "\n";
    }

    public String programStateToString() throws UtilsException {
         return "ID: " + id + "\nExecution stack: \n" + exeStackToString() + "Symbol table: \n" + symTableToString() + "Output list: \n" + outputListToString() + "File table:\n" + fileTableToString() + "Heap memory:\n" + heapToString() + "\n";
    }
}
