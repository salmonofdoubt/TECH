import java.awt.*;
import java.lang.Math;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        System.out.println("Welcome to my Bank Account");
        //New object, by calling its constructor
        BankAccount myAccount = new BankAccount(100001, 100);
        //System.out.println(myAccount.account_balance);

        myAccount.deposit(100);
        //System.out.println(myAccount);
        myAccount.withdraw(200);

    }

}
