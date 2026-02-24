#include "Sach.h"
using namespace std;

int timViTriChen(const ListDauSach &ds, const char* tenSach) {
    int left = 0;
    int right = ds.n - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1); // Tinh mid tranh tran so (overflow)
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

DauSach* timTheoISBN(const ListDauSach &ds, const char* ISBN) {
    for (int i = 0; i < ds.n; i++) {
        if (strcmp(ds.nodes[i]->ISBN, ISBN) == 0) 
            return ds.nodes[i];
    }
    return nullptr;
}

void themDauSach(ListDauSach &ds) {    
    if (ds.n >= MAX_DAUSACH) {
        cout << "Danh sach dau sach da day!\n";
        return;
    }

    DauSach* p = new DauSach;

    cout << "Nhap ISBN: ";
    cin >> p->ISBN; // con trỏ p truy cập vào thành phần ISBN 
    cin.ignore(); // Khi bạn nhập ISBN và nhấn Enter, phím Enter (ký tự \n) vẫn còn sót lại trong bộ đệm. Lệnh này dùng để xóa ký tự thừa đó đi, 

    // kiểm tra trùng ISBN
    if (timTheoISBN(ds, p->ISBN) != nullptr) {
        cout << "ISBN da ton tai! Them dau sach that bai.\n";
        delete p; // giải phóng bộ nhớ đã cấp phát cho p dòng trên để tránh rò rỉ bộ nhớ.
        return;
    }

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

    cout << "Them dau sach thanh cong" << endl;
}

void inDanhSachDauSach(const ListDauSach &ds) {
    if (ds.n == 0) {
        cout << "Danh sach nay rong! \n";
        return;
    }

    for (int i = 0; i < ds.n; i++) {
        cout << i + 1 << ". "
             << ds.nodes[i]->tenSach
             << " | ISBN: " << ds.nodes[i]->ISBN
             << " | So cuon: " << ds.nodes[i]->dsSach.tongSoSach
             << endl;    }
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
        // nếu danh sách sách của đầu sách hiện tại rỗng, thì cả pHead và pTail đều sẽ trỏ đến newSach, vì newSach là cuốn sách duy nhất trong danh sách.
        dauSach->dsSach.pHead = newSach;
        dauSach->dsSach.pTail = newSach; 

    } else {
        Sach* tail = dauSach->dsSach.pTail; // lấy con trỏ tail hiện tại của danh sách sách của đầu sách.
        tail->pNext = newSach; // làm con trỏ pNext của cuốn sách cuối cùng hiện tại trỏ đến newSach, để nối newSach vào cuối danh sách.
        dauSach->dsSach.pTail = newSach; // cập nhật con trỏ pTail của danh sách sách đầu sách để trỏ đến newSach, vì newSach bây giờ là cuốn sách cuối cùng trong danh sách.
    }
    // Cap nhat tong so sach cua dau sach sau khi them cuon sach moi.
    dauSach->dsSach.tongSoSach++;
    
    cout << "Them cuon sach thanh cong!\n";
}

bool xoaCuonSach(DauSach* dauSach, const char* maSach) {
    if (dauSach == nullptr || dauSach->dsSach.pHead == nullptr) return false; 

    Sach* prev = nullptr; // con trỏ prev để theo dõi cuốn sách trước đó trong danh sách khi duyệt.
    // con trỏ current để duyệt danh sách sách của đầu sách hiện tại, bắt đầu từ cuốn sách đầu tiên (pHead).
    Sach* current = dauSach->dsSach.pHead; 

    while (current != nullptr) {
        // so sánh mã sách của cuốn sách hiện tại với mã sách cần xóa. Nếu tìm thấy cuốn sách có mã sách trùng khớp, tiến hành xóa cuốn sách đó khỏi danh sách.
        if (strcmp(current->maSach, maSach) == 0) {
            // Không thể xoá nếu cuốn sách đang được mượn (trangThai == 1).
            if (current->trangThai == 1) {
                cout << "Khong the xoa. Sach dang duoc muon!\n";
                return false;
            }

            if (current == dauSach->dsSach.pHead && current == dauSach->dsSach.pTail) {
                dauSach->dsSach.pHead = nullptr;
                dauSach->dsSach.pTail = nullptr;
                
            } else {
                // nếu cuốn sách cần xóa là cuốn sách đầu tiên trong danh sách (pHead), cập nhật pHead để trỏ đến cuốn sách tiếp theo.
                if (current == dauSach->dsSach.pHead) {
                    dauSach->dsSach.pHead = current->pNext; // cập nhật pHead để trỏ đến cuốn sách tiếp theo sau khi xóa cuốn sách đầu tiên.
                } else {
                    // nếu cuốn sách cần xóa không phải là cuốn sách đầu tiên, 
                    // cập nhật con trỏ pNext của cuốn sách trước đó (prev) để trỏ đến cuốn sách tiếp theo sau khi xóa cuốn sách hiện tại.
                    prev->pNext = current->pNext; 
                }
                // nếu cuốn sách cần xóa là cuốn sách cuối cùng trong danh sách (pTail), cập nhật pTail để trỏ đến cuốn sách trước đó.
                if (current == dauSach->dsSach.pTail) {
                    dauSach->dsSach.pTail = prev; // cập nhật pTail để trỏ đến cuốn sách trước đó sau khi xóa cuốn sách cuối cùng.
                }
            }

            delete current; // giải phóng bộ nhớ đã cấp phát cho cuốn sách hiện tại sau khi xóa nó khỏi danh sách.
            dauSach->dsSach.tongSoSach--;
            cout << "Xoa cuon sach thanh cong!\n";
            return true; // trả về true để báo hiệu rằng cuốn sách đã được xóa thành công.
        }
        prev = current; // cập nhật con trỏ prev để trỏ đến cuốn sách hiện tại trước khi di chuyển con trỏ current đến cuốn sách tiếp theo trong danh sách.
        current = current->pNext; // di chuyển con trỏ current đến cuốn sách tiếp theo trong danh sách để tiếp tục tìm kiếm cuốn sách cần xóa.
    }
    return false; // trả về false nếu không tìm thấy cuốn sách có mã sách trùng khớp trong danh sách, tức là cuốn sách cần xóa không tồn tại.
}

// Độ phức tập xấu nhất O(n), tốt nhất là O(1) khi đầu sách không có cuốn sách nào hoặc cuốn sách cần xóa là cuốn sách đầu tiên trong danh sách.
bool xoaDauSach(ListDauSach &ds, const char* ISBN) {
    for (int i = 0; i < ds.n; i++) {
        if (strcmp(ds.nodes[i]->ISBN, ISBN) == 0) {
            DauSach* toDelete = ds.nodes[i]; // lưu con trỏ đến đầu sách cần xóa để giải phóng bộ nhớ sau khi xóa khỏi mảng.
            
            Sach* temp = toDelete->dsSach.pHead; // lấy con trỏ tạm để duyệt danh sách sách của đầu sách cần xóa.
            while (temp != nullptr) {
                if (temp->trangThai == 1) {
                    cout << "Khong the xoa. Co cuon sach dang duoc muon!\n";
                    return false; 
                }
                temp = temp->pNext;
            }

            temp = toDelete->dsSach.pHead; // reset con trỏ tạm để bắt đầu giải phóng bộ nhớ cho các cuốn sách của đầu sách cần xóa.
            while (temp != nullptr) {
                // xoá hết các cuốn sách của đầu sách cần xóa bằng cách duyệt qua danh sách sách của đầu sách đó và giải phóng bộ nhớ cho từng cuốn sách.
                Sach* next = temp->pNext;
                delete temp; // giải phóng bộ nhớ đã cấp phát cho cuốn sách hiện tại và khi hết vòng lặp.
                temp = next;
            }

            delete toDelete; // giải phóng bộ nhớ đã cấp phát cho đầu sách cần xóa sau khi đã xoá hết các cuốn sách của nó.

            // dịch mảng 
            for (int j = i; j < ds.n - 1; j++) {
                ds.nodes[j] = ds.nodes[j + 1];
            }
            
            ds.n--;
            ds.nodes[ds.n] = nullptr; // đặt con trỏ cuối cùng của mảng thành nullptr để tránh trỏ đến vùng nhớ đã giải phóng.
            cout << "Xoa dau sach thanh cong!\n";
            return true; // trả về true để báo hiệu rằng đầu sách đã được xóa thành công.
        }
    }

    cout << "Khong tim thay dau sach co ISBN: " << ISBN << ". Xoa that bai.\n";
    return false; // trả về false nếu không tìm thấy đầu sách có ISBN trùng kh
}

void inDanhSachCuonSach(const DauSach* dauSach) {
    if (dauSach == nullptr) {
        cout << "Dau sach khong ton tai!\n";
        return;
    }

    Sach* temp = dauSach->dsSach.pHead;

    if (temp == nullptr) {
        cout << "Dau sach nay chua co cuon sach nao!\n";
        return;
    }

    cout << "\n--- DANH SACH CAC CUON SACH (ISBN: " << dauSach->ISBN << ") ---\n";
    cout << "Ten sach: " << dauSach->tenSach << "\n";
    cout << "----------------------------------------------------------\n";

    int stt = 1;
    while (temp != nullptr) {
        cout << stt++ << ". Ma sach: " << temp->maSach 
             << " | Vi tri: " << temp->viTri
             << " | Trang thai: ";
        switch (temp->trangThai) {
            case 0: cout << "Cho muon duoc"; break;
            case 1: cout << "Da muon"; break;
            case 2: cout << "Thanh ly"; break;
            default: cout << "Khong xac dinh"; break;
        }

        cout << endl;
        temp = temp->pNext;
    }

}

void traCuuTheoTen(const ListDauSach &ds, const char* tenSach) {
    if (ds.n == 0) {
        cout << "Danh sach dau sach rong!\n";
        return;
    }

    int left = 0;
    int right = ds.n - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
    }

}