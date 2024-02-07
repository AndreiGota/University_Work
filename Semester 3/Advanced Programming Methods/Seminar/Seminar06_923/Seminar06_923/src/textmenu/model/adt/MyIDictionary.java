package textmenu.model.adt;

public interface MyIDictionary<K, V> {

    void put (K k, V v) throws MyException;
}