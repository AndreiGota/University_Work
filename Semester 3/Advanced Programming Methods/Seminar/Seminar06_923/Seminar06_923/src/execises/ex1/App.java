package execises.ex1;

import java.util.ArrayList;

/*
    Compute the most specific signatures for the class A main methods (method1 and method2)
    such that the entire program is correct. If it is not possible to find the types justify
    your answer. Discuss line by line the correctness of the above program.
 */


public class App {


    static A method1(ArrayList<? extends A> list) {//upper bound, to get
        if (list.isEmpty()) return null;
        else return list.get(0);
    }

    static void method2(ArrayList<? extends A> list) {
        list.add(null);
    }

    static void method2elem(ArrayList<? super C> list, C elem) { //lower bound, to set/add
        list.add(elem);
    }

    static void method3() {
        ArrayList<A> listA = new ArrayList<>();
        listA.add(new A());
        ArrayList<B> listB = new ArrayList<>();
        listB.add(new B());
        ArrayList<C> listC = new ArrayList<>();
        listC.add(new C());


        A a =method1(listA);
        A b =method1(listB);
        A c =method1(listC);
        System.out.println(method1(listA));
        System.out.println(method1(listB));
        System.out.println(method1(listC));

        method2(listA); System.out.println(listA);
        method2(listB); System.out.println(listB);
        method2(listC); System.out.println(listC);

        method2elem(listA, new C()); System.out.println(listA);
        //method2elem(listB, new C()); System.out.println(listB); //no direct relationship between B and C
        method2elem(listC, new C()); System.out.println(listC);
    }


    public static void main(String[] v) {

        method3();
    }

}