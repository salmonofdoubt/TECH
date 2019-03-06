package geometry;
/**
 *
 * @author Peggy Fisher
 */
public class Geometry {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Shape frisbee = new Circle("Frisbee");
        System.out.println("The area for the frisbee is: "+ frisbee.calculateArea());
        Shape square = new Rectangle("Square");
        System.out.println("The area of the square is: "+square.calculateArea());
    }
    
}
