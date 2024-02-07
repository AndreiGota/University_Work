package execises.ex2;

import java.util.ArrayList;

/*
Compute the most specific signatures for the class A main methods (method1 and method2)
such that the entire program is correct.
If it is not possible to find the types justify your answer.
Discuss line by line the correctness of the above program.
 */

public class App0 {

    static A method1A(ArrayList<A> list) {
        if (list.isEmpty()) return null;
        else return list.get(0);
    }

    static A method1B(ArrayList<B> list) {
        if (list.isEmpty()) return null;
        else return list.get(0);
    }

    static A method1C(ArrayList<C> list) {
        if (list.isEmpty()) return null;
        else return list.get(0);
    }
    /////////////////////////////////////////////////

    static void method2A(ArrayList<A> list, A elem) {
        list.add(elem);
    }

    static void method2B(ArrayList<B> list, B elem) {
        list.add(elem);
    }

    static void method2C(ArrayList<C> list, C elem) {
        list.add(elem);
    }

   static void method3(C elem) {
        ArrayList<A> listA = new ArrayList<A>();
        listA.add(new A());
        ArrayList<B> listB = new ArrayList<B>();
        listB.add(new B());
        ArrayList<C> listC = new ArrayList<C>();
        listC.add(new C());

        A a = method1A(listA);
        A b = method1B(listB);
        A c = method1C(listC);
        System.out.println(method1A(listA));
        System.out.println(method1B(listB));
        System.out.println(method1C(listC));

        method2A(listA, elem); System.out.println(listA);
        method2B(listB, elem); System.out.println(listB);
        method2C(listC, elem); System.out.println(listC);
    }

    public static void main(String[] v){

        method3(new C());
    }
}

