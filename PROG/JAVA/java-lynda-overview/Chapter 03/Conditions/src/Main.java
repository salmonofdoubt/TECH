import javax.sound.midi.SysexMessage;
import java.awt.*;
import java.lang.reflect.Array;
import java.util.concurrent.Future;
import java.util.Scanner;
import java.util.Arrays;

//Loops: while   do while   for
public class Main {

    public static void main(String[] args) {
        System.out.println("---WHILE---");
        int x = 3;
        while (x > 0) {
            System.out.println("x = " + x);
            x = x - 1;
        }
        //after that:
        System.out.println("Final x = " + x);

        System.out.println("---DO WHILE---");
        int y = 3;
        do {
            System.out.println("y = " + y);
            y = y - 1;
        } while (y > 0);
        //after that
        System.out.println("Final y = " + y);

        int z;
        System.out.println("---FOR---");
        for (z = 3; z > 0; z--) {
            System.out.println("z = " + z);
        }
        System.out.println(z);
    }
/*
        String[] person = {"Adult", "Teen", "Kid", "Baby"};

        Scanner sc = new Scanner(System.in);
        int age = sc.nextInt();

        while (age >= 0) { 
            System.out.println("Enter age: ");
            age = sc.nextInt();
        if (age >= 0 && age <= 5) {
            System.out.println(person[3]);
            age = sc.nextInt();
        } else if (age >= 6 && age <= 11) {
            System.out.println(person[2]);
            age = sc.nextInt();
        } else if (age >= 12 && age <= 17) {
            System.out.println(person[1]);
            age = sc.nextInt();
        } else if (age >= 18) {
            System.out.println(person[0]);
            age = sc.nextInt();
        } else {
            System.out.println("Invalid ");
        }
        System.out.println("Thanks for using this program!");
        }
    }
*/
}