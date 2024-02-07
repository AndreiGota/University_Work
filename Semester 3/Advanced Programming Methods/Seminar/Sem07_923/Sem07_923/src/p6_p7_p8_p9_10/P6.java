package p6_p7_p8_p9_10;

import java.util.Arrays;
import java.util.List;

/**
 * P6. Produce a single String that is the result of concatenating the uppercase versions of all the Strings.
 * Use a single reduce operation, without using map.
 */


public class P6 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "Servus", "QEPPP", "seqqq");

        //(1) UpperCase (2) reduce
        System.out.println("upper case then concatenate and uses map --  not good!");
        //System.out.println(words.stream().map(String::toUpperCase).reduce("", (partial, elem)-> partial.toUpperCase()+":"+elem.toUpperCase()));
        System.out.println(words.stream()
                .map(s-> s.toUpperCase())
                .reduce("",
                        (partial, elem)-> partial+":"+elem));

        //(1) reduce + UpperCase
        System.out.println("concatenate the upper cases (during reduce)");
        //System.out.println(words.stream().reduce("", (partial, elem)-> partial.toUpperCase()+":"+elem));
        System.out.println(words.stream()
                .reduce("",
                        (partial, elem)-> partial+":"+elem.toUpperCase()));

        // (1) reduce (2) UpperCase
        System.out.println("concatenate then to upper case");
        System.out.println(words.stream()
                .reduce("123",
                        (partial, elem)-> partial+":"+elem)
                .toUpperCase());

    }

}
