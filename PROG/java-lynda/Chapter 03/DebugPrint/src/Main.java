import java.awt.*;
import java.lang.Math;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        //Its random even on creation, because Coin calls flip() right away
        Coin myCoin = new Coin();
        //first check
        System.out.println(myCoin.getFaceUp() + "\n");

        for (int i = 0; i < 10; i++) {
            myCoin.flip();
            System.out.println(myCoin.getFaceUp());
        }
    }
}
