#include <iostream>
#include <math.h>
#include <vector>
#include <complex>

using namespace std;

int main ()
{	
	long double hbar=1.0545718176461565e-34;
	//Ejemplo de Matriz de Transferencia
//Zetas
long double zetas[4]={0,6e-9,9e-9,15e-9,};
int i=4;
// Energias
long double q=1.602176634e-19;
long double V0=0.5*q;
long double V[4]={V0, 0, V0, V0};

//Masas Efectivas
long double m_e=9.1093837015e-31;
long double me[4]={m_e,m_e,m_e,m_e};

//Energia
long double Eq=0.25*q;
complex <long double> k[i];
complex <long double> kt[i];
complex <long double> res1;
complex <long double> res2;
complex <long double> im ( 0 , 1 );
		
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
complex <long double> T11;
complex <long double> T12;
complex <long double> T21;
complex <long double> T22; 
complex <long double> mt[2][2]={{T11,T12},{T21,T22}};
complex <long double> mr[2][2]={{(1,1),(1,1)},{(1,1),(1,1)}};
complex <long double> two (2 , 0);
complex <long double> ex;
complex <long double> exp_p;
complex <long double> exp_n;
complex <long double> T_11, T_12, T_21, T_22;
for (int j=0; j<i-1; j++)
{
	ex = im*k[j]*(zetas[j+1]-zetas[j]);
	exp_p= exp(ex);
	exp_n= exp(-ex);
	T11 = ((kt[j+1]+kt[j])/(two*kt[j+1]))*exp_p;
	T12 = ((kt[j+1]-kt[j])/(two*kt[j+1]))*exp_n;
	T21 = ((kt[j+1]-kt[j])/(two*kt[j+1]))*exp_p;
	T22 = ((kt[j+1]+kt[j])/(two*kt[j+1]))*exp_n;
	mt[0][0]=T11;
	mt[0][1]=T12;
	mt[1][0]=T21;
	mt[1][1]=T22;
	
	cout<<endl<<"Matriz "<<j+1<<" = "<<endl<<endl;;
	cout<<mt[0][0]<<" , "<<mt[0][1]<<"\n";
	cout<<mt[1][0]<<" , "<<mt[1][1]<<"\n\n";
	
	T_11 =mr[0][0]*mt[0][0]+mr[0][1]*mt[1][0];
	cout<<"T_11 = "<<T_11<<endl;
	T_12 =mr[0][0]*mt[0][1]+mr[0][1]*mt[1][1];
    cout<<"T_12 = "<<T_12<<endl;
	T_21 =mr[1][0]*mt[0][0]+mr[1][1]*mt[1][0];
    cout<<"T_21 = "<<T_21<<endl;
	T_22 =mr[1][0]*mt[0][1]+mr[1][1]*mt[1][1];
    cout<<"T_22 = "<<T_22<<endl;
	mr[0][0]=  T_11;
    mr[0][1] = T_12;
    mr[1][0] = T_21;
    mr[1][1] = T_22;
}
cout<<"´T´ total = "<<endl;
    cout<<mr[0][0]<<" , "<<mr[0][1]<<"\n";
	cout<<mr[1][0]<<" , "<<mr[1][1]<<"\n\n";
    return 0;
}

