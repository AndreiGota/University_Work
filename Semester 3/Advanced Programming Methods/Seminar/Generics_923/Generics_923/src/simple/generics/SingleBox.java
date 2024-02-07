package simple.generics;

public class SingleBox<T> {
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

    public static void main(String[] v) {

        SingleBox<Integer> ob = new SingleBox<Integer>();
        //Integer i = new Integer(10);
        Integer i = 10;
        ob.setFirst(i);

        System.out.println(ob);

        Integer a = ob.getFirst();
        //System.out.println(a);

        Object obj =ob.getFirst();
        if (obj instanceof Integer)
        System.out.println("integer object: "+obj);

        //an error will be generated at compile time
        //String s = ob.getFirst();

/*
        SingleBox<String> ob = new SingleBox<>();
        //String s = new String("abc");
        String s = "abc";
        ob.setFirst(s);

        System.out.println(ob);

        String b = ob.getFirst();
        //System.out.println(b);

        Object obj =ob.getFirst();
        if (obj instanceof String)
            System.out.println("integer object: "+obj);

        //an error will be generated at compile time
        //Integer a = ob.getFirst();
*/
    }
}