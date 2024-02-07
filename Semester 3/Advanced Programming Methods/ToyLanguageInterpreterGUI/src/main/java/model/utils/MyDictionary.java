package model.utils;

import exceptions.UtilsException;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MyDictionary<K, V> implements IDictionary<K,V> {
   HashMap<K, V> myDict;

   public MyDictionary() {
       this.myDict = new HashMap<>();
   }

    @Override
    public void put(K key, V value) {
        this.myDict.put(key, value);
    }

    @Override
    public boolean containsKey(K key) {
        return this.myDict.containsKey(key);
    }

    @Override
    public V lookUp(K key) throws UtilsException {
       //get the value of the key
        if (!containsKey(key))
            throw new UtilsException(key + " doesn't exists!");
        return this.myDict.get(key);
    }

    @Override
    public void update(K key, V value) throws UtilsException {
       //update value of the key
        if (!containsKey(key))
            throw new UtilsException(key + " doesn't exists!");
        this.myDict.put(key, value);
    }

    @Override
    public Collection<V> values() {
        return this.myDict.values();
    }

    @Override
    public void remove(K key) throws UtilsException {
        if (!containsKey(key))
            throw new UtilsException(key + " is not defined!");

        this.myDict.remove(key);
    }

    @Override
    public Set<K> keySet() {
        return myDict.keySet();
    }

    @Override
    public String toString() {
        return this.myDict.toString();
    }

    @Override
    public Map<K, V> getContent() {
       return this.myDict;
    }
}
