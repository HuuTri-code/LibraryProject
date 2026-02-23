#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;


bool hopLeSo(const string &s) {
    if (s.length() == 0) return false; // KHONG CHO RONG
	 
//KIEM TRA TUNG KI TU 
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}


string nhapSo() {
    string s;

    do {
        cout << "Nhap so (chi nhan ky so 0-9): ";
        getline(cin, s); //NHAP LEN TU BAN PHIM 

        if (!hopLeSo(s)) {
            cout << "Nhap sai! Vui long nhap lai.\n";
        }

    } while (!hopLeSo(s));

    return s;  
}

int main() {
    string x = nhapSo();
    cout << "So hop le: " << x << endl;
    return 0;
}