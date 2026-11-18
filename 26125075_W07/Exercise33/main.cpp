#include "function.h"

int main()
{
    Course A;
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case 1:
        if (!inputCourse("input.txt", A))
        {
            return 1;
        }
        // Ghi ra file để kiểm tra phần output
        if (!outputFile("output.txt", A))
        {
            return 1;
        }
        break;

    case 2:
    {
        Student s;
        cout << "Input student id: ";
        getline(cin, s.id);
        cout << "Input student name: ";
        getline(cin, s.name);
        cout << "Input Date of Birth of student: ";
        string dob;
        getline(cin, dob);
        inputDateFromConsole(dob, s);
        addStudent(A, s);
        cout << A.num;
        break;
    }
    default:
        break;
    }

    delete[] A.Arr;
    return 0;
}