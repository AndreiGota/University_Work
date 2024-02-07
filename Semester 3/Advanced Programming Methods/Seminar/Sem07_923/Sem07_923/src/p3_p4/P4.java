package p3_p4;

import p3_p4.v0.StringUtils;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 *  P4. We assume that we have the method StringUtils.allMatches(List<String>, Predicate1<String>) where
 *  interface Predicate1<T> { boolean check(T);}
 * and we produced filtered lists like this:
 * • List<String> shortWords = StringUtils.allMatches(words, s -> s.length() < 4);
 * • List<String> wordsWithB = StringUtils.allMatches(words, s -> s.contains("b"));
 * • List<String> evenLengthWords = StringUtils.allMatches(words, s -> (s.length() % 2) == 0);
 * Produce the same lists as above, but this time use “filter”.
 */


public class P4 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "hi there", "good evening", "good night");

        //with StringUtils.allMatches
        System.out.println("StringUils.allMatches based\n---------------");
        List<String> shortWords = StringUtils.allMatches(words, s -> s.length() < 4);
        shortWords.forEach(System.out::println);
        System.out.println();

        List<String> wordsWithB = StringUtils.allMatches(words, s -> s.contains("b"));
        wordsWithB.forEach(System.out::println);
        System.out.println();

        List<String> evenLengthWords = StringUtils.allMatches(words, s -> (s.length() % 2) == 0);
        evenLengthWords.forEach(System.out::println);
        System.out.println();

        //with filter
        System.out.println("filter based\n---------------");
        System.out.println("length < 4:");
        words.stream()
                .filter(s -> s.length() < 4)
                .collect(Collectors.toList())
                .forEach(System.out::println);
        //words.stream().filter(s -> s.length() < 4).toList().forEach(System.out::println);
        System.out.println("Containing b:");
        words.stream()
                .filter(s -> s.contains("b"))
                .toList()
                .forEach(System.out::println);
        System.out.println("Length even:");
        words.stream()
                .filter(s -> (s.length() % 2) == 0)
                .toList()
                .forEach(System.out::println);
        System.out.println();
    }

}
