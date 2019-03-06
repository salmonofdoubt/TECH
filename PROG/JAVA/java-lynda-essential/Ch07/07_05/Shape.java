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
      
    public Shape()
    {
        shapeName = "generic shape";
    }
    public Shape(String shapeName)
    {
        this.shapeName = shapeName;
        area = 0;        
    }
    public Shape(String name, double area)
    {
        this.shapeName = name;
        this.area = area;
    }
    public String getShapeName()
    {
        return shapeName;
    }
    public abstract double calculateArea();
    
}
