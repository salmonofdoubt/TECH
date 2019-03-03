import java.awt.*;

public class Main {

    public static void main(String[] args) {
        Car myCar = new Car(25.5,
                "1BC32E",
                Color.BLUE,
                true);

        Car sallyCar = new Car(13.9,
                "3D2OBN",
                Color.BLACK,
                false);

        //This is the new code demonstrating value and reference
        double myCarSpeed = 50;
        myCar.increaseSpeed(myCarSpeed);
        //Remains 50, so Java is call by value (Javalue)
        System.out.println(myCarSpeed);

        //So we change the original function to actually return
        //and reassign the new value to variable
        myCarSpeed = myCar.increaseSpeedReturnValue(myCarSpeed);
        //And hence myCarSpeed changes
        System.out.println(myCarSpeed);







    }
}
