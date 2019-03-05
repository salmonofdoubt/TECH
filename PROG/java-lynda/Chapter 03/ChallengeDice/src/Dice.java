import java.util.Random;

public class Dice {
    Random rand;
    //int previousRoll;

    public Dice() {
        this.rand = new Random();
    }

    public int roll() {
        int currentRoll = this.rand.nextInt(6) + 1;
        //this.previousRoll = currentRoll;
        //System.out.println("In roll function: " + previousRoll);
        return currentRoll;
    }
}


