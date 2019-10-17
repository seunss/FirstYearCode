// INSERT YOUR PROGRAM COMMENTS HERE
//
// Name:Seun Lawal
// Student Number: 101039762

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { 
	return value * value; 
}

double quadFn( double a, double b, double c){
	
	double det = 0;
	det = sqr(b) - (4*a*c);
	if (det>0) {
		return 1;
	}
	else if (det == 0){
		return 0;
	}
	else 
	return -1;
}


int main (void) {
double ftest;
double a;
double b;
double c;


cout << "Plug in A, b, and C" << endl;
cin >> a >> b >> c;
    ftest = quadFn(a,b,c );
	// INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE

    // INSERT YOUR STATEMENTS HERE
    

    system("PAUSE"); return 0;

}
