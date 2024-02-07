package simple.generics;

public class PairBox<T1, T2> extends SingleBox<T1> {
    private T2 second;

    public PairBox(T1 f, T2 s) {
        this.first = f;
        this.second = s;
    }

    public T2 getSecond()	{ return second; }
    public void setSecond(T2 t) { this.second=t; }

    @Override
    public String toString() {
        return "PairBox{" +
                "first=" + first +
                ", second=" + second +
                '}';
    }

    public static void main(String[] args) {

        PairBox<String, Integer> pairBox= new PairBox<>("abc", 10);
        System.out.println(pairBox);

        SingleBox<String> parent = pairBox;
        System.out.println(parent);
    }
}

