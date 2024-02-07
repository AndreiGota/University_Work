package io;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class FileReaderExample {

    public static void main(String[] v){
        try(FileReader fileReader = new FileReader(".//data//filereader.txt")){
            int data = fileReader.read();
            while(data != -1) { // read a char
                System.out.print((char) data);
                //System.out.println((char) data);
                //System.out.print((int) data+" ");
                //System.out.println((int) data+" "+(char)data);
                data = fileReader.read();
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}