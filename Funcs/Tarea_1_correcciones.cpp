#include <iostream>
#include <vector>

using namespace std;

//Declaracion de funcion
float *sum (float x[], float y[]) 
{
    static float z[4];  //c++ doesn't like to return adresses
	//Punteros
	for (int i=0; i<4; i++) 
    {
	  z[i] = x[i] + y[i];
	}
    return z;
}

int main()
{
	//Declaracion de vectores
	float vec1[4]={21,7,12,87};
	float vec2[4]={5,8,10,44};
	
	//No es necesario el &
    float *mySum;
	mySum = sum(vec1,vec2);
	cout<<"El valor del vector sumado es: ";
	for(int i = 0; i < 4; i++) 
    {
        cout << mySum[i] << ", ";
    }
    cout << "\n";
	return 0;
}
