/*mcExam.InvalidRecordException

--Assignment 1b--
File: 		InvalidRecordException.java
Author:		André Baumann
Description: Defines exceptions that may occur in classes other than thrown
			by native java*/

package mcExam;		//part of that package which is imported into ExamManage


//Number of tokens is invalid/malformed
public class InvalidRecordException extends Exception {

	public InvalidRecordException (String s)	{

		super("Number of tokens is invalid/malformed" +s );

	}	//end IRE ()
}		//end IRE class

