package payroll;

/**
 *
 * @author Peggy Fisher
 */
public class Address implements Comparable{
    private String houseNumber;
    private String address1;
    private String address2;
    private String city;
    private String state;
    private String zipcode;
    public Address(String houseNum, String address1, String address2,
            String city, String state, String zip)
    {
        houseNumber = houseNum;
        this.address1 = address1;
        this.address2 = address2;
        this.city = city;
        this.state = state;
        this.zipcode = zip;
    }
    public Address(String houseNum, String address1,             
            String city, String state, String zip)
    {
        houseNumber = houseNum;
        this.address1 = address1;
        this.address2 = "";
        this.city = city;
        this.state = state;
        this.zipcode = zip;
    }
  
     public String toString()
    {
        if(address2.equals(""))
        {
            return (houseNumber + " "
                + address1 +"\n" + city + ", "+ state + 
                    " " + zipcode);
        }
        else
        {
            return(houseNumber + " "
                + address1 +"\n" + address2 + "\n" +
                city + ", "+ state + " " + zipcode);
        }
    }
    @Override
    public int compareTo(Object a) {
        //this compareTo method allows the programmer to sort addresses by zip 
        //code
        Address addr = (Address)a;
        int zip1 = Integer.parseInt(this.zipcode);
        int zip2 = Integer.parseInt(addr.zipcode);
        if(zip1 < zip2)
            return -1;
        else if (zip1 > zip2)
            return 1;
        else
            return 0;
    }

}
