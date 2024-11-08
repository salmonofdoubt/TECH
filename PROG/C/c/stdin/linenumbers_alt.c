/*
 * This program was created by Denis Meyer (http://www.calltopower.de/blog/)
 */
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char* const argv[]) {
        if ( argc < 1 )
        {
                cout << endl << "Usage programname filename" << endl << endl;
                return 1;
        }
        else if ( argc != 2 )
        {
                cout << endl << "Usage: " << argv[0] << " filename" << endl << endl;
                return 1;
        }
    
    ifstream file(argv[1]);
    if(!file.is_open()) {
        cout << endl << "Couldn't open File " << argv[1] << endl << endl;
        return 1;
    }
    
    long begin, end;
    
    begin = file.tellg();
    file.seekg (0, ios::end);
    end = file.tellg();
    
    file.close();
    
    cout << endl << "The Size of the File '" << argv[1] << "' is: " << (end-begin) << " Byte." << endl << endl;
    
    return 0;
}
