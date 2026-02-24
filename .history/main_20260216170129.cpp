#include "Structs.h"
#include "Docgia.h"
#include "Sach.h"
#include "Giaodich.h"
#include "Thongke.h"
#include "File.h"

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
    {
        int subChoice;
        cout << "\n--- QUAN LY SACH ---\n";
        cout << "21. Them dau sach\n";
        cout << "22. Them cuon sach (nhap ISBN)\n";
        cout << "23. Tra cuu sach theo ten\n";
        cout << "24. In danh sách cuon sach\n";
        cout << "Chon: ";
        cin >> subChoice;
        cin.ignore(); // Xóa bộ nhớ đệm để không bị trôi khi nhập chuỗi

        if (subChoice == 21) {
            themDauSach(ds); // Bước 1: Thêm đầu sách
        } 
        else if (subChoice == 22) {
            char isbn[11];
            cout << "Nhap ISBN cua dau sach muon them cuon: ";
            cin.getline(isbn, 11);
            DauSach* dsFound = timTheoISBN(ds, isbn); // Tìm đầu sách trước
            if (dsFound != nullptr) {
                themCuonSach(dsFound); // Bước 2: Thêm cuốn sách vào đầu sách đó
            } else {
                cout << "Khong tim thay ISBN!\n";
            }
        }
        else if (subChoice == 23) {
            char ten[100];
            cout << "Nhap ten sach can tim: ";
            cin.getline(ten, 100);
            traCuuTheoTen(ds, ten); // Bước 3: Tra cứu theo tên (hàm Binary Search)
        }
        else if (subChoice == 24) {
            // In toàn bộ đầu sách để kiểm tra
            for(int i = 0; i < ds.n; i++) {
                cout << "\n[" << i+1 << "] Ten: " << ds.nodes[i]->tenSach;
                inDanhSachCuonSach(ds.nodes[i]); // Bước 4: In chi tiết từng cuốn
            }
        }
        break;
    }

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
