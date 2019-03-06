package findname;
import java.util.*;

/**
 *
 * @author Peggy Fisher
 */
public class FindName {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String[][] names = {{"Mickey", "Mouse"},
            {"Donald", "Duck"},
            {"Goofy", "Pluto"},
            {"Snow", "White"},
            {"James", "Bond"},
            {"Doc", "Sneezy"},
            {"Scotty", "Jimmy"},
            {"Peggy", "Sandy"},
            {"Joe", "Sean"},
            {"Alice", "Mackenzie"},
            {"Reshmi", "Vasant"},
            {"Steve", "Rae"}};
        //ask the user to enter a name, then pass the name and array to 
        //the method to search for that name. 
        String name, response = "y";
        while(response.equalsIgnoreCase("y"))
        {
        System.out.println("Enter the name to search for: ");
        Scanner in = new Scanner(System.in);
        name = in.nextLine();
        if(searchName(names,name)==true)
            System.out.println("The name was found!!! ");
        else
            System.out.println("The name was not found");
        System.out.println("Would you like to try again?");
        response = in.nextLine();
        }
        System.out.println("Thanks for playing the name search game");
        }
    public static boolean searchName(String[][] names, String key)
    {
        for(int row=0;row<names.length;row++)
        {
            for(int col=0;col<names[0].length;col++)
            {
                if(names[row][col].equalsIgnoreCase(key))
                    return true;
            }
        }
        return false;
    }
    }
    

