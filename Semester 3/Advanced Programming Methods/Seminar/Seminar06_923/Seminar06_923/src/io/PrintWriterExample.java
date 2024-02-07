package io;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class PrintWriterExample {
    public static void main(String[] v) throws IOException {
        FileWriter writer = new FileWriter(".//data/PWfile.txt", true);
        PrintWriter printWriter = new PrintWriter(writer);
        printWriter.print(true);
        printWriter.println((int) 123);
        printWriter.print((float) 123.456);
        int intVar=200;
        printWriter.printf("Text + data: %d", intVar);
        printWriter.close();
    }
}