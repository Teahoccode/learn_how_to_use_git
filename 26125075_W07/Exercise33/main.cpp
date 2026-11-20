#include "function.h"

void showMenu()
{
    cout << "\n===== MENU =====\n";
    cout << "1. Read course information from the file and print out on the output.txt\n";
    cout << "2. Add student to the course\n";
    cout << "3. Remove student from the course \n";
    cout << "4. Print out the student list\n";
    cout << "5. Print out the student born in this month\n";
    cout << "6. Print out the student born on this date\n";
    cout << "0. Thoat\n";
    cout << "Nhap lua chon: ";
}

int main()
{
    Course A;
    int choice;
    ofstream out("ouput.txt");
    do
    {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            if (!inputCourse("input.txt", A))
            {
                cout << "Khong doc duoc input.txt\n";
                break;
            }
            // Ghi ra file de kiem tra phan output
            if (!outputFile("output.txt", A))
            {
                cout << "Khong ghi duoc output.txt\n";
                break;
            }
            cout << "Da doc va ghi file thanh cong.\n";
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
            break;
        }
        case 3:
        {
            string ID;
            cout << "Input student id: ";
            getline(cin, ID);
            if (removeStudent(A, ID)){
                cout << "Remove succesfully!";
            }
            break;

        }
        case 4:
        {
            for (int i = 0; i < A.num; i++){
                cout << i + 1 << ". ";
                outputStudent(std::cout, A.Arr[i]);
            }
            break;
        }
        case 5:
        {
            Date Today;
            if (realTime(Today)){
                cout << "--- The students were born on this month --- \n";
                int index = 0;
                bool check = false;
                for (int i = 0; i < A.num; i++){
                    if (A.Arr[i].DOB.month == Today.month){
                        cout << index + 1 << ". ";
                        outputStudent(cout, A.Arr[i]);
                        check = true;
                    }
                }
                if (!check){
                    cout << "No student were born on this month!";
                }
            }
            break;

        }
        case 6:
        {
            Date Today;
            if (realTime(Today)){
                cout << "--- The students were born on this date ---\n";
                int index = 0;
                bool check = false;
                for (int i = 0; i < A.num; i++){
                    if (A.Arr[i].DOB.month == Today.month && A.Arr[i].DOB.day == Today.day){
                        cout << index + 1 << ". ";
                        outputStudent(cout, A.Arr[i]);
                        index ++;
                        check = true;
                    }
                }
                if (!check){
                    cout << "No students were born on this day!";
                }
            }
            break;

        }
        case 7:
        {
            int index = 0;
            for(int i = 0; i < A.num; i++){
                if (enoughAge(A.Arr[i].DOB)){
                    cout << index + 1 << ". ";
                    outputStudent(cout, A.Arr[i]);
                    index ++;
                }
            }
            break;
        }
        case 8:
        {
            int index = 0;
            if (!out){
                cout << "Can't open the file!";
            }
            else {

                out << "--- All student in K19 --- \n";
                string classe = "K19";
                for(int i = 0; i < A.num; i++){
                    if (checkClasse(A.Arr[i].id, classe)){
                        out << index + 1 << ". ";
                        outputStudent(out, A.Arr[i]);
                    }
                    
                }
            }
            break;

        }
        case 9:
        {
            string id;
            getline(cin, id);
            bool check = false;
            for(int i = 0; i < A.num; i++){
                if (A.Arr[i].id == id){
                    outputStudent()


                }
            }
        }

        case 0:
            cout << "Tam biet!\n";
            break;

        default:
            cout << "Lua chon khong hop le, vui long nhap lai.\n";
            break;
        }
    } while (choice != 0);
    delete[] A.Arr;
    return 0;
}