package wildcards;

public class WildcardsExample {
    public static void main(String v[]) {
        SingleBox<Number> box = new SingleBox<Number>();
        box.setFirst(10);   // Integer OK
        box.setFirst(10.1);  // Double OK

//        public void boxTest (SingleBox <Number> n) {
//            /* ... */
//        }

        //Are you allowed to pass in SingleBox<Integer> or SingleBox<Double>,as you might expect?
        //The answer is "no", because SingleBox<Integer> and SingleBox<Double> are not subtypes of SingleBox<Number >.

        //If we assume that SingleBox<Integer> is subtype of SingeBox<Number> we can have
        //the followings:

        //SingleBox<Number> box1 = new SingleBox<Integer>(); //the assumption
        //box1.setFirst(new Double(10.2)); //ERROR at runtime when you write the box content
        //System.out.println(box1);


        //SingleBox<?>
        //NOTE! -the only allowed operation is to read Object and to write null.
        //        - can be interpreted to have Object as content, but you cannot write anything only null
        //        - is the top of the hierarchy

        SingleBox<?> wildbox ;//= new SingleBox<Number>();
        SingleBox<Integer> intbox= new SingleBox<>();
        wildbox = intbox; //OK
        intbox.setFirst(2); //OK
        //wildbox.setFirst(2); //ERROR
        Integer nrint1 = intbox.getFirst(); //OK
        //Integer nrInt2 = wildbox.getFirst(); //ERROR
        Object nrint3= wildbox.getFirst(); //OK

        //in fact SingleBox<?> means SingleBox<T> where bottom < T> is Object


    }
}