#include "Structs.h"
#include "docgia.h"
#include "sach.h"
#include "giaodich.h"
#include "thongke.h"
#include "file.h"

int menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Quan ly doc gia\n";
    cout << "2. Quan ly sach\n";
    cout << "3. Giao dich\n";
    cout << "4. Thong ke\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
    
    int choice;
    cin >> choice;
    return choice;
}

int main() {
    TREE_DocGia root = nullptr;
    ListDauSach ds;
    ds.n = 0;

    int choice;
    do {
        choice = menu();

        switch (choice) {
        case 1:
            cout << "Chuc nang doc gia\n";
            break;
        case 2:
            cout << "Chuc nang sach\n";
            break;
        case 3:
            cout << "Chuc nang giao dich\n";
            break;
        case 4:
            cout << "Chuc nang thong ke\n";
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
