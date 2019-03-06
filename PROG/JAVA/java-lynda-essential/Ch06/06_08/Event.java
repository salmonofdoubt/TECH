
package kathiescatering;
import java.text.DateFormat;
import java.util.Date;
/**
 *
 * @author Peggy Fisher
 */
public class Event {
    public static int nextEventNumber=100; //start the event number at 100
    private String eventNumber;
    private String eventType;
    private int guests;
    private final double pricePerGuest = 40.00;
    private String eventDate;
    
    public Event(String type)
    {
        eventType = type;
        guests = 0;
        eventDate = null;
        SetEventNumber(eventType);
    }
    public Event (String type, String eventDate)
    {
        eventType = type;
        guests = 0;
        this.eventDate = eventDate;
        SetEventNumber(eventType);
    }
     public Event (String type, String eventDate, int numGuests)
    {
        eventType = type;
        guests = numGuests;
        this.eventDate = eventDate;
        SetEventNumber(eventType);
    }
    public void incrementEventNumber()
    {
        nextEventNumber++;
    }
    public void SetEventNumber(String eventType)
    {
        eventNumber = ""+eventType.charAt(0)+nextEventNumber;
        incrementEventNumber();        
    }
    public String getEventNumber()
    {
        return eventNumber;
    }
    public void setGuest(int value)
    {
        if(value > 100 || value <20){
            System.out.println("Sorry, we can only accommodate 20-100 guests.");}
        else
        { guests = value;}
    }
    public int getGuests()
    {
        return guests;
    }
    public void setEventType(String value)
    {
         eventType = value;
    }
    public String getEventType()
    {
        return eventType;
    }
    public double getTotal()
    {
        return guests*pricePerGuest;
    }
    public void setEventDate(String date)
    {
        eventDate = date;
    }
    public String getEventDate()
    {
        return eventDate;
    }
    public void printEvent()
    {
        System.out.printf("\nYour event is for a %s\nEvent Number: %s"+
                "\nScheduled for: %s\nNumber of guests: %d"
                + "\nTotal cost $%6.2f", eventType, eventNumber, eventDate, 
                + guests, getTotal());
        System.out.println();
       
    }
    
}
