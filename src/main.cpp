
#include <iostream>
#include "Account.h" 

using namespace std;

int main() {
    Account person; 
    int choice;
    int moneyInput;

    do {
        system("cls");

        cout << "\n================ CHUONG TRINH NGAN HANG ================" << endl;
        cout << "1. Xem thong tin tai khoan" << endl;
        cout << "2. Nap tien (Deposit)" << endl;
        cout << "3. Rut tien (Withdrawal)" << endl;
        cout << "0. Thoat" << endl;
        cout << "--------------------------------------------------------" << endl;
        

        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                person.get_information();
                break;

            case 2:

                cout << "Nhap so tien ban muon nap: ";
                cin >> moneyInput;

                if (person.deposit(moneyInput)) {
                    cout << "-> Nap tien thanh cong!" << endl;
                } else {
                    cout << "-> So tien nap khong hop le (phai > 0)!" << endl;
                }
                break;

            case 3:
                cout << "Nhap so tien ban muon rut: ";
                cin >> moneyInput;

                if (person.withdrawal(moneyInput)) {
                    cout << "-> Rut tien thanh cong!" << endl;
                } else {
                    cout << "-> Rut tien that bai (So du khong du hoac so tien khong hop le)!" << endl;
                }
                break;

            case 0:
                cout << "Cam on ban da su dung dich vu!" << endl;
                break;

            default:
                cout << "Lua chon khong hop le! Vui long nhap lai." << endl;
                break;
        }
        if (choice != 0) {
            cout << "\nNhan phim bat ky hoac Enter de quay lai menu...";
            cin.ignore(); 
            cin.get();    
        }


    } while (choice != 0);


    return 0;
}