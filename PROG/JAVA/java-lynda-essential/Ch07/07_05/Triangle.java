package geometry;
import java.util.*;
/**
 *
 * @author Peggy Fisher
 */
public class Triangle extends Shape{
    Scanner in = new Scanner(System.in);
    public Triangle()
    {
        super("Triangle");
    }
    public Triangle(String name)
    {
        super(name);
    }
    public double calculateArea()
    {
        System.out.println("Enter the height and base of the triangle: ");
        double height = in.nextDouble();
        double base = in.nextDouble();
        return .5 * height * base;
    }
       
}
