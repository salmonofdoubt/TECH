import java.awt.*;
import java.lang.Math;
import java.util.Random;

//Inheritance "extends", "super"

public class Main {
    public static void main(String[] args) {
        System.out.println("Welcome to Critters Program");

        Cricket myCricket = new Cricket(11, 2.3);
        Insect myInsect = new Insect(3,6);
        Spider mySpider = new Spider(1, true);

        System.out.println(mySpider);

        //since Spider extends the Insect class,
        myInsect.crawls();  //Insect crawled
        myInsect.says();    //Insect says

        mySpider.crawls();  //Insect crawled    ::inherits Insect.crawls()
        mySpider.says();    //Spider says       ::overwrites with its own says()

        myCricket.crawls(); //Insect crawled    ::inherits Insect.crawls()
        myCricket.says();   //Cricket says      ::overwrites with its own says()
        myCricket.jumps();  //Cricket jumps     ::overwrites with its own says()

        System.out.println("Are both mySpider and myCricket instances of an Insect?");
        System.out.println(mySpider instanceof Insect && myCricket instanceof Cricket);
    }
}
