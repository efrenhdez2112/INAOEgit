#include <iostream>
#include <math.h>
#include <vector>
#include <complex>
#include <Eigen/Dense> //Libreria usada para la multiplicacion de matrices

using namespace Eigen;
using namespace std;

void get_ki(int n, long double V[], long double me[], long double Eq, complex <long double> *ki)
{
    complex <long double> res1;
    complex <long double> res2;
    complex <long double> im ( 0 , 1 );	
    long double hbar=1.0545718176461565e-34;


	for(int j=0; j<n; j++)
    {
          if (Eq>V[j])
          {
               res1=2*me[j]*(Eq-V[j]);
	           ki[j] = (((sqrt(res1))/hbar));
          } 
          else if (Eq<V[j])
          {
               res2=2*me[j]*(V[j]-Eq);        
               ki[j]=((im*(sqrt(res2)))/hbar);
          }
          cout<<"< V= "<<V[j]<<" , "<<"m_eff = "<<me[j]<<" , "<<"E = "<<Eq<<" >"<<endl;
          cout<<"k"<<j+1<<"= "<<ki[j]<<"\n";
    }
}

Matrix <complex <long double>,2,2> * Trans_Mat(int n, complex <long double> *k, long double zetas[], long double me[])   
{	
    complex <long double> *kt;    
    complex <long double> T11;
    complex <long double> T12;
    complex <long double> T21;
    complex <long double> T22; 
    Matrix <complex<long double>,2,2> *mt;
    Matrix <complex<long double>,2,2> mr=*mt;
      mr(0,0)=(1,1);
      mr(1,0)=(1,1);
      mr(0,1)=(1,1);
      mr(1,1)=(1,1); 
    complex <long double> two (2 , 0);
    complex <long double> im ( 0 , 1 );	
    complex <long double> ex;
    complex <long double> exp_p;
    complex <long double> exp_n;
    
       for(int j=0; j<n; j++)
       {
       	 *kt=(k[j]/me[j]);
       	 *kt++;
	   }
	   
       for (int j=0; j<n-1; j++)
       {
	     ex = im*k[j]*(zetas[j+1]-zetas[j]);
	     exp_p= exp(ex);
	     exp_n= exp(-ex);
	      T11 = ((kt[j+1]+kt[j])/(two*kt[j+1]))*exp_p;
	      T12 = ((kt[j+1]-kt[j])/(two*kt[j+1]))*exp_n;
	      T21 = ((kt[j+1]-kt[j])/(two*kt[j+1]))*exp_p;
	      T22 = ((kt[j+1]+kt[j])/(two*kt[j+1]))*exp_n;
             mr(0,0)=T11;
             mr(1,0)=T21;
             mr(0,1)=T12;
             mr(1,1)=T22;
	     cout<<"\nMatriz "<<j+1<<" = "<<endl<<endl;
	     cout<<*mt;
       }
    return mt;   
}
/////////////////////////////////////////////////////////////////////////

int main ()
{	
    //Constantes
	const long double q=1.602176634e-19;
	const long double m_e=9.1093837015e-31;
	const long double hbar=1.0545718176461565e-34;
	const long double nm=1e-9;
	complex <long double> im ( 0 , 1 );	
	
	int n; 
	cout<<"Ecuacion de Schrodinger."<<endl;
	cout<<"Ingrese el numero de potenciales a analizar: ";
	cin>>n;
	
	float E;
	cout<<"Ingrese la energia en eV: ";
	cin>>E;
	long double Eq=E*q;
	
	long double v[n];
	long double V[n];
	
	 for (int j=0; j<n; j++)
	 {
		cout<<"Ingrese el valor del potencial #"<<j+1<<" en eV: ";
		cin>>v[j];
		V[j]=v[j]*q;
	 } 
	
	long double masa[n];
	long double me[n];
	
	 for (int j=0; j<n; j++)
	 {
		cout<<"Ingrese el valor de la masa efectiva #"<<j+1<<": ";
		cin>>masa[j];
		me[j]=masa[j]*m_e;
	 }
	
	long double z[n];
	long double zetas[n];
	
	 for (int j=0; j<n; j++)
	 {
		cout<<"Ingrese el valor del tamano de la z #"<<j+1<<" en nm: ";
		cin>>z[j];
		zetas[j]=z[j]*nm;
	 }
	 
//	  complex <long double> ki[4];
	  complex <long double> *ki = new complex <long double>[4];

      get_ki(n,V,me,Eq,ki);
      delete [] ki; 

      Matrix <complex <long double>,2,2> *m_t;
      
        m_t = Trans_Mat(n,ki,zetas,me);


    return 0;
}
