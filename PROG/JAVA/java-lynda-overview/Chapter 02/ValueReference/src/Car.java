import java.awt.*;

public class Car {

    double averageMilesPerGallon;
    String licensePlate;
    Color paintColor;
    boolean areTailingWorking;

    public Car(double inputAverageMPG,
               String inputLicensePlate,
               Color inputPaintColor,
               boolean inputAreTaillightsWorking) {
        this.averageMilesPerGallon = inputAverageMPG;
        this.licensePlate = inputLicensePlate;
        this.paintColor = inputPaintColor;
        this.areTailingWorking = inputAreTaillightsWorking;
    }

    public void changePaintColor(Color newPaintColor) {
        this.paintColor = newPaintColor;
    }

    //This is the new code demonstrating value and reference
    public void increaseSpeed(double currentSpeed) {
        currentSpeed += 100;
    }

    //With this method we return the value (no longer void, double)
    public double increaseSpeedReturnValue(double currentSpeed) {
        currentSpeed += 100;
        return currentSpeed;
    }
}
