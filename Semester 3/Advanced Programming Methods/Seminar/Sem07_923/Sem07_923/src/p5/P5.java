package p5;

import p3_p4.v0.StringUtils;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * P5. Turn the strings into uppercase,
 * keep only the ones that are shorter than 4 characters, of what is remaining,
 * keep only the ones that contain “E”,
 * and print the first result.
 *
 * Repeat the process, except checking for a “Q”
 * instead of an “E”. When checking for the “Q”, try to avoid
 * repeating all the code from when you checked for
 * an “E”.
 */


public class P5 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "Servus", "QEPPP", "seqqq");

        //ver 1
        System.out.println("UPPER CASE, length<4, E filtering, print first");
        words.stream()
                .map(s-> s.toUpperCase())
                .filter(s -> s.length() < 4)
                .filter(s->s.contains("E"))
                .findFirst()
                .ifPresent(System.out::println);

        System.out.println("UPPER CASE, length<4, Q filtering, print first");
        words.stream()
                .map(s-> s.toUpperCase())
                .filter(s -> s.length() < 4)
                .filter(s->s.contains("Q"))
                .findFirst()
                .ifPresent(System.out::println);

        //ver2
        System.out.println("\nUPPER CASE, length<4");
        List<String> partial= words.stream()
                .map(s-> s.toUpperCase())
                .filter(s -> s.length() < 4)
                .toList();
        partial.forEach(System.out::println);

        System.out.println("E filtering, print first");
        partial.stream()
                .filter(s->s.contains("E"))
                .findFirst()
                .ifPresent(System.out::println);
        System.out.println("Q filtering, print first");
        partial.stream()
                .filter(s->s.contains("Q"))
                .findFirst()
                .ifPresent(System.out::println);

        System.out.println("indexof(Q) != -1, print first");
        partial.stream()
                .filter(s->s.indexOf('Q')!=-1)
                .findFirst()
                .ifPresent(System.out::println);
        System.out.println("indexof(Q) != -1, print first or else \'No Match\'");
        String result = partial.stream()
                .filter(s->s.indexOf('Q')!=-1)
                .findFirst()
                .orElse("No match");
        System.out.println(result);
    }
}
