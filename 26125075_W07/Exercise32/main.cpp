#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;

int main()
{
    Data ans;
    Data student;
    int correct = 0;
    if (!(containAnswer("CorrectAnswers.txt", ans) && containAnswer("StudentAnswers.txt", student)))
    {
        cout << "Can't not read the file!";
    }
    if (compareAnswer(ans, student, correct))
    {
        double rate = static_cast<double>(correct) / 20;
        if (( rate - 0.7 > 0) || (abs(rate - 0.7) < 1e-9))
        {
            cout << "Pass the examination! \n";
        }
        else
        {
            cout << "Fail the examination! \n";
            cout << correct;
        }
    }
    else
    {
        cout << "Can't compare the answer!";
    }
    return 0;
}