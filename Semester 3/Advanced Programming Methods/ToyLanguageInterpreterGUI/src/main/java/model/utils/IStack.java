package model.utils;

import exceptions.UtilsException;

import java.util.List;

public interface IStack<T> {
    T pop() throws UtilsException;
    void push(T v) throws UtilsException;
    boolean isEmpty();
    List<T> getReversed();
}
