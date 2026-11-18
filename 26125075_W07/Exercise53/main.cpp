#include<iostream>
#include<fstream>
#include "function.h"

using namespace std;

int main(){
    Data ans;
    Data student;
    int correct = 0;
    if (containAnswer("CorrectAnswers.txt", ans) && containAnswer("StudentAnswers.txt", ans)){
        cout << "Input succesfully!";
    }
    if (compareAnswer(ans, student, correct)){
        double rate = correct/20;
        if(rate > 0.7){
            cout << "Pass the examination! \n";
        }
        else {
            cout << "Fail the examination! \n";
        }

    }
    return 0;

}