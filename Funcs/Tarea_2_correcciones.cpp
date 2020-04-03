#include<iostream>

using namespace std;

void sumav(float vec1[], float vec2[], float vec3[], int N)
{
   for (int i=0; i<N; i++)
   {
      vec3[i] = vec1[i] + vec2[i];
   }
}


int main() {

    int numval;
    const int tamvec = 100;
    float vec1[tamvec];
    float vec2[tamvec];
    float vec3[tamvec];

    cout << "\n";
    cout<<"Ingrese el numero total de valores en el vector: ";
    cin>>numval;

    cout<<"Ingrese el vector #1: ";
    for(int i=0; i<numval; i++)
	{
        cin>>vec1[i];
    }

    cout<<"Ingrese el vector #2: ";
       for(int i=0; i<numval; i++)
	{
        cin>>vec2[i];
    }
    cout << endl;


    sumav(vec1, vec2, vec3, numval);

    cout<<"La suma de los dos vectores es: "<<endl;
    for (int i=0; i<numval; i++)
	{
         cout<<vec3[i]<<", ";
    }
    cout << "\n\n";

    return 0;

}
