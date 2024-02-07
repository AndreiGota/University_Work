package model.utils;

import exceptions.UtilsException;
import model.value.Value;

import java.util.HashMap;
import java.util.Set;

public class MyHeap implements IHeap {
    HashMap<Integer, Value> heap;
    Integer freeLocationValue; //the first free location in the heap

    public int newValue() {
        //returns the first free location in the heap
        int idx = 1;
        while (heap.containsKey(idx)) {
            idx += 1;
        }
        return idx;
    }

    public MyHeap() {
        this.heap = new HashMap<>();
        this.freeLocationValue = 1; //the first free location in the heap
    }

    @Override
    public int getFreeValue() {
        //returns the first free location in the heap;
        return this.freeLocationValue;
    }

    @Override
    public HashMap<Integer, Value> getContent() {
        return this.heap;
    }

    @Override
    public void setContent(HashMap<Integer, Value> newMap) {
        this.heap = newMap;
    }

    @Override
    public int add(Value value) {
        this.freeLocationValue = newValue();
        this.heap.put(this.freeLocationValue ,value);
        //Integer toReturn = this.freeLocationValue;
//        this.freeLocationValue = newValue();
        return this.freeLocationValue;
    }

    @Override
    public void update(Integer position, Value value) throws UtilsException {
        if (!this.heap.containsKey(position))
            throw new UtilsException(String.format("%d is not present in the heap", position));
        this.heap.put(position, value);
    }

    @Override
    public Value get(Integer position) throws UtilsException {
        //returns the value at the given position
        if (!this.heap.containsKey(position))
            throw new UtilsException(String.format("%d is not present in the heap", position));
        return this.heap.get(position);
    }

    @Override
    public boolean containsKey(Integer position) {
        return this.heap.containsKey(position);
    }

    @Override
    public void remove(Integer key) throws UtilsException {
        if (!this.heap.containsKey(key))
            throw new UtilsException(String.format("%d is not present in the heap", key));
        this.heap.remove(key);
    }

    @Override
    public Set<Integer> keySet() {
        return this.heap.keySet();
    }

    @Override
    public String toString() {
        return this.heap.toString();
    }
}
