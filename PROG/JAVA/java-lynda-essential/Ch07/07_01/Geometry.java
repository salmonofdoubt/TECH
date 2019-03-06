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
        Shape coin = new Circle("Coin");
        System.out.println("The area for the coin is: "+ coin.calculateArea());
        Shape square = new Rectangle();
        System.out.println("The area of the square is: "+square.calculateArea());
        Shape triangle = new Triangle("Pyramid");
        System.out.println("The area of the pyramid is "+triangle.calculateArea());
    }
    
}
