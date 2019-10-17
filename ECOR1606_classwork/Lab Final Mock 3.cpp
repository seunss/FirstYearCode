// Lab final example #3
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

double computePressure (double hubDiameter, double interferance, double thickness) {
	double const E = 207e9;
	double const v = 0.28;
	double p, b, x, c;
	b = (hubDiameter/2);
	c = (b + thickness);
	x = ((((c*c) + (b*b))/((c*c) - (b*b))) + v);
	p = (interferance/b)/(((1/E)*x) + ((1/E)*(1-v)));
	
	return p;
}

int main (void) {
	double answer, bestAnswer, interferance, hubDiameter;
	double thickness;
	double bestThickness = 0;
	double a;
	for (;;) {
		
		cout << "Enter hub diameter and interference: ";
		cin >> hubDiameter >> interferance;
		thickness = 0.06;
		a = 0;
		
		if ((hubDiameter == 0)&&(interferance == 0)) {
			break;
		}
		else if ((hubDiameter >= 0.5)&&(hubDiameter <= 2.5)&&(interferance > 0)&&(interferance < 0.05*hubDiameter)) {
			cout << setiosflags(ios::fixed | ios::showpoint);
			cout << "Thickness (cm)" << " " << "Pressure (MPa)" << endl;
			cout << "----------------------------" << endl;
		

			while (thickness < 0.125) {
				answer = (computePressure (hubDiameter, interferance, thickness));
				answer = answer / 1e6;
				cout << setw(8) << setprecision(1) << thickness*100 << setw(15) << setprecision(4) << answer << endl;
		
				if ((thickness == 0.06)||((fabs(20-answer) < 5)&&(fabs(20-answer)< bestAnswer))) {
					bestAnswer = answer;
					bestThickness = thickness;
				}
			answer = computePressure (hubDiameter, interferance, thickness);
			thickness += 0.005;
			}
		}
		else {
			cout << "Invalid values ignored. " << endl << endl;
		}
		a = fabs(20 - bestAnswer);
		if (a < 5) {
		cout << "A tire thickness of " << setprecision(1) << bestThickness*100 << " cm comes closest to giving a pressure of 20 MPa." << endl << endl;
		}
		else if ((thickness = 0.12)&&(a >= 5)) {
			cout << "All of the tire thicknesses are unnacceptable." << endl << endl;
		}
	}
	
	system("PAUSE"); return 0;
}

