#include<iostream>

using namespace std;

void sumav(float vec1[], float vec2[], float vec3[], int tam)
{
    float *ptrvec1 = vec1;
    float *ptrvec2 = vec2;
    float *ptrvec3 = vec3;

   for (int i; i<tam; i++)
   {
       *vec3 = (*vec1 + *vec2);

      *vec1++;
      *vec2++;
      *vec3++;
   }
}


int main() {

    int numval;
    const int tamvec = 1000;
    float vec1[tamvec];
    float vec2[tamvec];
    float vec3[tamvec];

    cout<<"Ingrese el numero total de valores en el vector: ";
    cin>>numval;

    for(int i=0; i<numval; i++)
	{
        cout<<"Ingrese el valor numero "<<i+1<<" para el vector #1: ";
        cin>>vec1[i];
    }

       for(int i=0; i<numval; i++)
	{
        cout<<"Ingrese el valor numero "<<i+1<<" para el vector #2: ";
        cin>>vec2[i];
    }

    sumav(vec1, vec2, vec3, numval);

    cout<<"La suma de los dos vectores es: "<<endl;
    for (int i=0; i<numval; i++)
	{
         cout<<vec3[i]<<", ";
    }

    return 0;

}
