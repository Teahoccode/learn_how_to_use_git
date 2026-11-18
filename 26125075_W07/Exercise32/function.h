#pragma once
#include<iostream>
using namespace std;

struct Data {
    int num; // So luong cau tra loi
    char *Arr; // Mang char chua so line
};

bool containAnswer(string filename, Data &s);

bool compareAnswer( Data &ans, Data &student, int &correct);
