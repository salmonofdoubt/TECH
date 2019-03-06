import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Welcome to Java Essentials");
        String prompt =  args[0];
        System.out.println(prompt);
        String name;
        int age;
        Scanner in = new Scanner(System.in);
        name = in.nextLine();
        age = in.nextInt();
        System.out.println("Hello, "+name + " nice to meet you\nYou are "
                    +age+" years old!");

    }
}

