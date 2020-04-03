//Using vectors in C++
#include <iostream>
#include <vector>
 
using namespace std;

int * sumVectors (int array1[], int array2[], int n) {
    //Initialize "sum" with zeros
    vector<int> sum(n, 0);   //Note that including "static" was not necessary! 

    for (int i=0; i<n; i++) {
        sum[i] = array1[i] + array2[i];
    }

    //Return Pointer to initial value in sum
    return sum.data();
}

 
int main () {
    int  var1[] = {10, 100, 200};
    int  var2[] = {20, 150, 250};
    int *sum; 

    int n = sizeof(var1)/sizeof(var1[0]);
    sum = sumVectors(var1, var2, n);

    cout << "( " ;
    for (int i=0; i<n; i++) {
        cout << sum[i] << " ";
    }
    cout << ")" << endl;
   
    return 0;
}
