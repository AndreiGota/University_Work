package io;

import java.io.*;
import java.util.StringTokenizer;

public class StringTokenizerExample {

    public static void main(String[] v) throws FileNotFoundException {
        BufferedReader br = new BufferedReader(new FileReader(".//data/StringTRfile.txt"));
        try{
            String line=null;
            while((line = br.readLine())!=null){
                StringTokenizer stringTokenizer = new StringTokenizer(line, " ");

                while (stringTokenizer.hasMoreTokens())
                    System.out.println(stringTokenizer.nextToken());
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}