package textmenu.model.adt;

import java.util.HashMap;
import java.util.Map;

public class MyDictionary<K, V> implements  MyIDictionary<K, V>{

    private Map<K, V> map;

    public MyDictionary() {
        this.map = new HashMap<K, V>();
    }

    @Override
    public void put(K k, V v) throws MyException {
        map.put(k, v);
    }

    @Override
    public String toString() {
        return "MyDictionary:"+map.toString();
    }
}

