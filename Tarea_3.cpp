#include<iostream>
#include<complex>

using namespace std;
//Funcion para la suma
void sumav(complex <float> vec1[], complex <float> vec2[], complex <float> vec3[], float tam)
{
	//Declaracion de punteros
    complex <float> *ptrvec1 = vec1;
    complex <float> *ptrvec2 = vec2;
    complex <float> *ptrvec3 = vec3;

   //Suma
   for (int i; i<tam; i++)
   {
       *vec3 = (*vec1 + *vec2);

      *vec1++;
      *vec2++;
      *vec3++;
   }
}


int main() {

    //Declaracion de constantes y vectores
    int numval;
    const int tamvec = 1000;
    complex <float> vec1[tamvec];
    complex <float> vec2[tamvec];
    complex <float> vec3[tamvec];
    complex <float> num;
    

    cout<<"Ingrese el numero total de valores en el vector: ";
    cin>>numval; //Tamaño de vector

   //Ingreso de valores a los vectores, parte real e imaginaria
    for(int i=0; i<numval; i++)
	{
        cout<<"Ingrese el valor real del numero "<<i+1<<" para el vector #1: ";
        cin>>real(num);
        cout<<"Ingrese el valor imaginario del numero "<<i+1<<" para el vector #1: ";
		cin>>imag(num);
		vec1[i]=num;
    }

     for(int i=0; i<numval; i++)
	{
        cout<<"Ingrese el valor real del numero "<<i+1<<" para el vector #2: ";
        cin>>real(num);
        cout<<"Ingrese el valor imaginario del numero "<<i+1<<" para el vector #2: ";
		cin>>imag(num);
		vec2[i]=num;
    }

    //Se llama a la funcion
    sumav(vec1, vec2, vec3, numval);

    cout<<"La suma de los dos vectores es: "<<endl;
    for (int i=0; i<numval; i++)
	{
         cout<<vec3[i]<<", ";
    }

    return 0;

}
