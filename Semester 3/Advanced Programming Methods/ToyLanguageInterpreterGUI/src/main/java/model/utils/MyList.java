package model.utils;

import exceptions.UtilsException;

import java.util.ArrayList;
import java.util.List;

public class MyList<T> implements IList<T> {
    ArrayList<T> myList;

    public MyList() {
        this.myList = new ArrayList<>();
    }

    @Override
    public void add(T elem) {
        this.myList.add(elem);
    }

    @Override
    public String toString() {
        return this.myList.toString();
    }

    @Override
    public T pop() throws UtilsException {
        if (myList.isEmpty())
            throw new UtilsException("List is empty!");
        return myList.remove(0);
    }

    @Override
    public boolean isEmpty() {
        return myList.isEmpty();
    }

    @Override
    public List<T> getList() {
        return myList;
    }
}
