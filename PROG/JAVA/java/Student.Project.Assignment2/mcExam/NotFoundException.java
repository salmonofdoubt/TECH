/*mcExam.NotFoundException

--Assignment 1b--
File: 		NotFoundException.java
Author:		André Baumann
Description: Defines exceptions that may occur in classes other than thrown
			by native java*/

package mcExam;		//part of that package which is imported into ExamManage

//Failed attempt to find a student with the specified student number
public class NotFoundException extends Exception {

	public NotFoundException (String s)	{

		super("Failed attempt to find a student with the specified student number" +s );

   }	//end NFE
} 		//end NFE class

