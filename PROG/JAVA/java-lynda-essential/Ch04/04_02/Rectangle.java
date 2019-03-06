package geometry;
import java.util.*;
/**
 *
 * @author Peggy Fisher
 */
public class Rectangle extends Shape{
    Scanner in = new Scanner(System.in);
    public Rectangle(String name)
    {
        super("Rectangle");
    }
    public double calculateArea()
    {
        System.out.println("Enter the length and width of the rectangle: ");
        double length = in.nextDouble();
        double width = in.nextDouble();
        return length * width;
    }
       
}
