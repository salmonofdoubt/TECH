
package geometry;
import java.util.*;
/**
 *
 * @author Peggy Fisher
 */
public class Circle extends Shape{
    Scanner in = new Scanner(System.in);
    public Circle()
    {
        super("Circle");
    }
    public Circle(String name)
    {
        super(name);
    }
    public double calculateArea()
    {
        System.out.println("Enter the radius of the circle: ");
        double radius = in.nextDouble();
        return Math.PI*Math.pow(radius, 2);
    }
       
}
