#include <iostream>
#include <math.h>
#include <vector>
#include <complex>

using namespace std;

int main ()
{	
	long double q=1.602176634e-19;
	long double m_e=9.1093837015e-31;
	long double hbar=1.0545718176461565e-34;
	complex <long double> im ( 0 , 1 );
	int i;
	cout<<"Funcion para determinar las ´k´ de la matriz de transferencia."<<endl;
	cout<<"Ingrese el numero de potenciales a analizar: ";
	cin>>i;
	
	float E;
	cout<<"Ingrese la energia en eV: ";
	cin>>E;
	long double Eq=E*q;
	
	long double v[i];
	long double V[i];
	for (int j=0; j<i; j++)
	{
		cout<<"Ingrese el valor del potencial #"<<j+1<<" en eV: ";
		cin>>v[j];
		V[j]=v[j]*q;
	}
	
	long double masa[i];
	long double me[i];
	for (int j=0; j<i; j++)
	{
		cout<<"Ingrese el valor de la masa efectiva #"<<j+1<<": ";
		cin>>masa[j];
		me[j]=masa[j]*m_e;
	}
    return 0;
	
}
