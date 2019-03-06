/*mcExam.TheClass

--Assignment 1b--
File:		mcExam.TheClass
Author:		André Baumann
Description:This class collects and manipulates details on Students
			already stored in array (created in ExamManage) */

package mcExam;			//part of that package which is imported into ExamManage

import java.io.*;
import java.util.*;
import corejava.*;

public class TheClass {

	//Constructor to set up the class with the default number of students.
	public TheClass(int St, int n, String Student) {;}

	//Constructor to set up the class with the given number of students.
	public Student getStudent(String stuNumb) throws NotFoundException {
		boolean found = false;
		if (studNum == st[i]) found = true;
		return Student;
		if (found == false) {
			throw new NotFoundException ( "\n'" + exception.getMessage() +
				"': Invalid Student number.\nPlease try again.");
			}
		}


	//writeData
	static void writeData(Student[] St, PrintWriter out) throws IOException {
		out.println(St.length);
		int i;
			for (i = 0; i < St.length; i++)
			St[i].writeData(out);
	}	//end of writeData

	//readData
	public Student[] readData(BufferedReader in) throws IOException, FileFormatException {
		int n = Integer.parseInt(in.readLine());
		Student [] st = new Student(n);
		int i;
		for (i = 0; i < n; i++) {
			st[i] = new Student();
			st[i].readData(in);
		}	//end loop
		return st;
	}		//end readData

} //end TheClass
