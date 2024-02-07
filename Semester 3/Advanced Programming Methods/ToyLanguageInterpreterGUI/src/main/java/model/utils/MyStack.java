package model.utils;

import exceptions.UtilsException;

import java.util.*;

public class MyStack<T> implements IStack<T> {
    Stack<T> myStack;

    public MyStack() {
        this.myStack = new Stack<>();
    }

    @Override
    public T pop() throws UtilsException {
        if (this.myStack.isEmpty())
            throw new UtilsException("Stack is empty!");
        return this.myStack.pop();
    }

    @Override
    public void push(T v) throws UtilsException {
        this.myStack.push(v);
    }

    @Override
    public boolean isEmpty() {
        return this.myStack.isEmpty();
    }

    @Override
    public List<T> getReversed() {
        List<T> reversed = Arrays.asList((T[]) this.myStack.toArray());
        Collections.reverse(reversed);
        return this.myStack;
    }

    @Override
    public String toString() {
        return this.myStack.toString();
    }
}
