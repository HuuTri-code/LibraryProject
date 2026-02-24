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

void themDauSach(ListDauSach &ds) {    
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

    cout << "Them dau sach thanh cong";
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

DauSach* timTheoIBSN(ListDauSach &ds, const char* ISBN) {
    for (int i = 0; i < ds.n; i++) {
        if (strcmp(ds.nodes[i]->ISBN, ISBN) == 0) 
            return ds.nodes[i];
    }
    return nullptr;
}

void themCuonSach(DauSach* dauSach) {
    if (dauSach == nullptr) return; // kiểm tra con tro dauSach có hợp lệ hay không.

    Sach* newSach = new Sach;
    cout << "Nhap ma sach: ";
    cin >> newSach->maSach;

    Sach* temp = dauSach->dsSach.pHead; // lấy con trỏ tạm để duyệt danh sách sách của đầu sách hiện tại.
    while (temp != nullptr) {
        if (strcmp(temp->maSach, newSach->maSach) == 0) {
            cout << "Ma sach da ton tai! Them cuon sach that bai.\n";
            delete newSach; // giải phóng bộ nhớ đã cấp phát cho newSach dòng trên để tránh rò rỉ bộ nhớ.
            return;
        }
        temp = temp->pNext; // di chuyển con trỏ tạm đến cuốn sách tiếp theo trong danh sách.
    }
    
    cout << "Nhap vi tri: ";
    cin >> newSach->viTri;

    newSach->trangThai = 0; // mặc định khi thêm mới, cuốn sách có trạng thái "cho mượn được".
    newSach->pNext = nullptr; // khởi tạo con trỏ pNext của newSach thành nullptr vì nó sẽ là cuốn sách cuối cùng trong danh sách.

    if (dauSach->dsSach.pHead == nullptr) {
        dauSach->dsSach.pHead = dauSach->dsSach.pTail = newSach; // neu danh sách sách của đầu sách hiện tại đang rỗng, thì newSach sẽ trở thành cuốn sách đầu tiên và cũng là cuốn sách cuối cùng trong danh sách.
    } else {
        dauSach->dsSach.pTail->pNext = newSach; 
        // nếu danh sách sách của đầu sách hiện tại không rỗng, 
        thì con trỏ pNext của cuốn sách cuối cùng hiện tại sẽ trỏ đến newSach, sau đó cập nhật con trỏ pTail của đầu sách hiện tại để trỏ đến newSach, vì newSach bây giờ là cuốn sách cuối cùng trong danh sách.
        dauSach->dsSach.pTail = newSach;
    }
}
