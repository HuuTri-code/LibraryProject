#include <iostream>
#include <cctype>
#include <cstring>
#include "InputUtils.h" 

using namespace std;

// --- CHỖ NÀY QUAN TRỌNG ---
// Thay vì chỉ include .h, ta include luôn file .cpp chứa ruột hàm nhapMa
// để trình biên dịch hốt trọn gói trong 1 file duy nhất.
#include "Sach.cpp" 

int main() {
    char testMa[20]; // Khai báo mảng 20 ký tự
    
    cout << "--- TEST HAM NHAP MA (LINUX) ---" << endl;
    cout << "Quy tac: Chi nhan Chu, So, '-', '_'. Tu dong VIET HOA." << endl;
    cout << "Nhap ma: ";
    
    nhapMa(testMa, 20);
    
    cout << "\n----------------------------" << endl;
    cout << "Ket qua luu trong mang: [" << testMa << "]" << endl;
    cout << "Do dai thuc te: " << strlen(testMa) << endl;
    
    return 0;
}
