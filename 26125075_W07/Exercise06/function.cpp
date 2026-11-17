#include<iostream>
#include "function.h"
using namespace std;


void inputFunction(int *Arr, int n){
    for(int i =0; i < n; i++){
        cin >> Arr[i];
    }
    return;
}

void outputFunction(int *Arr, int n){
    for(int i =0; i < n; i++){
        cout << Arr[i] << " ";
    }
    return;
}

int calculateSum(int *Arr, int n){
    int sum = 0;
    for(int i =0; i < n; i++){
        sum += Arr[i];
    }
    return sum;
}

int findMaxValue(int *Arr, int n){
    int max = Arr[0];
    for(int i = 1; i < n; i++){
        if (Arr[i] > max) max = Arr[i];
    }
    return max;
}

void deleteElement(int *Arr, int val, int &n){
    int index = 0;
    for (int i = 0; i < n; i++){
        if (Arr[i] !=val){
            Arr[index++] = Arr[i];
        }
    }
    n = index;
}

void insertElement(int *Arr, int pos, int val, int &n){
    for (int i = n; i > pos; i--){   
        Arr[i] = Arr[i-1];
    }
    Arr[pos] = val;
    n++;                           
}

void reverseOrder(int *Arr, int &n){
    for(int i = 0; i < n/2; i ++){
        std::swap(Arr[i], Arr[n - i -1]);
    }
}