/*mcExam.InterfaceStudent

--Assignment 1b--
File:		mcExam.InterfaceStudent
Author:		André Baumann
Description: This class to test the Student class.
			Sorts an array of Student objects.
			Implements the Comparable interface.
			uses the toString method.*/

package mcExam;

import java.io.*;		// for BufferedReader
import java.util.*;

public class InterfaceStudent {
	public static void main(String[] args) throws IOException {
		int i;
		// create Student array reference and array object
		Student[] staff = new Student[10];
		for (i = 0; i < staff.length; i++)
			System.out.println( staff[i]);

		Arrays.sort(staff);	// sort the array of Student objects
		System.out.println( "\n\n");

		for (i = 0; i < staff.length; i++)
			System.out.println( staff[i]); // Print each Student object

   }	// end of main()
}		// end of class InterfaceStudent

class Student implements Comparable {

	public Student(String St, double n ) {
		Student = St;
		result = n;
	}

	public Student() { }	// default constructor

	public void print() {
		System.out.println(Student + " " + result);
	}

	public String toString()
	{
		return Student + "\t" + result;
	}

//Calculates rank of student in class based on result
	public int compareTo(Object other) {	//rank value is updated in Student array
		Student St = (Student)other;
		int comp = Student.compareTo(St.Student);
		return (comp!=0 ? comp : result.compareTo(St.result));
	} 	//end compareTo()

   	// accessor methods
	public double getResult() {return result;}

   	public String getStudent() {return Student;}

	private String Student;
	private double result;
}
