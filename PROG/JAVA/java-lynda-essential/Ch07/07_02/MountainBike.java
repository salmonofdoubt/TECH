/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfacedemo;

/**
 *
 * @author Peggy Fisher
 */
public class MountainBike implements Bicycle{
    int pedalRate = 0;
    int speed = 0;
    int gear = 1;

   // The compiler will now require that methods
   // change pedalRate, changeGear, speedUp, and applyBrakes
   // all be implemented. Compilation will fail if those
   // methods are missing from this class.
      
      @Override
    public void changePedalRate(int newValue) {
         pedalRate = newValue;
    }
    
      @Override
    public void changeGear(int newValue) {
         gear = newValue;
    }
      @Override
    public void speedUp(int increment) {
         speed = speed + increment;   
    }
      @Override
    public void applyBrakes(int decrement) {
         speed = speed - decrement;
    }
    void printStates() {
         System.out.println(" pedal rate: " +
             pedalRate + " speed: " + 
             speed + " gear: " + gear);
    }
}  

