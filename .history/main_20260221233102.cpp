#include <iostream>
#include <string.h>

#include "InputUtils.h"
#include "Structs.h"
#include "Docgia.h"
#include "Sach.h"
#include "Giaodich.h"
#include "Thongke.h"
#include "File.h"



using namespace std;

#define TEST_MODE 0




int menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Quan ly doc gia\n";
    cout << "2. Quan ly sach\n";
    cout << "3. Giao dich\n";
    cout << "4. Thong ke\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
    
    int choice;
    if (!(cin >> choice)) { // Kiểm tra nếu người dùng nhập chữ thay vì số
        cin.clear(); // Xóa lỗi nhập 
        cin.ignore(1000, '\n'); // Xóa bỏ ký tự không hợp lệ còn lại trong bộ đệm
        cout << "Lua chon khong hop le! Vui long nhap so tu 0 den 4.\n";    
        return -1;
    }
    cin.ignore(1000, '\n'); // Xóa bỏ ký tự newline còn lại trong bộ đệm sau khi đọc số
    return choice;
}

int main() {

#if TEST_MODE
    testNhapLieu();
#else



#endif
    return 0;
}
