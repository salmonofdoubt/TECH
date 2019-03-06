package payroll;
import java.util.*;
/**
 *
 * @author Peggy Fisher
 */
public class Employee implements Comparable {
    //instance data
    private String firstName;
    private String lastName;
    private String phoneNumber;
    private Address address;
    private int employeeID;
    private int deptID;
    private String title;
    private double salary;
    public Employee(String fname, String lname, String phone, Address address, 
            int employeeID, int deptID, String title, double salary)
    {
        firstName = fname;
        lastName = lname;
        phoneNumber = phone;
        this.address = address;
        this.employeeID = employeeID;
        this.deptID = deptID;
        this.title = title;
        this.salary = salary;
    }
    public String getName()
    {  return firstName + " " + lastName;   }
    public void setFirstName(String value)
    {   firstName = value;    }
    public void setLastName(String value)
    {   lastName = value;    }
    public String getPhone()
    {   return phoneNumber; }
    public void setPhone(String value)
    {   phoneNumber = value;  }
    public Address getAddress()
    {   return address;  }
    public void setAddress(Address address)
    {   this.address = address;  }
    public int getEEID()
    {   return employeeID;  }
    public void setEEID(int value)
    {  employeeID = value;  }
    public int getDeptID()
    {   return deptID;  }
    public void setDeptID(int value)
    {  deptID = value;  }
    public String getTitle()
    {   return title;  }
    public void setTitle(String title)
    {   this.title = title;  }
    public double getSalary()
    {   return salary;  }
    public void setSalary(double value)
    {  if(value <= 10000)
            System.out.println("Error, invalid salary amount, salary was not updated");
        else
            salary = value;  }
    public void printEmployee()
    {
        System.out.println(lastName +", "+firstName+"\nTitle: " + title + 
                "\nAddress: " + address.toString() + "\n\nEmployee ID: " + employeeID + 
                "\nDepartment: "+getDeptName(deptID));
        System.out.printf("Salary: $%8.2f", salary);
        System.out.println();      
    }
    public String getDeptName(int value)
    {
        switch(value)
        {
            case 001: 
                return "Human Resources"; 
            case 002: 
                return "Staff"; 
            case 003: 
                return "Faculty";
            case 004: 
                return "Administration";
            default:
                return "other";
          }
    }

    @Override
    public int compareTo(Object t) {
        Employee emp = (Employee)t;
        if(this.salary>emp.salary)
        {
            return 1;
        }
        else if (this.salary == emp.salary)
        {
            return 0;            
        }
        else
        {
            return -1;
        }
    }
    
}
