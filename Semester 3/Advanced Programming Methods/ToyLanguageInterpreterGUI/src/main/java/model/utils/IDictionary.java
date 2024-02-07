package model.utils;

import exceptions.UtilsException;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

public interface IDictionary<K, V> {
    void put (K key, V value);
    boolean containsKey(K key);
    V lookUp(K key) throws UtilsException;
    void update(K key, V value) throws UtilsException;
    Collection<V> values();
    void remove(K key) throws UtilsException;
    Set<K> keySet();
    Map<K, V> getContent();
}
