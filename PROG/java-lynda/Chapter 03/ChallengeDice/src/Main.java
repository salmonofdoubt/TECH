

public class Main {
    public static void main(String[] argv) {
        System.out.println("Hello Dice Program");
        Dice d = new Dice();
        //Dice object
        System.out.println(d);

        // System.out.println(d.previousRoll);
        System.out.println(d.roll());
        System.out.println(d.roll());



    }
}
