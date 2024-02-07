package p3_p4.v0;

import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class StringUtils {


    public static List<String> transformedList(List<String> list, Function1<String> fun){

        List<String> result= new ArrayList<>();
        for (String s: list)
            result.add(fun.app(s));

        return result;
        //return list.stream().map(x->fun.app(x)).collect(Collectors.toList());
    }

    public static List<String> allMatches(List<String> list, Predicate1<String> predicate){

        List<String> result= new ArrayList<>();
        for (String s: list)
            if (predicate.check((s)))
                result.add(s);
        return result;
        //return list.stream().filter(s->predicate.check(s)).toList();
    }
}
