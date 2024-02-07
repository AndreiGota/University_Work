package io;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ScannerExample {
    public static void main(String[] v) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(".//data//Scannerfile.txt"));
        while (sc.hasNextLong()) {
            long aLong = sc.nextLong();
            System.out.println(aLong);
        }
    }
}

