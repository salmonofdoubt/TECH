//Encapsulation: Put data and methods into a single class to restrict access
//What describes a Bankaccount
public class BankAccount {
    private int account_number;
    private int account_balance;

    //Constructor
    public BankAccount(int account_number, int account_balance) {
        this.account_number = account_number;
        this.account_balance = account_balance;
        System.out.println("You created account " +
                this.account_number + " which has " + this.account_balance + " in it.");
    }

    //Methods, what can an object of this class do
    public void deposit(int addMoney) {
        if (addMoney < 0) {
            System.out.println("You cannot deposit a " +
                    "negative amount.");
        } else {
            this.account_balance = this.account_balance + addMoney;
            System.out.println("$" + addMoney + " " +
                    "deposited into account " +
                    this.account_number + ".");
        }
    }

    public void withdraw(int removeMoney) {
        if (removeMoney > this.account_balance) {
            System.out.println("You cannot remove more " +
                    "than what is in your account");
        } else {
            this.account_balance = this.account_balance - removeMoney;
            System.out.println("$" + removeMoney + " " +
                    "has been withdrawn from account " +
                    this.account_number + ".");
        }
    }
}
