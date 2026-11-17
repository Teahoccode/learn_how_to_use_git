#include<iostream>
#include "function.h"
using namespace std;

int main(){
    int n; cin >> n;
    cin >> n;
    int *Arr = new int[n];

    cout << "Input n elements: ";
    inputFunction(Arr, n);

    cout << "The array is: ";
    outputFunction(Arr, n);
    cout << endl;

    cout << "The sum of the array is: " << calculateSum(Arr, n) << endl;
    cout << "The max value of the array is: " << findMaxValue(Arr, n) << endl;

    int Max = findMaxValue(Arr, n) 
    deleteElement(Arr, delVal, Max);
    cout << "The array after deleting the max value is: ";
    outputFunction(Arr, n);


    int pos, val;
    cout << "Input the inserted position: ";
    cin >> pos;
    cout << "Input the inserted value: ";
    cin >> val;
    if (pos >= 0 && pos <= n){
        insertElement(Arr, pos, val, n);
        cout << "The array after inserting is: ";
        outputFunction(Arr, n);
        cout << endl;
    } else {
        cout << "Invalid position!" << endl;
    }

    reverseOrder(Arr, n);
    cout << "The array after reversing is: ";
    outputFunction(Arr, n);
    cout << endl;

    delete[] Arr;
    return 0;
}