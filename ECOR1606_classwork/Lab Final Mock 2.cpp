// Lab final example #2
//
// Name:  Mihailo Krstic
// Student Number: 101036979

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

double computeSolidity (double beta1, double beta2, double incidence) {
	double answer; 
	double sigma = 0.6;
	double lowAns, lowSigma;
	
	cout << setiosflags(ios::fixed | ios::showpoint);
	cout << "Solidity" << "                 " << "LHS Value" << endl;
	cout << "----------------------------------" << endl;
	
	while (sigma < 2.2) {
		answer = (33.5291 + (0.469188 + (0.0020961*beta2))*beta2 - beta1) + (((0.187148*beta2)-15.2599)*log(1/sigma)) - (0.677212*(pow(log(1/sigma),2)));
		cout << setw(8) << setprecision(1) << sigma << setw(15) << setprecision(4) << answer << endl;
		
		if ((sigma == 0.6)||(fabs(answer) < fabs(lowAns))) {
			lowAns = answer;
			lowSigma = sigma;
		}
		sigma = 0.1;
	}
	return lowSigma;
}

double computeBladeExitAngle(double a1,double b2,double sigma) {
	double a2, top, bottom;
	
	top = b2 - a1*(0.23 + (b2/500))*pow((1/sigma),0.5);
	bottom = 1 - (0.23 + b2/500)*pow((1/sigma),0.5);
	a2 = top / bottom;
	
	return a2;
}

int main (void) {

	double error, bestValue, finalAnswer, a1, b1, b2, inc;

	for (;;) {
		cout << "Enter flow entry angle, flow exit angle, and incidence: ";
		cin >> b1 >> b2 >> inc;
		a1 = b1 - inc;
		error = (36 - 0.45*b2)/(b1 - b2);
	
		if ((b1 == -1)&&(b2 == -1)&&(inc == -1)) {
			break;
		}
		else if ((b2 < -10)||(b2 > 50)||(inc < -3)||(inc > 3)||(error < 0.75)||(error > 1.25)) {
			cout << "Invalid values ignored" << endl;
		}
		else {
			bestValue = computeSolidity (b1, b2, inc);
			finalAnswer	= computeBladeExitAngle (a1, b2, bestValue);
			cout << "Leaving function. The chosen value is " << setprecision(1) << bestValue << endl << endl;
			cout << "Blade entry angle: " << setprecision(1) << a1 << endl;
			cout << "Solidity: " << setprecision(1) << bestValue << endl;
			cout << "Blade exit angle: " << finalAnswer << endl << endl;
		}
	}

	
	system("PAUSE"); return 0;
}

