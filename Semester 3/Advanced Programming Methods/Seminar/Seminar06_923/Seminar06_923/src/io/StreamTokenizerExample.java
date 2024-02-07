package io;

import java.io.*;

public class StreamTokenizerExample {

    public static void main(String[] v) throws FileNotFoundException {
        Reader reader = new FileReader(".//data/StreamTRfile.txt");
        try{
            StreamTokenizer streamTokenizer = new StreamTokenizer(reader);
            while(streamTokenizer.nextToken() != StreamTokenizer.TT_EOF){
                if(streamTokenizer.ttype == StreamTokenizer.TT_WORD) {
                    System.out.println(streamTokenizer.sval);
                } else if(streamTokenizer.ttype == StreamTokenizer.TT_NUMBER) {
                    System.out.println(streamTokenizer.nval);
                } else if(streamTokenizer.ttype == StreamTokenizer.TT_EOL) {
                    System.out.println();
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

