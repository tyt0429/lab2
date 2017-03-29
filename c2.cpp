#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
class Game
{
   public:
	double seta(double a)
	{	
		ra = a;
		return ra;
	}
	double setK(double k)
        {
                K = k;
                return K;
        }

   private:
	double ra,rb,K;
};
int main(){
	Game p1;
	double K,ra,rb,sa,sb,Ea,Eb;
	ifstream inFile("file.in",ios::in);
	if(!inFile){
		cerr << "Failed opening" << endl;
	}
	inFile >> K >> ra >> rb ;
	ofstream outFile("file.out",ios::out);
	outFile << ra << " " << rb << endl;
	while(inFile >> sa )
	{
		sb = 1 - sa;
		Ea = 1 / (1 + pow(10,(rb - ra) / 400 ));
		Eb = 1 / (1 + pow(10,(ra - rb) / 400 ));
		ra = ra + K * ( sa - Ea );
		rb = rb + K * ( sb - Eb );
		
		outFile << (int)(ra+0.5) << " " << (int)(rb+0.5) << endl ;
	}
	return 0;
}
