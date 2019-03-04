import java.util.Random;

public class Coin {

    public final static int HEADS = 0;
    public final static int TAILS = 1;

    private int faceUp;

    //constructor
    public Coin() {
        flip();
    }

    //method
    public void flip() {
        Random rand = new Random();
        faceUp = rand.nextInt(2);
    }

    //method
    public String getFaceUp() {
        if (faceUp == HEADS) {
            return "HEADS";
        } else if (faceUp == TAILS) {
            return "TAILS";
        } else {
            return "INVALID";
        }
    }

}

