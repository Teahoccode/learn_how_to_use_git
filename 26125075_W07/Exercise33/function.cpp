#include "function.h"

bool inputDate(ifstream &in, Date &DOB)
{
    char c;
    in >> DOB.day >> c >> DOB.month >> c >> DOB.year;
    return true;
}


bool inputDateFromConsole(string &DOB, Student &S){
    stringstream ss(DOB);
    char c1, c2;
    ss >> S.DOB.day >> c1 >> S.DOB.month >> c2 >> S.DOB.year;

    if (!ss || c1 != '/' || c2 != '/')
        return false;
    return true;
}

bool inputStudent(ifstream &in, Student &s)
{
    if (!getline(in, s.id, ','))
        return false;

    inputDate(in, s.DOB);
    in.ignore();
    in >> ws;
    getline(in, s.name);
    return true;
}

bool addStudent(Course &A, Student &S)
{
    if (A.num + 1 > A.capacity)
        return false;
    Student *temp = new Student[A.num + 1];
    for (int i = 0; i < A.num; i++)
    {
        temp[i] = A.Arr[i];
    }
    temp[A.num] = S;
    delete[] A.Arr;

    A.Arr = temp;
    A.num++;

    if (A.num >= A.minimum)
    {
        A.status = "open";
    }

    return true;
}

bool removeStudent(Course &A, string &id)
{

    int pos = -1;
    for (int i = 0; i < A.num; i++)
    {
        if (A.Arr[i].id == id)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "Student is not found!\n";
        return false;
    }
    Student *temp = new Student[A.num - 1];
    int index = 0;
    for (int i = 0; i < A.num; i++)
    {
        if (A.Arr[i].id != id)
        {
            temp[index++] = A.Arr[i];
        }
    }
    delete[] A.Arr;
    A.Arr = temp;
    A.num--;

    if (A.num - 1 < A.minimum)
    {
        A.status = "close";
        return false;
    }
    return true;
}

bool inputCourse(string filename, Course &A)
{
    ifstream in(filename);
    if (!in.is_open())
    {
        cout << "Can't open the file! \n";
        return false;
    }

    getline(in, A.id);
    getline(in, A.name);
    getline(in, A.status);
    in >> A.capacity >> A.minimum;
    in.ignore(1000, '\n');

    while (true)
    {
        Student s;
        if (!inputStudent(in, s))
            break;
        addStudent(A, s);
    }

    in.close();
    return true;
}

void outputDate(ostream &out, Date DOB)
{
    out << setfill('0') << setw(2) << DOB.day << "/" << setw(2) << DOB.month << "/" << DOB.year << "\n";
}

void outputStudent(ostream &out, Student &s)
{
    out << s.id << " - " << s.name << " - ";
    outputDate(out, s.DOB);
    return;
}

bool outputFile(string filename, Course &A)
{
    ofstream out(filename);
    if (!out)
    {
        cout << "Can't open the file!";
        return false;
    }
    out << "Course ID: " << A.id << "\n";
    out << "Course name: " << A.name << "\n";
    out << "--- Students' Information --- \n";
    for (int i = 0; i < A.num; i++)
    {
        out << i + 1 << ". ";
        outputStudent(out, A.Arr[i]);
    }

    out.close();
    return true;
}

bool realTime(Date &Today){
    time_t now = std::time(nullptr);
    tm* local_tm = std::localtime(&now);
    Today.day = local_tm -> tm_mday;
    Today.month = local_tm -> tm_mon +  1;
    Today.year = local_tm -> tm_year +1900;
    return true;

}




