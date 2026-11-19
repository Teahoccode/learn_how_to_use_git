#include "function.h"
#include<fstream>

bool containAnswer(string filename, Data &s){
    ifstream in(filename);

    if (!in.is_open()){
        cout << "Can't read the file!";
        return false;
    }

    in >> s.num;

    for (int i = 0; i < s.num; i++){
        s.Arr[i];
    }
    in.close();
    return true;

}

bool compareAnswer(Data &ans, Data &student, int &correct){
    int size = ans.num;
    int count = 0;
    for (int i = 0; i < size; i++){
        if (ans.Arr[i] == student.Arr[i]){
            count ++;
        }
    }
    correct = count;
    return true;
}