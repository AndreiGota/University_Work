package p6_p7_p8_p9_10;

import java.util.Arrays;
import java.util.List;

/**
 * P9. Find the total number of characters (i.e., sum of the lengths) of the strings in the List.
 */


public class P9 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "Servus", "QEPPP", "seqqq");

        System.out.println("\nsum of length reduce (identity, accumulator, combiner)");
        System.out.println("Total length: "+
                words.stream()
                .reduce(0,
                        (partial, elem)-> partial+elem.length(),
                        Integer::sum));

        System.out.println("\nsum of length maptoInt(String::length).sum()");
        System.out.println("Total length: "+
                words.stream()
                .mapToInt(String::length)
                .sum());


        System.out.println("\nmin/max length reduce (identity, accumulator, combiner)");
        System.out.println("min/max length: "+
                words.stream()
                        .reduce(0,
                                (partial, elem)->
                                        Math.min(partial, elem.length()),
                                Integer::min));

    }

}
