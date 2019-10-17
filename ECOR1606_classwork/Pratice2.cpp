// INSERT YOUR PROGRAM COMMENTS HERE
//
// Name:
// Student Number:

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


double computeSolidity (double beta1, double beta2){
double  i;
double leftside;
double solidity;
double minSolid;
double minLeftside;
	cout << setiosflags(ios::fixed | ios::showpoint);
	cout << "Solidity" << "                 " << "LHS Value" << endl;
	cout << "----------------------------------" << endl;
	
	while (solidity < 2.2){
		leftside = 35.5291 +((0.469188 + (0.0020961*beta2))*beta2) - beta1 +(((0.187148*beta2) - 15.2599)*(log((1 /solidity)))) - (0.677212* (log((1 /solidity))) * (log((1 /solidity))));
		cout << setw(8) << setprecision(1) << solidity << setw(15) << setprecision(4) << leftside << endl;
		if (solidity == 0.6 || fabs(leftside) < fabs (minLeftside)) {
		minLeftside = leftside;
		minSolid = solidity;	
		}
		solidity = solidity + 0.1;
	}
	return minSolid;
}

double computeBladeExitAngle(double a1, double b2, double sigma) { 
double top;
double bottom;
double sigmai;
double a2;
double b2500;// Morevarible makes code easir

sigmai = pow((1 / sigma), 0.5);
b2500 = (b2 / 500) + 0.23;
top = b2 - (a1*b2500*sigmai);
bottom = 1 - (b2500*sigmai);
a2 = top / bottom;

return a2;
}

int main (void) {
double b1;
double b2;
double i1;
double i;
double rangeofbs;
 
 for (;;){
 	cout << "Enter values for Beta 1, Beta 2, and Incidence." << endl;
 	cin >> b1 >> b2 >> i1;
 	if (b2 =! b1){
 	rangeofbs = (36 - (0.45 * b2)) / (b1 - b2);
 }
 	if (b1 == -1 && b2 == -1 && i1 == -1){
 		break;
 	}
 	else if (b2 > 50 || b2 < -10 || i1 > 3 || i1 < -3 || (rangeofbs > 1.125) || (rangeofbs < 0.75 )){
 		cout << "Invalid Values, Please try again. " << endl;
 	}
 	
 	else {
 		cout << "Blade entry angle: " << b1 - i1 << endl;
 		cout << "Soldidity: " << computeSolidity (b1, b2) << endl;
 		cout << "Blade exit angle: " << computeBladeExitAngle (b1 - i1, b2, computeSolidity (b1, b2) );
 	}
 }
    // INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE

    // INSERT YOUR STATEMENTS HERE


    system("PAUSE"); return 0;

}
