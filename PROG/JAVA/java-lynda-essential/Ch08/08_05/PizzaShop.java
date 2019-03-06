package pizzashop;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Peggy Fisher
 */
public class PizzaShop {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter customer name: ");
        String name = in.nextLine();
        ArrayList<Pizza> pizzas = new ArrayList<Pizza>();
        String response = "y";
        while(response.equals("y"))
        {
        System.out.println("What type of pizza would you like, regular or "
                + "sicilian? ");
        String type = in.nextLine();
         //Pizza pizza1 = new Regular();
        if(type.equalsIgnoreCase("regular"))
        {
            System.out.println("What size? S, M, L, X?");
            String size = in.nextLine();
            Regular pizza1 = new Regular();
            if(size.equalsIgnoreCase("S"))
            {
                pizza1 = new Regular(12);
            }
            else if(size.equalsIgnoreCase("M"))
            {
                pizza1 = new Regular(14);
            }
            else if(size.equalsIgnoreCase("L"))
            {
                pizza1 = new Regular(16);
            }
            else if(size.equalsIgnoreCase("X"))
            {
                pizza1 = new Regular(18);
            }
            pizza1.getToppings();
            pizzas.add(pizza1);
            
           
        }
        else
        {
            System.out.println("What size? S, M, L?");
            String size = in.nextLine();
            Sicilian pizza1 = new Sicilian();
            if(size.equalsIgnoreCase("S"))
            {
                pizza1 = new Sicilian(10);
            }
            else if(size.equalsIgnoreCase("M"))
            {
                pizza1 = new Sicilian(12);
            }
            else if(size.equalsIgnoreCase("L"))
            {
                pizza1 = new Sicilian(14);
            }
            pizza1.getToppings();
            pizzas.add(pizza1);
            
        }
            System.out.println("Do you want to order another pizza? (y/n)");
            response = in.nextLine();
        }
        for(Pizza p : pizzas)
        {
            p.printString();
        }
    }
    
}
