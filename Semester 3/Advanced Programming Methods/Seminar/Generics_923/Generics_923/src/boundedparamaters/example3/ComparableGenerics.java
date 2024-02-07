package boundedparamaters.example3;

//A generic algorithm
//public interface Comparable {
//    int compareTo(Object o);
//}
// A generic algorithm to compare the first fields:

public class ComparableGenerics {

    public static <T extends Comparable>
    int checkFields(SingleBox<T> box, T elem) {
//        if (elem.compareTo(box.getFirst()) >= 0)
//            return 1;
//        else
//            return -1;
        return elem.compareTo(box.getFirst());
    }


    public static void main(String[] v){

        SingleBox<String> stringBox= new SingleBox<>();
        stringBox.setFirst("abc");
        System.out.println("string box: "+(checkFields(stringBox,"abc")==0?stringBox+"="+"abc":stringBox+"!="+"abc"));

        System.out.println("string box compared to an integer ??? "+(stringBox.compareTo(12)==0?stringBox+"="+12:stringBox+"!="+12));
        System.out.println("string box compared to string "+(stringBox.compareTo("abc")==0?stringBox+"="+"abc":stringBox+"!="+"abc"));


        SingleBox<Integer> intBox= new SingleBox<>();
        intBox.setFirst(12);
        System.out.println(checkFields(intBox,122)==0?intBox+"="+122:intBox+"!="+122);
    }
}
