/**
  * File 	Date.java
  *Author	André Baumann
  *	--Assignment 1a--

  *Description:
  *  - Defines class with methods for a Date object.
  *  - Uses constructor methods, methods, get and set methods.
  */

import java.*;

class Date {

//var for day, month, year

	private int d, m, y;
	int weekday;
	int sfx;
	int mth;
	int diff;
	int i;

//default constructors, the Date OBJECT, setting initial value

	public Date(int dd, int mm, int yy) {

		d = dd;
		m = mm;
		y = yy;
	}

	public Date() { d = 0; m = 0; y = 0;}


	public Date(Date date) {

		d = date.d;
		m = date.m;
		y = date.y;
	}


//access, mutation methods

	public int getDay()		 {return d;}
	public int getMonth()	 {return m;}
	public int getYear()	 {return y;}

	public void setDay(int dd)		{d = dd;}
	public void setMonth(int mm)	{m = mm;}
	public void setYear(int yy)		{y = yy;}



/**
  *methods
  */

//Suffix method (OK)

	public int Suffix()	{


		if (d == 1 || d == 21 || d == 31)
			sfx = 0;

		if (d == 2 || d == 22)
			sfx = 1;

		if (d == 3 || d == 23)
			sfx = 2;

		if (d >= 4 && d <=20 || d >= 24 && d <= 30)
			sfx = 3;

		return sfx;

		}	//end Suffix


//Zeller method (OK)

	public int Zeller() {


//no parse necessary
   		weekday = ((int)(y + Math.floor(y / 4) - Math.floor(y / 100) + Math.floor (y / 400) + Math.floor(2.6 * m + 1.6) + d)) % 7;

			return weekday;

		} // end Zeller


//Tomorrow method (OK)
	public void Tomorrow()	{

//if end of a month is reached, adjust dd, mm, yy



			if (m == 2 && d == 28 || m== 2 && d == 29 || m == 1 && d == 31 || m == 3 && d == 31 || m ==  5 && d == 31 || m == 7 && d == 31 || m == 8 && d == 31 || m == 10 && d == 31 || m == 4 && d == 30 || m == 6 && d == 30 || m == 9 && d == 30 || m == 11 && d == 30)

				{
					d = 1;
					m = m + 1;
					y = y;
				}
			else
				{
					d = d + 1;
					m = m;
					y = y;
				}


//if end of year is reached, adjust dd, mm, yy to New Year

			if (m == 12 && d == 31)

				{
					d = 1;
					m = 1;
					y = y + 1;

				}
			return;

		} // end Tomorrow


//toString method (OK)
	public String toString() {

		String[] dayofweek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

		String[] daysuffix = {"st", "nd", "rd", "th"};

		String[] Mon = {"January", "February", "March", "April", "May", "June","July","August","September","October","November","December"};

		String LongFormat = dayofweek[weekday]+", "+d+daysuffix[sfx]+" of "+Mon[m-1]+" "+y+"\n\n";

		return LongFormat;

		} // end toString



//daysUntil method (working on..)
	public int daysUntil()	{

		int c_day = d;
		int c_month, c_year;
		int diff = 0;
		int i_d = 0, i_m = 0;

		int [] mymonth = {31,28,31,30,31,30,31,31,30,31,30,31};

			for (i_m = m-1; i_m < mymonth.length; i_m++) {

					if(i_m > m-1) c_day=1;

					for (i_d = c_day; i_d <= mymonth[i_m]; i_d++) {
						diff++;
					}
				}
		return diff;

		} // end daysUntil

}		 //end class date

