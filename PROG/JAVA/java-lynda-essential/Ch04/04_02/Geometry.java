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
        Shape orange = new Circle("Orange");
        double area = orange.calculateArea();
        System.out.println("The area for the orange is: "+ area);
        Shape square = new Rectangle("Square");
        double area2 = square.calculateArea();
        System.out.println("The area of the square is: "+area2);
    }
    
}
