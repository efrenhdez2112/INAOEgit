#include <iostream>
 
using namespace std;

int * sumVectors (int array1[], int array2[], int n) {
    static int *sum = new int[n];
    for (int i=0; i<n; i++) {
        sum[i] = array1[i] + array2[i];
    }
    return sum;
}

 
int main () {
    int  var1[] = {10, 100, 200};
    int  var2[] = {20, 150, 250};
    int *sum; 

    int n = 3;
    sum = sumVectors(var1, var2, n);

    cout << "( " ;
    for (int i=0; i<n; i++) {
        cout << sum[i] << " ";
    }
    cout << ")" << endl;
    delete [] sum;
   
    return 0;
}
