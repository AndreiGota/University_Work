package boundedparamaters.example1;

/**
 *
 * Bounded Type Parameter
 * - when you want to restrict the types that can be used as type arguments in a parameterized type.
 * For example, a method that operates on numbers might only want to accept instances of Number or its subclasses.
 * This is what bounded type parameters are for.
 *
 * - To declare a bounded type parameter,
 * -- list the type parameter's name, followed by
 * -- the extends keyword, followed by
 * -- its upper bound, which in this example is Number.
 * Note that, in this context, extends is used in a general sense to mean either
 * "extends" (as in classes) or "implements" (as in interfaces).
 *
 * <T extends Number>
 */



public class NaturalNumber<T extends Integer> {
    private T n;
    public NaturalNumber(T n)  { this.n = n; }
    public boolean isEven() {
        //return true;
        return n.intValue() % 2 == 0;
    //T must be a subclass of Integer. Otherwise the compiler will signal an error
    // isEven method invokes the intValue method defined in the Integer class through n.
     //   T is a subclass of Integer ==> it has access to the intValue () method
    }

    @Override
    public String toString() {
        return ""+n;
    }

    public static void main(String[]v){
       NaturalNumber<Integer> nr=new NaturalNumber<>(29);
       System.out.println("number: "+nr+ (nr.isEven()?" is even": " is odd"));
   }


}

