package execises.ex1;

import java.util.ArrayList;

/*
    Compute the most specific signatures for the class A main methods (method1 and method2)
    such that the entire program is correct. If it is not possible to find the types justify
    your answer. Discuss line by line the correctness of the above program.
 */


public class App0 {


    static A method1A(ArrayList<A> list) {
        if (list.isEmpty()) return null;
        else return list.get(0);
    }

    static A method1B(ArrayList<B> list) {
        if (list.isEmpty()) return null;
        //B b= list.get(0);
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

    static void method3() {
        ArrayList<A> listA = new ArrayList<>();
        listA.add(new A());
        ArrayList<B> listB = new ArrayList<>();
        listB.add(new B());
        ArrayList<C> listC = new ArrayList<>();
        listC.add(new C());


        A a =method1A(listA);
        B b =(B)method1B(listB);
        C c =(C)method1C(listC);
        System.out.println(method1A(listA));
        System.out.println(method1B(listB));
        System.out.println(method1C(listC));

        method2A(listA, new A()); System.out.println(listA);
        method2B(listB, new B()); System.out.println(listB);
        method2C(listC, new C()); System.out.println(listC);
    }


    public static void main(String[] v) {

        method3();
    }


}