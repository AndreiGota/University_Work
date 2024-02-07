package boundedwildcards;

/**
 *
 * Use lower bounded wildcard to restrict the unknown type to be a specific type or a super type of that type.
 *
 * A lower bounded wildcard is expressed using
 * -- the wildcard character ('?'), following by
 * -- the super keyword, followed by
 * -- its lower bound: <? super A>.
 *
 * Note: You can specify an upper bound for a wildcard, or you can specify a lower bound,
 * but you cannot specify both.
 *
 * Say you want to write a method that puts Integer objects into a list. To maximize flexibility,
 * you would like the method to work on List<Integer>, List<Number>, and List<Object> — anything that
 * can hold Integer values.
 *
 * To write the method that works on lists of Integer and the supertypes of Integer, such as Integer,
 * Number, and Object, you would specify List<? super Integer>.
 *
 * The term List<Integer> is more restrictive than List<? super Integer> because the former matches
 * a list of type Integer only, whereas the latter matches a list of any type that is a supertype of Integer.
 *
 * https://docs.oracle.com/javase/tutorial/java/generics/lowerBounded.html
 */


public class LowerBoundExample {

    public static void main(String v[]) {

        //Bounded Wildcards
        //Lower Bound – we can only WRITE the content – contravariant subtyping


        SingleBox<? super Number> a = new SingleBox<Number>();//OK
        SingleBox<? super Integer> b = a;  // OK, Number is a superclass of Integer
        //SingleBox<? super Number> c = new SingleBox<Integer>();//ERROR, Integer is not a superclass of Number
        SingleBox<? super Integer> d = new SingleBox<Number>();//OK, Number is a superclass of Number

        d=b;
        //Lower bound means that we can write elements of type (or of superclasses of the type) given by
        // the lower bound.
        // SingleBox<? super Integer> means SingleBox<T > where Integer < T < Object
        //and we can write Integer or a superclass of Integer.

        //example:public static void processWriteBox (Box < ? super Integer > a, Integer x){
        //            a.setFirst(x);
        //        }

        //and can be called by proccessWriteBox (v) where v has the type Box<? super Number>,
        //Integer is derived from Number or v can have the type Box<Integer >

        processWriteBox(a, 12);
        System.out.println("? super Number box: "+a+" "+a.getFirst());

        SingleBox <?> wildbox= null;
        SingleBox <?> wildboxObject =new SingleBox<Object>(); //unbounded wildcard
        SingleBox <?> wildboxInteger =new SingleBox<Integer>(); //unbounded wildcard
        SingleBox <?> wildboxNumber =new SingleBox<Number>(); //unbounded wildcard

        SingleBox<? extends Object> objbox = (SingleBox<? extends Number>) wildboxObject;//upper bound + unbound
        SingleBox<? extends Number> nrbox = (SingleBox<? extends Number>) wildboxNumber;//upper bound + unbound
        SingleBox<? super Integer> intbox = (SingleBox<? super Integer>) wildboxInteger;//lower bound + unbound
        wildbox = nrbox; //OK
        wildbox = intbox;//OK
        processWriteBox(b, 122);
        System.out.println("? super Integer box: "+b+" "+b.getFirst());
        processWriteBox(b, 123);
        System.out.println("? super Integer box: "+d+" "+d.getFirst());

        processWriteBox((SingleBox<? super Integer>) wildbox, 100);
        System.out.println("? super Integer box: "+wildbox+" "+wildbox.getFirst());


    }

    //any type that is the parent of type Integer
    public static void processWriteBox (SingleBox < ? super Integer > a, Integer x){
        a.setFirst(x);
    }


    //problem code redundancy
    public static void processWriteBoxInteger (SingleBox < Integer > a, Integer x){
        a.setFirst(x);
    }

    public static void processWriteBoxNumber (SingleBox < Number > a, Number x){
        a.setFirst(x);
    }

    public static void processWriteBoxObject (SingleBox < Object > a, Object x){
        a.setFirst(x);
    }
}