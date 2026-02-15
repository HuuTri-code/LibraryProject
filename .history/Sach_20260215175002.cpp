#include "Sach.h"
using namespace std;

int timViTriChen(const ListDauSach &ds, const char* tenSach) {
    int left = 0;
    int right = ds.n - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1); // phep dich phai <-> chia, cho ngau.
        int cmp = strcmp(ds.nodes[mid]->tenSach, tenSach);// đi đén địa chỉ đó để thực hiện so sánh.

        if (cmp == 0) // trả về 0 khi nội dung giống nghe.
            return mid;
        else if (cmp < 0 ) // ví dụ: "A" < "B")- giá trị của bảng mã ASCII
            left = mid + 1;
        else if (cmp > 0) // ví dụ: "C" > "B")
            right = mid - 1;
    }
    return left; // dừng lại vị trí lớn hơn tên sách.
}

int themDauSach(ListDauSach &ds) {    
    if (ds.n >= MAX_DAUSACH) {
        cout << "Danh sach dau sach da day!\n";
        return;
    }

    DauSach* p = new DauSach

    cout << "Nhap ISBN: ";
    cin p->ISBN; // con trỏ p truy cập vào thành phần ISBN 
    cin.ignore(); // Khi bạn nhập ISBN và nhấn Enter, phím Enter (ký tự \n) vẫn còn sót lại trong bộ đệm. Lệnh này dùng để xóa ký tự thừa đó đi, 

    cout << "Nhap ten sach: ";
    cin.getline(p->tenSach, 100); // giới hạn 99 ký tự, 1 ký tự \n

    cout << "Nhap tac gia: ";
    cin.getline(p->tacGia, 50);

    cout << "Nhap the loai: ";
    cin.getline(p->theLoai, 30);

    cout << "Nhap so trang: ";
    cin >> p->soTrang;

    cout << "Nhap nam xuat ban: ";
    cin >> p->namXuatBan;

    p->soLuotMuon = 0;
    p->dsSach.pHead = p->dsSach.pTail = nullptr;
    p->dsSach.tongSoSach = 0;

    // mấy trường hợp 0,1,2, pos = ds.n xử lý ngon lành.
    int pos = timViTriChen(ds, p->tenSach); 

    for (int i = ds.n; i > pos; i--) {
        ds.nodes[i] = ds.nodes[i - 1];
    }
    ds.nodes[pos] = p;
    ds.n++;

    count << "Them dau sach thanh cong";
}

void inDanhSachDauSach(ListDauSach &ds) {
    if (ds.n == 0) {
        cout << "Danh sach nay rong! /n";
        return;
    }

    for (int i = 0; i < ds.n; i++) {
        cout << i + 1 << ". "
             << ds.nodes[i]->tenSach
             << " | ISBN: " << ds.nodes[i]->ISBN
             << " | So cuon: " << ds.nodes[i]->dsSach.tongSoSach
             << endl;    }
}

DauSach* timTheoIBSN(ListDauSach &ds, const char* IBSN) {
    for (int i = 0, i < ds.n; i++) {
        if (strcmp(ds.nodes[i]->ISBN, ISBN) == 0) 
            return 
    }
}