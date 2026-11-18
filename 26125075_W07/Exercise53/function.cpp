#include "function.h"
#include<fstream>

void containAnswer(string filename, Data &s){
    ifstream in(filename);

    if (!in.is_open()){
        cout << "Can't read the file!";
        return;
    }

    in >> s.num;

    for (int i = 0; i < s.num; i++){
        
    }


}