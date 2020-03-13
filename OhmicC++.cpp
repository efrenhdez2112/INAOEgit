#include <iostream>
#include <math.h>

using namespace std;
int main ()
{
	const double pi = 3.14159265358979323846;
	double j, Nc;
	double n;
	float T=523.15;
	float Eg=7, Ec=2.16;
	float m=2.7e-4;
	float m_eff=0.4;
	float Kb=8.6e-5;
	float h=4.13e-15;
	float q=1.6e-19;
	float hcua=pow(h,2);
	float Ef=Eg/2;
	float E=0;
	cout<<"Modelo de Conduccion Ohmica Al2O3\n";
	float Nc_1=2*((2*pi*m_eff*Kb*T)/(hcua));
	Nc=pow(Nc_1,(3/2));
	float n_1=exp((-(Ec-Ef))/(Kb*T));
	n=Nc*n_1;
	cout<<"Nc= "<<Nc<<"\n";
	cout<<"n= "<<n<<"\n";
	for (int i=0; E<=4; i++)
	{
		j=(n*q*m*E)*exp(-(Eg/(2*Kb*T)));
		cout<<"E= "<<E<<"\t"<<"J= "<<j<<"\n";
		E+=0.1;
	}
	return 0;
}
