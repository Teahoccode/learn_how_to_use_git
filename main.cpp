#include "Category.h"
#include "utils.h"
#include <iostream>

// using namespace std;
// int main() {
//     CategoryManager CategoryManager();
//     TransactionManager TransactionManager();
//     WalletManager WalletManager();
//     cout << "Bai tap lon CS160" << endl;
//     return 0;
// }



using namespace std;

// Doc 1 so nguyen, nhap sai thi bao nhap lai
int readInt(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Vui long nhap so!" << endl;
    }
}

double readDouble(const string& prompt) {
    double x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Vui long nhap so!" << endl;
    }
}

string readLine(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}

// Chi chap nhan 0 hoac 1
int readType() {
    int t;
    do {
        t = readInt("Loai (0 = thu, 1 = chi): ");
        if (t != 0 && t != 1) cout << "Loai chi duoc la 0 hoac 1!" << endl;
    } while (t != 0 && t != 1);
    return t;
}

void printAll(CategoryManager& cm, int type) {
    DynamicArray<Category> list;
    int size = 0;
    cout << (type == 0 ? "--- Thu (INC) ---" : "--- Chi (EXP) ---") << endl;
    if (!cm.getAllCategories(list, type, size)) {
        cout << "(trong)" << endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        cout << list[i].id << " | " << list[i].name
             << " | " << list[i].amount << endl;
    }
}

void showResult(bool ok) {
    cout << (ok ? ">> Thanh cong" : ">> That bai") << endl;
}

int main() {
    CategoryManager cm;
    int choice;

    do {
        cout << "\n===== QUAN LY DANH MUC =====" << endl;
        cout << "1. Them danh muc" << endl;
        cout << "2. Xoa danh muc" << endl;
        cout << "3. Doi ten danh muc" << endl;
        cout << "4. Cap nhat so tien" << endl;
        cout << "5. Xem danh sach theo loai" << endl;
        cout << "0. Thoat" << endl;
        choice = readInt("Chon: ");

        if (choice == 1) {
            string name = readLine("Ten danh muc: ");
            int type = readType();
            showResult(cm.addCategory(name, type));
        }
        else if (choice == 2) {
            string id = readLine("ID can xoa (vd EXP003): ");
            int type = readType();
            showResult(cm.deleteCategory(id, type));
        }
        else if (choice == 3) {
            string id = readLine("ID can doi ten: ");
            string newName = readLine("Ten moi: ");
            int type = readType();
            showResult(cm.renameCategory(id, newName, type));
        }
        else if (choice == 4) {
            string id = readLine("ID can cap nhat: ");
            double amount = readDouble("So tien moi: ");
            int type = readType();
            showResult(cm.updateCategory(id, amount, type));
        }
        else if (choice == 5) {
            int type = readType();
            printAll(cm, type);
        }
        else if (choice != 0) {
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);

    cout << "Tam biet!" << endl;
    return 0;
}