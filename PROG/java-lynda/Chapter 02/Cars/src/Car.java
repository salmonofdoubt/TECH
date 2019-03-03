import java.awt.*;

public class Car {
    //This is just the blueprint of a car
    //Learn some DataTypes
    //Color is defined in java.awt.Color, so import it
    //So below are just Attributes of Car

    int averageMileagePerGallon;
    String licensePlate;
    Color paintColour;
    boolean areTailLightsWorking;

    //here is the generator function for a car, it just associates variables
    public Car(int inputAvgMPG,
               String inputLicPlate,
               Color inputPaintCol,
               boolean inputTailLights){
        this.averageMileagePerGallon = inputAvgMPG;
        this.licensePlate = inputLicPlate;
        this.paintColour = inputPaintCol;
        this.areTailLightsWorking = inputTailLights;

    }
    public void changeCarColor(Color newColor){
        this.paintColour = newColor;

    }
}
