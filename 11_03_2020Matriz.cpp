#include <iostream>
#include <math.h>
#include <complex>
#include <vector>
using namespace std;

 int main()
{
//Ejemplo de Matriz de Transferencia
//Zetas
long double zetas[5]={0,6e-9,9e-9,15e-9,0};

// Energias
long double q=1.602176634e-19;
long double V0=0.5*q;
long double potenciales[5]={V0, 0, V0, V0,0};

//Masas Efectivas
long double m_e=9.1093837015e-31;
long double masas[5]={m_e,m_e,m_e,m_e,m_e};

//Energia
long double E=0.25*q;

//Matriz y parametros
const double pi = 3.14159265358979323846;
float An=1;
float Bn=-1;
long double hbar=1.0545718176461565e-34;
long double matriz_in[2][1] = {An,Bn};
complex <long double> i ( 0 , 1 );
complex <long double> k[4];
complex <long double> kt[4];
complex <long double> res1;
complex <long double> res2;
complex <long double> T11;
complex <long double> T12;
complex <long double> T21;
complex <long double> T22;
complex <long double> mt[2][2]={{T11,T12},{T21,T22}};
complex <long double> a (2 , 0);
complex <long double> ex;
complex <long double> exp_p;
complex <long double> exp_n;
complex <long double> ej;

for(int j=0; j<5; j++)
{
    if (E>potenciales[j])
    {
        //cout<<potenciales[j]<<"\n";
        res1=2*masas[j]*(E-potenciales[j]);
        cout<<"res = "<<res1<<"\n";
        //cout<<i<<"\n";
	    k[j]=(sqrt(res1))/hbar;
	    kt[j]=k[j]/masas[j];
	    
    } else if (E<potenciales[j])
    {
        //cout<<potenciales[j]<<"\n";
        res2=2*masas[j]*(potenciales[j]-E);
        cout<<"res = "<<res2<<"\n";
        //cout<<i<<"\n";        
        k[j]=(i*(sqrt(res2)))/hbar;
        kt[j]=k[j]/masas[j];
    }
        cout<<"k"<<j+1<<"= "<<k[j]<<"\n";
        cout<<"kt"<<j+1<<"= "<<kt[j]<<"\n\n";
}
for (int j=0; j<5; j++)
{
	ex = i*k[j]*(zetas[j+1]-zetas[j]);
	exp_p= exp(ex);
	exp_n= exp(-ex);
	T11 = ((kt[j+1]+kt[j])/(a*kt[j+1]))*exp_p;
	T12 = ((kt[j+1]-kt[j])/(a*kt[j+1]))*exp_n;
	T21 = ((kt[j+1]-kt[j])/(a*kt[j+1]))*exp_p;
	T22 = ((kt[j+1]+kt[j])/(a*kt[j+1]))*exp_n;
	cout<<"exp_p = "<<exp_p<<endl;
	cout<<"exp_n = "<<exp_n<<endl<<endl;
	cout<<T11<<" , "<<T12<<"\n";
	cout<<T21<<" , "<<T22<<"\n\n";
}
  return 0;
}
