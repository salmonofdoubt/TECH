import java.awt.*;
import java.lang.reflect.Array;
import java.util.concurrent.Future;
import java.util.Scanner;
import java.util.Arrays;

// < > <= >= == &&
// Create program based on age
public class Main {

    public static void main(String[] args) {

        String[] person = {"Adult", "Teen", "Kid", "Baby"};
        System.out.println("Enter age: ");
        Scanner sc = new Scanner(System.in);
        int age = sc.nextInt();

        if (age >= 0 && age <= 5) {
            System.out.println(person[3]);
        } else if (age >= 6 && age <= 11) {
            System.out.println(person[2]);
        } else if (age >= 12 && age <= 17) {
            System.out.println(person[1]);
        } else if (age >= 18) {
            System.out.println(person[0]);
        } else {
            System.out.println("Invalid ");
        }
        System.out.println("Thanks for using this program!");
    }
}
