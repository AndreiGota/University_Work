package io;

import java.io.FileWriter;
import java.io.IOException;

public class FileWriterExample {

    public static void main(String[] v){
        try(FileWriter fileWriter = new FileWriter(".//data//filewriter.txt",true)){
            //true –appends, false or nothing-overwrites
            fileWriter.write("data 1\n");
            fileWriter.write("data 2\n");
            fileWriter.write("data 3\n");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}