/*
 * This program includes an example of a for loop, while loop and do...while loop
 */
package basicsreview;
import java.util.*;
/**
 *
 * @author Peggy Fisher
 */
public class Loops {

    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
        int choice;
        do{
            System.out.println("Choose and item from the list below: ");
            System.out.println("____________________________________");
            System.out.println("1. Hot dog");
            System.out.println("2. Hamburger");
            System.out.println("3. Cheeseburger");
            System.out.println("4. Veggie Burger");
            System.out.println("5. Nachos");
            choice = in.nextInt();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
        switch (choice)
        {
            case 1: 
                System.out.println("You chose a hot dog, that is $1.00");
                break;
            case 2: 
                System.out.println("You chose a hamburger, that is $2.50");
                break;
            case 3: 
                System.out.println("You chose a cheeseburger, that is $3.00");
                break;
            case 4: 
                System.out.println("You chose a veggie burger, that is $3.25");
                break;
            case 5: 
                System.out.println("You chose nachos, that is $1.75");
                break;
            default:
                System.out.println("Have a good day");
                break;
        }
        //loan problem
        double loanBalance = 5000;
        int months = 0;
        while(loanBalance >0)
        {
            loanBalance -= 500;
            months ++;
        }
        System.out.println("It will take "+months+" months to pay back your loan!");
        
        //print all odd numbers between 1 and 100
        System.out.println("Odd numbers between 1 and 100 are: ");
        for(int i = 1; i < 99; i++)
        {
            if(i%2 == 1)
            {
                System.out.print(i+", ");
            }
        }  System.out.print("99\n");
    }
    
}
    

