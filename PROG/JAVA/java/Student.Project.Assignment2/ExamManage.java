/*ExamManage
--Assignment 1b--
File:		ExamManage.java
Author:		Andre Baumann
Description: Provides user interface, which is responsible for displaying student
			details and read/write from/to file. Represents the user interface for
			processing the exam results @Brenda Ryan

ExamManage:	readFile() gets the filename
			it then calls readData() in TheClass to read in data	DONE
			it now displayes number of records read
myClass:	readData() reads the records from file
			it then populates the student array in myClass		DONE
Student:	readData() reads a single record from file 			DONE
*/

import java.io.*;
import java.util.*; //necessary to implement the comparable interface in Student.class
import mcExam.*;	//package containing Student, TheClass, Exceptions)

public class ExamManage {

	private BufferedReader reader;	//for reading input from System.in
	private myClass TheClass;		//myClass holds an array of Student objects

	//Default constructor which sets up myClass which can hold 10 Students
	public ExamManage(){

		// initialise the instance variables
		//myClass = new TheClass();
		// sit and wait for input
		reader = new BufferedReader(new InputStreamReader(System.in));
		//then displays the main menu.
		menu();
	}

/*Loop which presents the user with a menu, waits for input.
The appropriate method is executed.
Any exceptions that occur are handled before going back to the beginning
and displaying the menu again.
Continues until 'q' to quit.
Is invoked by the default constructor.
*/
	private void menu(){

		char choice = '\0';
		do {
			System.out.print("s - Info single, a - Info all" +
			"\n r - Read Student file, w - Write Student file" +
			"\n q - Quit --> ");

			try {
				choice = (char)reader.read();	//read a single character of input
				reader.readLine();				//skip the rest of line

					switch (choice) {
						case 'S':
						case 's': infoSingle();	//definded
						break;

						case 'A':
						case 'a': infoAll();	//definded
						break;

						case 'R':
						case 'r': readFile();	//definded
						break;

						case 'W':
						case 'w': writeFile();	//definded
						break;

						case 'Q':
						case 'q':	//TBD: WHAT HAPPENS HERE?
						break;

						default: System.out.println("\nUnrecognised option.");
						}
					}
/* The following Exceptions are to be caught here:
- NumberFormatException exception:
 method requires numerical input, the parseInt method will throw that exception.
-NotFoundException:
 thrown if an invalid Student number is given.
-FileFormatException:
 If the format of file is invalid in any way
-FileNotFoundException:
 If filename itself is not valid
-IOException:
 In the unlikey event of an IOException when reading in values from the user */

			catch (NumberFormatException exception) {	//java native
				System.err.println("\n'" + exception.getMessage()
				+ "': Requires numerical input.\nPlease try again.");
			}
			catch (NotFoundException exception) {		//provided in extra class
				System.err.println("\n'" + exception.getMessage()
				+ "': Invalid Student number is given.\nPlease try again.");
			}
			catch (FileFormatException exception) {		//provided in extra class
				System.err.println("\n'" + exception.getMessage()
				+ "': Requires numerical input.\nPlease try again.");
			}
			catch (FileNotFoundException exception) {	//java native
				System.err.println("\n'" + exception.getMessage()
				+ "': File not found.\nPlease try again.");
			}
			catch (IOException exception) {				//java native
				System.err.println("\n'" + exception.getMessage()
				+ "': Error reading values.\nPlease try again.");
			}
		}
		while (choice != 'q' && choice != 'Q');
	}

/* Request an student number from the user, attempt to retrieve the Student,
and print its details. All exceptions are thrown on to caller.
-NumberFormatException if format of student number is invalid
-NotFoundException if student number cannot be located in array
-IOException if error on reading in values from user */
	private void infoSingle() throws NumberFormatException, NotFoundException,
	IOException {
		// Get student number from user and call method to retrieve student details:
		Student student = TheClass.getStudent( sn );
		//TBD: see TheClass maybe?
		//Output results
		}

	// Add in method for infoAll()	TBD
	private void infoAll() {

	}
	//writeFile()
	private static void writeFile() {
		String Student;
		try {
			PrintWriter out = new PrintWriter(new FileWriter("results.dat"));
			writeData(Student, out);
			out.close();			//closes the newly written file with
									//certain memory location
		}							//end try
		catch(IOException e) {
			System.out.print("Error: " + e);
			System.exit(1);
		}	//end catch IO
	}		//end writeFile()

	//readFile()
	private static void readFile() {
			try {
			BufferedReader in = new BufferedReader(new FileReader("exam.dat"));
			Student [] St = readData(in);
			for (int i = 0; i < St.length; i++) {
				St[i].print();
				in.close();			//closes the read-in file
			}				 		//end for loop
		}			//end try
		catch(IOException e) {
			System.out.print("Error: " + e);
			System.exit(1);
		}		//end catch
	}			//end readFile()

// main creates new instance of ExamManage. Constructor calls menu() which continue
//to loop and accept input until user chooses quit (the main method exits) */
	public static void main(String[] args) { new ExamManage();}
}//end class ExamManage
