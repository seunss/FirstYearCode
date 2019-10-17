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


double partial_sum(double a, double r, int k){
	if (k == 0) {
		return a;
	}
	else {
		return pow(r,k) * a + partial_sum(a,r,k-1);
	}
}

int main (void) {

    // INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE

    // INSERT YOUR STATEMENTS HERE
    double  y = 4;
 double  x= 2;
 int k= 2;
  
double  sum = partial_sum(4,2,2);
cout << sum;

    system("PAUSE"); return 0;

}
