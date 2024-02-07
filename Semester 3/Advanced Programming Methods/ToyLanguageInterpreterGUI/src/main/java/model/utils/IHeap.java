package model.utils;

import exceptions.UtilsException;
import model.value.Value;

import java.util.HashMap;
import java.util.Set;

public interface IHeap {
    int getFreeValue();
    HashMap<Integer, Value> getContent();
    void setContent(HashMap<Integer, Value> newMap);
    int add(Value value);
    void update(Integer position, Value value) throws UtilsException;
    Value get(Integer position) throws UtilsException;
    boolean containsKey(Integer position);
    void remove (Integer key) throws UtilsException;
    Set<Integer> keySet();
}
