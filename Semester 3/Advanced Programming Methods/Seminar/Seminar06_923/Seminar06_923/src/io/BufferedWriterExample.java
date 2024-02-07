package io;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class BufferedWriterExample {
    public static void main(String[] v) throws IOException {
        FileWriter output = new FileWriter(".//data/BWdata.bin",false);
        try(BufferedWriter bufferedWriter = new BufferedWriter(output)){
            for(int i=0;i<5;i++){
                bufferedWriter.write("Hello World"+(i+1));
                bufferedWriter.newLine();
                if(i%3==0)
                    bufferedWriter.flush();
            }
        }
    }
}