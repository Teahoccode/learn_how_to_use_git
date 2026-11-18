#pragma once
#include<iostream>
using namespace std;

struct Data {
    int num; // So luong cau tra loi
    char *Arr; // Mang char chua so line
};

void containAnswer(string filename, ifstream &in, Data &s);

void compareAnswer(string filename1, string filename2, Data &ans, Data &student);
