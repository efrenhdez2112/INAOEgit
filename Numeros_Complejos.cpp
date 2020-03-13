#include <iostream>
#include <math.h>
#include <complex>
using namespace std;

int main()
{
cout<<"Numeros complejos.\n";

const double pi = 3.14159265358979323846;

complex <double> c1 ( 0 , pi/6 );
cout << "Complex number c1 = " << c1 << endl;

complex <double> r1 = exp ( c1 );
cout << "exp ( c1 ) = " << r1 << endl;
//
complex <double> c2 ( 2 , pi/3 );
cout << "Complex number c2 = " << c2 << endl;

complex <double> r2 = exp ( c2 );
cout << "exp ( c2 ) = " << r2 << endl;
//
complex <double> c3 ( 3 , 4 );
complex <double> c4 ( 3 , -4 );

cout << "Complex number c3 = " << c3 << endl;
cout << "Complex number c4 = " << c4 << endl;

complex <double> r3 = c3*c4;
complex <double> r4 = sqrt(r3);
cout<<"sqrt(c3*c4) = "<< r4 << endl;

complex <double> c5 ( -9 , 0 );
cout << "Complex number c5 = " << c5 << endl;

complex <double> r5 = sqrt ( c5 );
cout << "sqrt ( c5 ) = " << r5 << endl;

	return 0;
}
