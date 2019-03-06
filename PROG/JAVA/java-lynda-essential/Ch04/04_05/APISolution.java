
package apisolution;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
/**
 *
 * @author Peggy Fisher
 */
public class APISolution {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
    /**
    * create SimpleDateFormat Object to convert the date in particular string format
    */
    DateFormat df = new SimpleDateFormat("MM/dd/yyyy");
    Date dt = new Date();
 
    /**
    * format method is used to convert the date in MM/dd/yyyy format
    */
    System.out.println("Date in MM/dd/yyyy format: "+df.format(dt));
    DateFormat df2 = DateFormat.getDateInstance(DateFormat.LONG, Locale.FRANCE);
    System.out.println("France time: "+df2.format(dt));
       
       
    
    }
}
