package vavr;


import io.vavr.collection.List;

import java.util.Arrays;


public class Lists {
    public static void main(String[] v) {
        //list from java.util
        System.out.println("list from java.util");
        java.util.List<String> lJavaLang = Arrays.asList("abc", "def");//java.util.List
        lJavaLang.forEach(System.out::println);
        //lJavaLang.tail
        //lJavaLang.prepend


        System.out.println("list from vavr");
        List<String> l1 = List.of("abc", "def");//java.util.List
        l1.forEach(System.out::println);

        System.out.println("list from vavr with method prepend from vavr");
        List<String> l2 = l1.prepend("123");//not in java.util
        l2.forEach(System.out::println);

        System.out.println("list from vavr with method tail+prepend from vavr");
        //https://docs.vavr.io/#_linked_list
        List<String> l3 = l1.tail().prepend("123");//not in java.util
        l3.forEach(System.out::println);
    }
}
