#include <iostream>
 
using namespace std;
const int MAX = 3;

int values (int *array1, int N) {
    for (int i=0; i<N; i++) {
        cout << "Element " << i << ": " << *array1 << endl; 
        array1++;
    }
    return 0;
}

int mySum (int array1[], int array2[], int N) {
    int sum = 0;
    for (int i=0; i<N; i++) {
        sum += array1[i] + array2[i];
    }
    return sum;
}

 
int main () {
   int  var1[MAX] = {10, 100, 200};
   int  var2[MAX] = {20, 150, 250};
   int sum; 
 

   values(var1, 3);
   sum = mySum(var1, var2, 3);

   cout << sum << endl;
   
   return 0;
}
