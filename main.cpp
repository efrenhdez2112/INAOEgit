#include <iostream>
#include <math.h>
#include <vector>
#include <complex>
#include <Eigen/Dense> //Libreria usada para la multiplicacion de matrices

using namespace Eigen;
using namespace std;
complex <long double> get_ki(int i, long double V[], long double me[], long double Eq, complex <long double> k[],complex <long double> kt[]);
int main ()
{	
	long double q=1.602176634e-19;
	long double m_e=9.1093837015e-31;
	long double hbar=1.0545718176461565e-34;
	long double nm=1e-9;
	complex <long double> im ( 0 , 1 );	
	int i;
	cout<<"Ecuacion de Schrodinger."<<endl;
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
	
	long double z[i];
	long double zetas[i];
	for (int j=0; j<i; j++)
	{
		cout<<"Ingrese el valor del tamaño de la z #"<<j+1<<" en nm: ";
		cin>>z[j];
		zetas[j]=z[j]*nm;
	}
complex <long double> K[i];
complex <long double> kt[i];
	
      get_ki(i,V,me,Eq,K,kt);
      
complex <long double> T11;
complex <long double> T12;
complex <long double> T21;
complex <long double> T22; 
Matrix <complex<long double>,2,2> mt;
Matrix <complex<long double>,2,2> mr;
mr(0,0)=(1,1);
mr(1,0)=(1,1);
mr(0,1)=(1,1);
mr(1,1)=(1,1);
complex <long double> two (2 , 0);
complex <long double> ex;
complex <long double> exp_p;
complex <long double> exp_n;

for (int j=0; j<i-1; j++)
{
	ex = im*K[j]*(zetas[j+1]-zetas[j]);
	exp_p= exp(ex);
	exp_n= exp(-ex);
	T11 = ((kt[j+1]+kt[j])/(two*kt[j+1]))*exp_p;
	T12 = ((kt[j+1]-kt[j])/(two*kt[j+1]))*exp_n;
	T21 = ((kt[j+1]-kt[j])/(two*kt[j+1]))*exp_p;
	T22 = ((kt[j+1]+kt[j])/(two*kt[j+1]))*exp_n;
    mt(0,0)=T11;
    mt(1,0)=T21;
    mt(0,1)=T12;
    mt(1,1)=T22;
	cout<<"\nMatriz "<<j+1<<" = "<<endl<<endl;
	cout<<mt;
	mr = mr*mt;
}
cout<<"\n´T´ total = "<<endl<<mr<<endl;


    return 0;
}
complex <long double> get_ki(int i, long double V[], long double me[], long double Eq, complex <long double> k[],complex <long double> kt[])
{
complex <long double> res1;
complex <long double> res2;
complex <long double> im ( 0 , 1 );	
long double hbar=1.0545718176461565e-34;

		for(int j=0; j<i; j++)
{
    if (Eq>V[j])
    {
        res1=2*me[j]*(Eq-V[j]);
	    k[j]=(sqrt(res1))/hbar;
	    kt[j]=k[j]/me[j];
	    
    } else if (Eq<V[j])
    {
        res2=2*me[j]*(V[j]-Eq);        
        k[j]=(im*(sqrt(res2)))/hbar;
        kt[j]=k[j]/me[j];
    }
    cout<<"< V= "<<V[j]<<" , "<<"m_eff = "<<me[j]<<" , "<<"E = "<<Eq<<" >"<<endl;
        cout<<"k"<<j+1<<"= "<<k[j]<<"\n";
        cout<<"kt"<<j+1<<"= "<<kt[j]<<"\n\n";
}	
return k;
}

