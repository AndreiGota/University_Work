package p6_p7_p8_p9_10;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * P8. Produce a String that is all the words concatenated together, but with commas in between.
 * E.g., the result should be "hi,hello,...". Note that there is no comma at the beginning, before “hi”,
 * and also no comma at the end, after the last word.
 * Major hint: there are two versions of reduce discussed in the notes.
 */


public class P8 {
    public static void main(String[] v){
        List<String> words = Arrays.asList("hi", "hello", "good morning", "Servus", "QEPPP", "seqqq");

        //ver 1
        System.out.println("\nconvert to upper case then concatenate (identity, i.e., initial value, and accumulator)");
        System.out.println(words.stream()
                .reduce("",
                        (partial, elem)-> partial+","+elem));

        System.out.println("\nconvert to upper case then concatenate (identity, i.e., initial value, and accumulator) and substring to remove the first comma");
        System.out.println(words.stream()
                .reduce("",
                        (partial, elem)-> partial+","+elem)
                .substring(1));

        //ver 2
        System.out.println("\nconcatenate with comma (just accumulator, no identity, i.e., initial value) with ifPresent");
        words.stream()
                .reduce((partial, elem)-> partial+","+elem)
                .ifPresent(System.out::println);

        System.out.println("\nconcatenate with comma (just accumulator, no identity, i.e., initial value) and get --> String");
        System.out.println(words.stream()
                .reduce((partial, elem)-> partial+","+elem)
                .get()
        );

        System.out.println("\nconcatenate with comma (just accumulator, no identity, i.e., initial value) with ifPresent, one item");
        List<String> l=new ArrayList<>(); l.add("ll");
        l.stream()
                .reduce((partial, elem)-> partial+","+elem)
                .ifPresent(System.out::println);

        System.out.println("\nconcatenate with comma (just accumulator, no identity, i.e., initial value) with orElse, no items");
        List<String> l1=new ArrayList<>(); //l1.add("ll");
        String result = l1.stream()
                .reduce((partial, elem)-> partial+","+elem)
                .stream()
                .findFirst()
                .orElse("no items");
        System.out.println(result);

        //Collectors.joining
        System.out.println("\nconcatenate with comma in Collectors.joining");
        System.out.println(words.stream()
                .collect(Collectors.joining(",")));
    }
}
