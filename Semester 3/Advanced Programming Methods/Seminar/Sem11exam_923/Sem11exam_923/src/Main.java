import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/*
2.(3p). Given the following collection
List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8,9,10,11,12,14,15,16);
Using Java functional style (Java streams),
please write a program that is doing the following operations in the following order:
a)eliminates all the numbers which are not multiple of 4;
b)transform each remaining number into its succesor (eg. 4 is transformed into 5);
c)compute the sum modulo 2 of the remaining numbers (eg. (9 +5) mod 2=0)
d)transform the result into a list
 */



public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8,9,10,11,12,14,15,16);//c) modulo 2==1  with ,17,18,19,20

        System.out.println("Initial List:"+numbers);

        //a) eliminates all the numbers which are not multiple of 4;
        numbers.stream().filter(x-> x%4==0).forEach(x->System.out.print(x+" "));

        System.out.println();

        //b)transform each remaining number into its succesor (eg. 4 is transformed into 5);
        numbers.stream().filter(x-> x%4==0).map(x-> x+1).forEach(x->System.out.print(x+" "));

        System.out.println();

        //c)compute the sum modulo 2 of the remaining numbers (eg. (9 +5) mod 2=0)
        System.out.println("sum modulo 2: "+(numbers.stream().filter(x-> x%4==0).map(x-> x+1).reduce(0, (p, x)-> p+x, Integer::sum))%2);

        System.out.println();

        //d)transform the result into a list
        Arrays.asList(numbers.stream().filter(x-> x%4==0).map(x-> x+1).reduce(0, (p, x)-> p+x, Integer::sum)%2).forEach(System.out::print);


    }
}