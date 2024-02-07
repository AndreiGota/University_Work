package p6_p7_p8_p9_10;

import java.util.Arrays;
import java.util.List;

/**
 * P10. Find the number of words that contain an “h”.
 */


public class P10 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "hihi", "heep", "hurray");

        //ver 1
        System.out.println("\nnumber of strings containing 'h'-- filter, accumulate to list and size");
        System.out.println(words+"\nTotal of strings: "+
                words.stream()
                        .filter(s-> s.contains("h"))
                        .toList()
                        .size());

        System.out.println("\nnumber of strings containing 'h'-- filter then count them");
        System.out.println(words+"\nTotal of strings: "+
                words.stream()
                        .filter(s-> s.contains("h"))
                        .count());

        System.out.println("\nnumber of strings containing 'h'-- reduce and sum");
        System.out.println(words+"\nTotal of strings: "+
                words.stream()
                        .reduce(0,
                                (count, str)->{return count+(str.contains("h")?1:0);},
                                Integer::sum));
    }

}
