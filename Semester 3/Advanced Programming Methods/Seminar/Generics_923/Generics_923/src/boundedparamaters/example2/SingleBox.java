package boundedparamaters.example2;

//A generic Comparable interface
// public interface Comparable<T> {
//    int compareTo(T o);
//}

// the raw type for Comparable<T> is the interface Comparable
// public interface Comparable {
//    int compareTo(Object o);
//}

/**
 * Comparable
 *
 *     1. It's meant for default natural Sorting order
 *     2. present in java.lang
 *     3. Define only one method compareTo(1 param)
 *     4. All wrapper classes & String class
 *     5. https://docs.oracle.com/javase/8/docs/api/java/lang/Comparable.html
 *
 * Comparator
 *
 *     1. It's meant for customised Sorting order
 *     2. present in java.util
 *     3. Define 2 methods compare(2 params) and equals(1 param)
 *     4. Rules based classes
 *     5. https://docs.oracle.com/javase/8/docs/api/java/util/Comparator.html
 */

public class SingleBox<T> implements Comparable<T> {
    // T stands for "Type"
    protected T first;
    public void setFirst(T t) {
        this.first = t;
    }
    public T getFirst() {
        return first;
    }

    @Override
    public String toString() {
        return "SingleBox{" +
                "first=" + first +
                '}';
    }

    @Override
    public int compareTo(T o) {
        if (first.equals(o)) return 0;
        return -1;
    }


    public static void main(String[] v) {
        SingleBox<Integer> ob1 = new SingleBox<Integer>();
        Integer i =  10;
        ob1.setFirst(i);
        System.out.println(ob1);
        System.out.println(ob1.compareTo(ob1.getFirst())==0?(ob1+"="+ob1):(ob1+"!="+ob1));

        SingleBox<Integer> ob2 = new SingleBox<Integer>();
        Integer k =  20;
        ob2.setFirst(k);
        System.out.println(ob2);
        System.out.println(ob2.compareTo(ob2.getFirst())==0?(ob2+"="+ob2):(ob2+"!="+ob2));
        System.out.println(ob1);
        System.out.println(ob2.compareTo(ob1.getFirst())==0?(ob2+"="+ob1):(ob2+"!="+ob1));

    }


}