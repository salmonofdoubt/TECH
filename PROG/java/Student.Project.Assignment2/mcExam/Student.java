/*mcExam.Student

--Assignment 1b--
File:		Student.java
Author:		André Baumann
Description: The class Student manages exam details about a single student

ExamManage:	readFile() gets the filename
			it then calls readData() in TheClass to read in data
			it now displayes number of reocords read
myClass:	readData() reads the records from file
			it then populates the student array in myClass
Student:	readData() reads a single record from file
*/

package mcExam;			//part of that package which is imported into ExamManage

import java.io.*;
import java.util.*;
import corejava.*;

public class Student {


	private String stuNumb;		//Student No
	private String lastName;	//Student last Name
	private String firstName;	//Student first Name
	private double result;		//Students results
	private int rank;			//Students rank in class
	private int[]answers;		//Students answers to MCQ

	//access, mutation methods
	//Get Student number. Returns: Student number as a string.
	public String getStuNumb()	{return stuNumb;}

	//Get Student last name.Returns: Student Last name as a string.
	public String getLastName()	{return lastName;}

	//Get Student first name.Returns: Student first name as a string.
	public String getFirstName(){return firstName;}

	//Get Student result.Returns: Student result as an integer.
	public double getResult()	{return result;}

	//Get Student rank. Returns: Student rank as an integer.
	public int getRank()		{return rank;}

	//Get Student answers to MCQs. Returns:Student answers as an integer array.
	public int[] getAnswers()	{return answers;}

	//Set Student number. Parameters: sn - Student Number.
	public void setStuNumb(String sn)	{stuNumb = sn;}

	//Set Student Last name. Parameters: ln - Student Last Name.
	public void setLastName(String ln)	{lastName = ln;}

	//Set Student First name. Parameters: fn - Student First Name.
	public void setFirstName(String fn)	{firstName = fn;}

	//Set Student result. Parameters: rr - Student result.
	public void setResult(int rr)	{result = rr; }

	//Set Student rank Parameters: rk - Student rank.
	public void setRank(int rk)		{rank = rk; }

	//Represents Student object in String format.Returns: Student details as a String
	public String toString() { }


	//writes single record to file
	public void writeData(PrintWriter out) throws IOException {
		out.println(stuNumb+ "|" +lastName+ "|" +firstName+ "|"
		+calculateResult.getResult() + "|"
		+compareTo.getRank());
	}


	// reads single record from file
	public void readData(BufferedReader in) throws EOFException, IOException, InvalidRecordException {
		String St = in.readLine();	//Represents Student object in String format as St
		boolean found = false;
			if (answers == answers.length[20]) found = true;
			else if (found = false) throw new InvalidRecordException();

		StringTokenizer t = new StringTokenizer(St, "|");
		stuNumb  = t.nextToken();
		lastName = t.nextToken();
		firstName = t.nextToken();
		int mcq1 = Integer.parseInt(t.nextToken());
		int mcq2 = Integer.parseInt(t.nextToken());
		int mcq3 = Integer.parseInt(t.nextToken());
		int mcq4 = Integer.parseInt(t.nextToken());
		int mcq5 = Integer.parseInt(t.nextToken());
		int mcq6 = Integer.parseInt(t.nextToken());
		int mcq7 = Integer.parseInt(t.nextToken());
		int mcq8 = Integer.parseInt(t.nextToken());
		int mcq9 = Integer.parseInt(t.nextToken());
		int mcq10 = Integer.parseInt(t.nextToken());
		int mcq11 = Integer.parseInt(t.nextToken());
		int mcq12 = Integer.parseInt(t.nextToken());
		int mcq13 = Integer.parseInt(t.nextToken());
		int mcq14 = Integer.parseInt(t.nextToken());
		int mcq15 = Integer.parseInt(t.nextToken());
		int mcq16 = Integer.parseInt(t.nextToken());
		int mcq17 = Integer.parseInt(t.nextToken());
		int mcq18 = Integer.parseInt(t.nextToken());
		int mcq19 = Integer.parseInt(t.nextToken());
		int mcq20 = Integer.parseInt(t.nextToken());
		int answers[] = {mcq1, mcq2, mcq3, mcq4, mcq5, mcq6, mcq7, mcq8, mcq9,
						mcq10, mcq11, mcq12, mcq13, mcq14, mcq15, mcq16, mcq17,
						mcq18, mcq19, mcq20};

		}
	//Calculates the exam result for student
	public void calculateResult() {

		int correct[] = {5,4,2,1,4,4,2,5,4,5,5,3,3,5,4,3,1,1,1,5}; //Dirk Gently's correct
		double overall;			//achieved points
		int i_ans, i_corr;		//array counters
			for ( i_corr = 1; i_corr < correct.length; i_corr++){
				for (i_ans = 1; i_ans <answers.length; i_ans++){
					if (i_ans = 0) overall = overall + 0;		//if answer is "0"
					if (i_ans = i_corr) overall =+ overall;				//if answer is correct
					else {
						if (i_ans != i_corr) overall = overall - 0.25;	//if answer is elsewise
					}	//end else - if
				}		//end for i_ans
			}			//end for i_corr
		//final overall rounded up to next whole number
		result = Math.ceil(overall);
		//Would need an array of student results
		St[i] = calculateResult(answers); // an extra class maybe?
	}	//end calculateResult
}		//end Student



