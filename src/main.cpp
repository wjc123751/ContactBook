#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <string>
#include "contact.h"
#include "contactbook.h"

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    ContactBook book;
    int choice;

    while (true) {
        cout << "\n===== 通讯录 =====\n";
        cout << "1. 添加联系人\n";
        cout << "2. 显示全部\n";
        cout << "3. 查找联系人\n";
        cout << "4. 删除联系人\n";
        cout << "0. 退出\n";
        cout << "请输入：";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            string name, phone;
            cout << "姓名："; cin >> name;
            cout << "电话："; cin >> phone;
            book.add(name, phone);
        }
        else if (choice == 2) {
            book.showAll();
        }
        else if (choice == 3) {
            string name;
            cout << "输入姓名："; cin >> name;
            book.search(name);
        }
        else if (choice == 4) {
            int idx;
            cout << "输入编号："; cin >> idx;
            book.remove(idx);
        }
    }

    return 0;
}