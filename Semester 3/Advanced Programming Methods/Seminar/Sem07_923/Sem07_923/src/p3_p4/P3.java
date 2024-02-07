package p3_p4;

import p3_p4.v0.StringUtils;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 *  P3. We assume that we have a method StringUtils.transformedList(List<String>, Function1<String>)
 * where interface Function1<T> { T app(T);}
 * and we produced transformed lists like this:
 * • List<String> excitingWords = StringUtils.transformedList(words, s -> s + "!");
 * • List<String> eyeWords = StringUtils.transformedList(words, s -> s.replace("i", "eye"));
 * • List<String> upperCaseWords = StringUtils.transformedList(words, String::toUpperCase);
 * Produce the same lists as above, but this time use streams and the builtin “map” method.
 */


public class P3 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "hi there", "good evening", "good night");

        //with StringUtils.transformedList method
        System.out.println("StringUtils.transformedList based\n---------------");

        List<String> excitingWords = StringUtils.transformedList(words, s -> s + "!");
        excitingWords.forEach(System.out::println);
        System.out.println();

        List<String> eyeWords = StringUtils.transformedList(words, s -> s.replace("i", "eye"));
        eyeWords.forEach(System.out::println);
        System.out.println();

        List<String> upperCaseWords = StringUtils.transformedList(words, String::toUpperCase);
        upperCaseWords.forEach(System.out::println);
        System.out.println();

        //with map
        System.out.println("map based\n---------------");
        //words.stream().map(s -> s + "!").collect(Collectors.toList()).forEach(System.out::println);
        words.stream()
                .map(s -> s + "!")
                .toList()
                .forEach(System.out::println);
        System.out.println();
        words.stream()
                .map(s -> s.replace("i", "eye"))
                .collect(Collectors.toList())
                .forEach(System.out::println);
        System.out.println();
        words.stream()
                .map(String::toUpperCase)
                .collect(Collectors.toList())
                .forEach(System.out::println);
        System.out.println();
    }

}
