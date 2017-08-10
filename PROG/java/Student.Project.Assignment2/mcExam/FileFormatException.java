/*mcExam.FileFormatException

--Assignment 1b--
File: 		FileFormatException.java
Author:		André Baumann
Description: Defines exceptions that may occur in classes other than thrown
			by native java*/

package mcExam;		//part of that package which is imported into ExamManage

//Indicate that the student data file is invalid in some way
public class FileFormatException extends Exception {

	public FileFormatException (String s)	{

		super("The student data file is invalid in some way" +s );
   }	//end FFE()
}		//end FFE class

