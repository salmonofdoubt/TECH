/*
 * Example of recursion
 */
package recursionexample;

/**
 *
 * @author Peggy Fisher
 */
public class RecursionExample {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("The countdown has begun!!");
        countDown(10);
        System.out.println("blastoff");
    }
    public static void countDown(int count)
    {
        if(count == 0)
            return;
       System.out.println(count + "...");
       countDown(count-1);
    }
    
}
