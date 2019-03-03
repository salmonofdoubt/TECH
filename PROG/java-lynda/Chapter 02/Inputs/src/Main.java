import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        //create scanner object
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string...");
        //Wait for sys inputx
        String userInputString = sc.next();

        System.out.println("Enter a possible substring...");
        String userInputSubString = sc.next();

        sc.close();

        System.out.println(userInputString +
                    " contains " +
                    userInputSubString.toLowerCase() +
                    " " +
                    userInputString.contains(userInputSubString.toLowerCase()));
    }
}
