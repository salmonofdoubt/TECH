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
public class InterfaceDemo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        MountainBike Huffy = new MountainBike();
        Huffy.printStates();
        //update Bicycle info
        Huffy.changePedalRate(2);
        Huffy.speedUp(5);
        Huffy.changeGear(1);
        System.out.println("\nAfter updating the info: ");
        Huffy.printStates();
    }
    
}
