package simple.nogenerics;

public class SingleBox {
    private Object first;

    public void setFirst(Object object) {
        this.first = object;
    }

    public Object getFirst() {
        return first;
    }

    @Override
    public String toString() {
        return "SingleBox{" +
                "first=" + first +
                '}';
    }

    public static void main(String[] v) {
        SingleBox ob = new SingleBox();

        //Integer i = new Integer(10);
        Integer i=10;
        int j=i;
        ob.setFirst(i);

        System.out.println(ob);

        //information about Integer is lost
        //we need a downcast to recover the specific information, namely the Integer
        Integer a = (Integer) ob.getFirst();

        //the cast may be wrong, it will pass the compiler but a runtime error will occur
        String s = (String) ob.getFirst();
        System.out.println("cast to string "+s);

        if (ob.getFirst() instanceof Integer) {
            Integer intObj = (Integer) ob.getFirst();
            System.out.println("Integer object: " + intObj);
        }

    }
}