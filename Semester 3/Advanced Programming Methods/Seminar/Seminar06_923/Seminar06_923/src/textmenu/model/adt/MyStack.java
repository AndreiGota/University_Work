package textmenu.model.adt;

import java.util.Stack;

public class MyStack<T> implements MyIStack<T>{

    private Stack<T> stack;

    public MyStack() {
        this.stack = new Stack<T>();
    }

    @Override
    public void push(T elem) {
        stack.push(elem);
    }

    @Override
    public T pop() {
        return stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return stack.isEmpty();
    }


    @Override
    public String toString() {
        return "MyStack:"+stack.toString();
    }
}

