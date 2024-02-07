package model.utils;

import exceptions.UtilsException;

import java.util.List;

public interface IList<T> {
    void add(T elem);
    String toString();
    T pop() throws UtilsException;
    boolean isEmpty();
    List<T> getList();
}
