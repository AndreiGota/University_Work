package io;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class BufferedReaderExample {

    private static void method1() throws FileNotFoundException {
        Reader reader = new FileReader(".//data/BRdata1.bin");
        try (BufferedReader bufferedReader = new BufferedReader(reader)) {
            String line = bufferedReader.readLine();
            while (line != null) {
                System.out.println(line);//do something with line
                line = bufferedReader.readLine();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private static void method2(String numefis) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(numefis));
        String linie;
        while ((linie = br.readLine()) != null) {
            String[] elems = linie.split("[|]");
            if (elems.length < 2) {
                System.err.println("Linie invalida " + linie);
            }
            else System.out.println(Arrays.stream(elems).toList());//do something with the line
        }
    }


        public static void main (String[] v) throws IOException {

            method1();
            System.out.println();
            method2(".//data/BRdata2.bin");
        }
    }
