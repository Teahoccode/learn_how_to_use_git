#include "function.h"
#include<fstream>

bool containAnswer(string filename, Data &s){
    ifstream in(filename);

    if (!in.is_open()){
        cout << "Can't read the file!";
        return false;
    }

    in >> s.num;
    // Cấp phát vùng nhớ
    s.Arr = new char[s.num];
    string line;
    for (int i = 0; i < s.num; i++){
        getline(in, line );
        if (line.empty() || line[0] == '\r')
            s.Arr[i] = ' ';      
        else
            s.Arr[i] = line[0];
    }


    in.close();
    return true;

}

bool compareAnswer(Data &ans, Data &student, int &correct){
    int size = ans.num;
    correct = 0;
    for (int i = 0; i < size; i++){
        if (ans.Arr[i] == student.Arr[i]){
            correct++;
        }
    }
    return true;
}
