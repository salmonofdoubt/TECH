/*
 * The shape is class is the superclass
 */
package geometry;

/**
 *
 * @author Peggy Fisher
 */
public abstract class Shape {
    private String shapeName;
    private double area;
    private double perimeter;
    
    public Shape()
    {
        
    }
    public Shape(String shapeName)
    {
        this.shapeName = shapeName;
        area = 0;
        perimeter = 0;        
    }
    public Shape(String name, double area)
    {
        
    }
    public abstract double calculateArea();
    
}
