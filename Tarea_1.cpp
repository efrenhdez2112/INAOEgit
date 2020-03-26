#include <iostream>
#include <vector>

using namespace std;

//Declaracion de funcion
void sum(float x[], float y[], float z[])
{
	//Punteros
	float *xptr = x;
    float *yptr = y;
    float *zptr = z;
	for (int i=0; i<4; i++)
	{
	  *zptr = (*xptr + *yptr);
	  *xptr++;
      *yptr++;
      *zptr++;
	}
}
int main()
{
	//Declaracion de vectores
	float vec1[4]={21,7,12,87};
	float vec2[4]={5,8,10,44};
	float suma[4];
	
	//No es necesario el &
	sum(vec1,vec2,suma);
	cout<<"El valor del vector sumado es: ";
	    for(int i = 0; i < 4; i++){
        cout << suma[i] << ", ";
    }
	return 0;
}
