package arrayexamples;
import java.lang.*;
import java.util.Arrays;
/**
 *
 * @author Peggy Fisher
 */
public class SampleAPIs {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int[] numbers = {5, 3, 17, 25, 4, 33, 45, 12};
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};
        boolean[] responses = {true, false, false, true, true};
        boolean[] responses2 = {false, true, false, true, true};
        
        System.out.println("Before sorting: "+ Arrays.toString(numbers));
        Arrays.sort(numbers);
        System.out.println("After sorting: "+ Arrays.toString(numbers));
        //sorting works with arrays of type int, double, char, 
        //byte, long, short, object
        
        int key = 25;
        int keyPosition = Arrays.binarySearch(numbers,key);
        //works with arrays of type int, double, char, byte, long, short, object
        System.out.println("Your key was found in position "+keyPosition);
       
        if(Arrays.equals(responses, responses2)==true)
            System.out.println("The two boolean arrays are the same.");
        else
            System.out.println("The two boolean arrays are different");
       //copyof and equals with arrays of type int, double, char, byte, long,
        // short, object, and boolean
        int[] numbers2 = Arrays.copyOf(numbers,numbers.length*2);
             
    }
    
}
