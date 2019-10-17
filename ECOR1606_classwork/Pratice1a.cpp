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

double Si ( double x){
double const A0=2.5253303767;
double const A1=1.0370462484;
double const A2 = 0.5688888889 ;
double const A3 =  0.3111070642;
double const A4 =  0.1242940878 ;
double const T0 =  0.0469100770;
double const T1 =  0.2307653450;
 double const T2 =  0.5000000000;
 double const T3 = 0.7692346550 ;
 double const T4 = 0.9530899230 ;
 
 double ans1;
 ans1 = (A0*sin(x*T0))	+  (A1*sin(x*T1)) + (A2*sin(x*T2)) +  (A3*sin(x*T3)) +  (A4*sin(x*T4)) ; ; ;
 
 return ans1;
}

int main (void) {

    // INSERT YOUR CONSTANT DECLARATIONS HERE
//double const A0=2.5253303767;
//double const A1=1.0370462484;
//double const A2 = 0.5688888889 ;
//double const A3 =  0.3111070642;
//double const A4 =  0.1242940878 ;
//double const T0 =  0.0469100770;
//double const T1 =  0.2307653450;
// double const T2 =  0.5000000000;
// double const T3 = 0.7692346550 ;
// double const T4 = 0.9530899230 ;
 

    // INSERT YOUR VARIABLE DECLARATIONS HERE
double a;
double b;
int  n;
double range;
double i;
double x;
double lgsix,smsix,six;


    // INSERT YOUR STATEMENTS HERE
    
for (;;){
		cout << "Enter in Values for a, b, and N" << endl;
		cin >> a >> b >> n;
		range = (b - a) / (n - 1);
		
		if ((a == 0) && (b == 0) && (n== 0)){
			break;
		}
		if (a <= 0 || b < a || n == 0 ){
			cout << "invalid Values please try again";
		}
		else {

			for (i = 0 ; i< n; ++i) {
				x = a + i*range;
				
				six = Si(x);
					if(n<5){	// output table as needed per N
					cout <<"x = " <<x <<", Si(x) = " << six << endl;
				}

				if(i==0){	// force first values as min and max
					// first min and max
					lgsix = smsix = six;
					
				}
				if(six>lgsix){	// capture a new max
					lgsix = six;
				}
				if(six<smsix){	// capture a new min
					smsix = six;
				}				
			}
			cout << "The Largest Value is " << lgsix << endl;
			cout << "The smallest Value is " << smsix << endl;
			}
	
			
		}
    

    system("PAUSE"); return 0;

}
