package simple.generics;


public class RawTypes {
    public static void main(String[] v){

/*
        SingleBox<String> stringBox = new SingleBox<>();
        stringBox.setFirst("abc");
        System.out.println("string Box: "+stringBox);


        //raw type <=== parameterized type
        SingleBox rawBox = stringBox; // OK rawBox can hold any type of box (Object - string, integer, etc.)
        System.out.println("raw Box: "+rawBox+"\n");

*/

/*
        //parameterized types  <=== raw type
        //But if you assign a raw type to a parameterized type, you get a warning:

        SingleBox rawBox1 = new SingleBox(); // rawBox is a raw type of Box<T>, it allows items of type Object
        rawBox1.setFirst(10);
        rawBox1.setFirst("abcd");

        SingleBox<Integer> intBox = rawBox1;     // warning: unchecked conversion
        System.out.println("raw Box1: "+rawBox1);
        System.out.println("integer object: "+intBox);
        System.out.println("integer object incremented: "+(intBox.getFirst()+1)+"\n");
*/


        //You also get a warning if you use a raw type to invoke generic
        //methods defined in the corresponding generic type:

        SingleBox<String> stringBox1 = new SingleBox<>();
        stringBox1.setFirst("abcde");
        System.out.println("string Box1: "+ stringBox1);


        SingleBox rawBox2= stringBox1;
        rawBox2.setFirst(8);  // warning: unchecked invocation to set(T)// we can add value of type Object
        System.out.println("string Box1: "+ stringBox1);
        System.out.println("raw Box2 (integer): "+rawBox2);
        System.out.println("raw Box2 (integer): "+((Integer)rawBox2.getFirst()+1));

        //NOTE: The warning shows that raw types bypass generic type checks,
        //deferring the catch of unsafe code to runtime.  Therefore, you should avoid using raw types!!!!!!!!!

        //raw types should be avoided, because
        //- They are not expressive
        //- They lack type safety, and
        //- Problems are observed at run time and not at compile time
    }
}
