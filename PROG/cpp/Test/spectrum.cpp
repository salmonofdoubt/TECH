//spectrum.cpp
#include <iostream.h>

//Rydbergkonstante für Wasserstoff
const double Rydberg = 3.28805e15;
//Lichtgeschwindigkeit
const double c = 2.99792e8;
//Planksches Wirkungsquantum
const double h = 6.62618e-34;
//Elementarladung 
const double e = 1.60219e-19;

enum Serie 
	{Lyman=1,Balmer,Paschen,Brackett,Pfund};
class spektrum 
	{
		Serie n; //Spektralserie
		int m;   //Niveau
		public:
			spektrum(Serie nn, int mm) {n=nn; m=mm;}
			double frequenz()     //Wellenlaenge in nm
				{return 1e-9*Rydberg*1./(n*n)-1./(m*m)); }
			double wellenlaenge() // Frequenz in GHz
				{return c/frequenz();}
			double energie()       //Energie in Elektronenvolt 
				{return h*1e9*frequenz()/e;}
	};
	
	int main ()
	{
		cout<<"H-alpha-Linie"<< end1;
		spektrum Halpha(Balmer,3);
		