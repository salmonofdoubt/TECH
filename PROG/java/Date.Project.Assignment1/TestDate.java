/*
	File 	TestDate.java
	Author	André Baumann
	--Assignment 1a--

	Description:
	-Tests the Date.class
	-Provides valid input
*/



import java.io.*;
import corejava.*;


public class TestDate
{
	public static void main(String args[]) throws IOException
	{

		int day, month, year;

		int leapyear = 0;
		int weekday, sfx;

		boolean valid = true;
		boolean menuvalid = true;
		boolean loop = true;

		Date doom;
		Date endofyear;
		Date cal;

		String longformat;

		char op, go;

		do
		{
			System.out.println("\n============= START =======================================");

			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


/**
 *Start of Data input: 3 do - while loops for year, month and day and
 *validate that date
 */

//check year

			do
			{
				valid = true;
				year = Console.readInt("\nEnter year 'YYYY' >");

        		if (year < 1582)
					System.out.println("\n  !Invalid year! Year should be >= 1582.");

	    	   else valid = false;
			}

			while (valid);

//check leapyear

			if (year%4 == 0)
				{
					if (year%100 == 0)
						{
							if (year%400 ==0) leapyear = 1;
							else leapyear = 0;
	    		        }
	    	        else leapyear = 1;

	    	      }
			System.out.println("help:leapyear " +leapyear);


        	do
        	{	valid = true;

//check month

        	month = Console.readInt("\nEnter month 'MM'   >");
   				if (month <= 0 || month > 12)
				System.out.println("\n  !Invalid month! Month can be 1..12.");

				else valid = false;
			}
			while (valid);

//check day

			do
			{	valid = true;

				day = Console.readInt("\nEnter day 'DD'     >");

				if (day < 1 || day > 31 || (day > 30 && month == 4) || (day > 30 && month == 6) || (day > 30 && month == 9) || (day > 30 && month == 11))

					System.out.println("\n!  Invalid number of days!");

				else if (day > 28 && month == 2)
					{
					if ((leapyear == 0 && day > 28) || (leapyear == 1 && day > 29))
					System.out.println("\n!  Impossible date in February!");
					else valid = false;
					}

				else valid = false;
			}
			while (valid);

			System.out.println("\n---Valid---");

//end of validation


/**
 *Creates a new instance on the object, based on validation process
 */

			doom = new Date();
			doom.setDay(day);
			doom.setMonth(month);
			doom.setYear(year);


/**
 *Program now presents a menu, its options are called through a switch
 */

			do
			{
				String menu = Console.readLine("\n\n============= MENU ========================================\n\n1. Show the given date in extended Format\n2. Show date after a given date\n3. Find number of days left in a year\n4. Show the calender for a month\n5. Quit\n");

				op = menu.charAt(0);

				switch (op)
				{

					case '1':

//calculates weekday calling Zeller method
					weekday = doom.Zeller();

//calculates the daysuffix calling Suffix
					sfx = doom.Suffix();

//System.out.println("help:weekday " +weekday);
					System.out.println("\nDate in extended Format :\n");

//calls the toString method on instance doom and returns result:
					longformat = doom.toString();

// print the date in long format calling the toString method
					System.out.println(longformat.toString());

				break;

				case '2':

//puts doom through Tomorrow to add one day
					doom.Tomorrow();

					weekday = doom.Zeller();
					sfx = doom.Suffix();

//calls the toString method with this instance
					System.out.println("\nThe following day is :\n");
					longformat = doom.toString();
					System.out.println(longformat.toString());

				break;

				case '3':

// calling daysUntil method to calculate days between

					endofyear = new Date();
					endofyear.setDay(31);
					endofyear.setMonth(12);
					endofyear.setYear(2004);

					int diffday = doom.daysUntil();
					//doom.daysUntil(endofyear);

					System.out.println("\nFrom the given date until 31-12 of that year there are "+diffday+" days left\n\n");

				break;

				case '4':


// create a Calendar

					cal = new Date();
					cal.setDay(1);
					cal.setMonth(month);
					cal.setYear(year);

//calculates weekday 1 of the month calling Zeller()
					weekday = cal.Zeller();


					String[] Mon = {"January","February","March","April","May","June","July","August","September","October","November","December"};

// print the Calendar Header
					System.out.println("\n\n========= CALENDAR VIEW ====================================\n");
					System.out.println(" "+Mon[month-1]+" "+year+"\n");
					System.out.println("\tSun \tMon \tTue \tWed \tThu \tFri \tSat");

					int [] mlenght = {31,28,31,30,31,30,31,31,30,31,30,31};
					int days_month = mlenght[month-1];

// Counters, with i_day to 1 which is first day of the given month
					int i_day = 1;
					int i_horizontal;
					int i_vertical;

// Count downwards (needs possibly 5 rows)
					for(i_vertical = 0; i_vertical < 6; i_vertical++)
					{
// Also count sidewards (7 weekdays)
						for (i_horizontal = 0; i_horizontal < 7; i_horizontal++)
						{

							if ((i_horizontal < weekday) & (i_vertical == 0))

								System.out.print("\t");

							else
							{
								if (i_day <= days_month)
									{
//print what is calculated so far
										System.out.print("\t"+i_day);
										i_day++;
									}
							} 	//close else

						}		//close horizontal count

//continues print in a new line
						System.out.println();

					}			//close vertical count

					System.out.println("\n===========================================================");

				break;

				case '5':
					String again = Console.readLine("Sure? y/n");
					go = again.charAt(0);
					if (go == 'y' || go == 'Y')
					{
						loop = false;
						System.exit(0);
					}
				break;

				default:
					System.out.println("\nInvalid comand\n");

				}				//end switch

			} while (op != 5);	//display menu until 5 was entered

		} while(loop); 			//end of do while loop



	} 			//ends main

} 				//end testdate


