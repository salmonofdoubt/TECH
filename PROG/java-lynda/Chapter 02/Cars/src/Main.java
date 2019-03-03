import java.awt.*;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World");
        System.out.println("Andre");

        Car myCar = new Car(70, "CA1234", Color.YELLOW, false);
        //Car otherCar = new Car(60,"161D2000", Color.BLUE, true);

        System.out.println("What is my car\'s paint color    ? " + myCar.paintColour.toString());

        myCar.changeCarColor(Color.BLACK);

        System.out.println("What is my car\'s paint color now? " + myCar.paintColour.toString());
    }
}