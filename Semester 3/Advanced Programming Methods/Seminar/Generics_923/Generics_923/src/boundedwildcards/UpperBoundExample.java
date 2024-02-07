package boundedwildcards;

/**
 * Use upper bounded wildcard to relax the restrictions on a variable.
 * For example, say you want to write a method that works on List<Integer>, List<Double>, and List<Number>;
 * you can achieve this by using an upper bounded wildcard.
 *
 * To declare an upper-bounded wildcard, use
 * -- the wildcard character ('?'), followed by
 * -- the extends keyword, followed by
 * -- its upper bound.
 * Note that, in this context, extends is used in a general sense to mean either
 * "extends" (as in classes) or "implements" (as in interfaces).
 *
 * https://docs.oracle.com/javase/tutorial/java/generics/upperBounded.html
 */


public class UpperBoundExample {

    public static void main(String v[]) {

        //Bounded Wildcards
        //Upper Bound –we can only READ THE CONTENT — Covariant subtyping


        SingleBox<? extends Integer> a = new SingleBox<Integer>();//OK
        SingleBox<? extends Number> b = a;  // OK
        SingleBox<? extends Number> c = new SingleBox<Integer>();//OK
        SingleBox<? extends Number> d = new SingleBox<Double>();//OK
        SingleBox<? extends Number> e = new SingleBox<Float>();//OK
        SingleBox<? extends Number> f = new SingleBox<Number>();//ERROR, Number is more restrictive than Number or any subtype of Number

        //SingleBox<? extends Integer> g = new SingleBox<Number>();//ERROR, Number is not a subtype of Integer


        //Upper bound means that we can only READ elements of the type (or of subclasses of the type) given by
        // the upper bound.

        //SingleBox<? extends Number> means SingleBox<T > where bottom < T < Number
        //and we can read Number or a subclass of Number.

        // example:
        //public Number processReadBox(SingleBox <? extends Number> a){
        //        return a.getFirst();
        //    }

        // and can be called by proccessReadBox (v) where v has the type SingleBox<? extends Integer>,
        //Integer is derived from Number or v can have the type SingleBox<Integer >

        SingleBox<Integer> intBox = new SingleBox<>();
        intBox.setFirst(23);

        SingleBox<? extends Number> b1 = intBox;  // OK
        Object intnr1 = b1.getFirst();

        SingleBox<? extends Integer> a1 = new SingleBox<Integer>();//OK
        //a1.setFirst(12);//error, upper bound cannot be used to set/add values, just to get/read values

        SingleBox<? extends Integer> a2 = new SingleBox<Integer>();//OK
        a2=intBox;
        Object intnr2= a2.getFirst();//error, upper bound cannot be used to set/add values, just to get/read values

        System.out.println("Integer box "+intBox+" "+processReadBox(intBox));
        System.out.println("? extends Number box "+b1+" "+processReadBox(b1));
        System.out.println("? extends Integer box "+a1+" "+processReadBox(a1));
        System.out.println("? extends Integer box "+a2+" "+processReadBox(a2));

    }

    //any type that is a subtype of Number
    public static Number processReadBox (SingleBox <? extends Number> a){
        return a.getFirst();
    }


    //problem code redundancy
    public static Double processReadBoxDouble (SingleBox <Double> a){
        return a.getFirst();
    }

    public static Integer processReadBoxInteger (SingleBox <Integer> a){
        return a.getFirst();
    }



}