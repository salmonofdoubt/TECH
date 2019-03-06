import java.awt.*;
import java.lang.reflect.Array;
import java.util.Random;
import java.util.concurrent.Future;
import java.util.Scanner;
import java.util.Arrays;


public class Main {

    public static void main(String[] args) {
        //Math class from Java.lang is already imported by default
        double power = Math.pow(5, 3);
        double sqrRoot = Math.sqrt(3);
        System.out.println(power);
        System.out.println(sqrRoot);

        //Random class must be imported explicitly
        Random rand = new Random();
        int random = rand.nextInt();
        System.out.println(random);
        int randomBound = rand.nextInt(10);
        System.out.println(randomBound);
    }
}
