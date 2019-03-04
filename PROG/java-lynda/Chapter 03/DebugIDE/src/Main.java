import java.awt.*;
import java.lang.Math;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Coin c = new Coin();
        System.out.println("Initial: " + c.getFaceUp());
        for(int i = 0; i < 10; i++) {
            //set breakpoint at next line, and run debug mode
            //you can then step into more (IntelliJ)
            c.flip();
            System.out.println("After Flip: " + c.getFaceUp());
        }
    }
}
