package boundedparamaters.example3;

public class SingleBox<T> implements Comparable {
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
    public int compareTo(Object o) {
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