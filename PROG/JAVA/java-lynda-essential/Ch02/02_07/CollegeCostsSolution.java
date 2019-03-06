/* Write a program that computes and displays the total yearly expenses 
*  for a student in college.  
*  The student might be living on campus (or in a nearby apartment) or 
*  commuting.  
*  For a student living on campus, ask the user for: 
*    number of weeks they will be living on campus
*    estimated weekly living expenses (outside of room and board)
*    estimated amount of room and board per year
*
*  For all students: 
*    name and year (freshman, sophomore, junior, senior)
*    estimated costs of textbooks, pencils, paper, etc.
*    number of credit hours for the year
*    cost per credit hour
*
*  Calculate the total cost for attending college for one year, 
*     print the final total.
*  Write separate methods for each request and only 
*     use the main to call the methods. 
*/
package basicsreview;

import java.util.Scanner;

public class CollegeCostsSolution {

    /**
     * @param args the command line arguments
     */
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        String name = getName();
        printTotal(name);
    }
    public static String getName()
    {
        System.out.println("What is the name of the student?");
        String name = in.nextLine();
        return name;
    }
     public static void printTotal(String name)
    {
        double total = 0;
        if(onCampus(name))
        {
            total = calculateTotal(estimatedLivingExpenses(), 
                    booksAndSupplies(), creditHours(), costPerCredit());            
        }
        else
        {
            total = calculateTotal(booksAndSupplies(), creditHours(), 
                    costPerCredit());    
        }
        String year = getYear();
        if(year.equalsIgnoreCase("other"))
           System.out.printf("The total cost for "+name+" is $%7.2f", total); 
        else
            System.out.printf("The total cost for "+name+" as a "+year+
                    " is $%7.2f", total);
        System.out.println();
    }
	
    public static boolean onCampus(String name)
    {
        boolean invalidResponse = true;
        do{
        System.out.println("Is "+name+ " living on campus? (yes/no)");
        String response = in.nextLine();
        if(response.equalsIgnoreCase("yes"))
            return true;
        else if (response.equalsIgnoreCase("no"))
            return false;
        else
            System.out.println("Invalid response.");
        } while(invalidResponse);
        return false;
    }
    public static double estimatedLivingExpenses()
    {
        double total = 0;
        try{
        System.out.println("How many weeks will the student live on campus? ");
        String value = in.nextLine();
        int weeks = Integer.parseInt(value);
        System.out.println("What is the estimated weekly living expenses?");
        value = in.nextLine();
        double weeklyExpenses = Double.parseDouble(value);
        System.out.println("What is the room and board for the year?");
        value = in.nextLine();
        double roomBoard = Double.parseDouble(value);
        total = weeks * weeklyExpenses + roomBoard;
        }
        catch(Exception e)
        {
            System.out.println("Invalid data type.");
            e.printStackTrace();
        }
        finally
        {
            return total;
        }
    }
    public static double booksAndSupplies()
    {
        System.out.println("What is the estimated cost of "
                + "textbooks and supplies? ");
        double cost = in.nextDouble();
        return cost;
    }
    public static int creditHours()
    {
        System.out.println("How many credit hours is the student planning "
                + "to take? ");
        int hours = in.nextInt();
        return hours;
    }
    public static double costPerCredit()
    {
        System.out.println("What is the cost per credit hour? ");
        double costCredit = in.nextDouble();
        in.nextLine();
        return costCredit;
    }
   
    public static double calculateTotal(double livingExpenses, double books,
            int credit, double cost)
    {
        return livingExpenses + books + (credit*cost);
          
    }
     public static double calculateTotal(double books, int credit, double cost)
    {
        return books + (credit*cost);
          
    }
	public static String getYear()
    {
        System.out.println("What year is the student(Freshman, Sophomore, "
                + "Junior, Senior, Other)?");
        String yearName = in.nextLine();
        return yearName;
    }
    
}
