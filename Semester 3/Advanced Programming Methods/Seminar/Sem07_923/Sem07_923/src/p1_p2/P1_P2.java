package p1_p2;

import java.util.Arrays;
import java.util.List;

/**
 *  Please start with a List of Strings similar to this:
 *      List<String> words = Arrays.asList("hi", "hello", ...);
 * P1. Loop down the words and print each on a separate line, with two spaces in front of each word. Don’t use map.
 *
 * P2. Repeat the previous problem, but without the two spaces in front. This is trivial if you use the same approach
 * as in P1, so the point is to use a method reference here, as opposed to an explicit lambda as in P1.
 *
 * https://www.oracle.com/technical-resources/articles/java/ma14-java-se-8-streams.html
 */

public class P1_P2 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "hi there", "good evening", "good night");
        System.out.println("Iterable action based\n------------");
        words.forEach(w-> System.out.println("  "+w));
        words.forEach(System.out::println);

        System.out.println("\nStream based\n------------");
        words.stream()
                .forEach(w-> System.out.println("  "+w));
        words.stream()
                .forEach(System.out::println);

        System.out.println();
        words.stream()
                .skip(2)
                .forEach(System.out::println);
    }

}
