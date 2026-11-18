#pragma once
using namespace std;
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    string id;
    string name;
    Date DOB;
};

struct Course {
    string id;
    string name;
    Student *Arr;
    string status; // close 0, open 1
    int capacity;
    int minimum;
    int num;

    Course (){
        num = 0;
    }
};

bool inputDate(ifstream &in, Date &DOB);

bool inputDateFromConsole(string &DOB, Student &S);

bool inputStudent(ifstream &in, Student &s, Course &A);

bool addStudent(Course &A, Student &S);

bool inputCourse(string filename, Course &A);

bool inputStudent(string filename, Student &d, Course &A);

void outputDate(ofstream &out, Date DOB);

void outputStudent(ofstream &out, Course &A, int i);

bool outputFile(string filename, Course &A);


