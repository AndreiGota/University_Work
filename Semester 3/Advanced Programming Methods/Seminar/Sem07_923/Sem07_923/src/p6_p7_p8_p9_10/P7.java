package p6_p7_p8_p9_10;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


/**
 * P7. Produce the same String as above, but this time via a map operation that turns the words into uppercase,
 * followed by a reduce operation that concatenates them.
 */


public class P7 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "Servus", "QEPPP", "seqqq");

        //ver 1, (1) Upper case using map (2) reduce with identity
        System.out.println("convert to upper case then concatenate (identity, i.e., initial value, and accumulator)");
        System.out.println(words.stream()
                .map(String::toUpperCase)
                .reduce("",
                        (partial, elem)-> partial+":"+elem));

        //ver 2, (1) Upper case using map (2) reduce, no identity
        System.out.println("convert to upper case then concatenate them (just accumulator, no identity, i.e., initial value) with ifPresent");
        words.stream()
                .map(String::toUpperCase)
                .reduce((partial, elem)-> partial+":"+elem)
                .ifPresent(System.out::println);

        System.out.println("convert to upper case then concatenate them (just accumulator, no identity, i.e., initial value) with ifPresent, one item");
        List<String> l=new ArrayList<>(); l.add("ll");
        l.stream()
                .map(String::toUpperCase)
                .reduce((partial, elem)-> partial+":"+elem)
                .ifPresent(System.out::println);

        System.out.println("convert to upper case then concatenate them (just accumulator, no identity, i.e., initial value) with orElse, no items");
        List<String> l1=new ArrayList<>(); //l1.add("ll");

        String result = l1.stream()
                .map(String::toUpperCase)
                .reduce((partial, elem)-> partial+elem)
                .stream()
                .findFirst()
                .orElse("no items");
        System.out.println(result);

    }

}
