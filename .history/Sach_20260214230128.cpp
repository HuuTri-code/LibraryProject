#include "Sach.h"
using namespace std;

int timViTriChen(ListDauSach ds, const char* tenSach) {
    int left = 0;
    int right = ds.n - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1); // phep dich phai <-> chia, cho ngau.
        int cmp = strcmp(ds.nodes[mid]->tenSach, tenSach);

        if (cmp == 0) // trả về 0 khi nội dung giống nghe.
            return mid;
        else if (cmp < 0 ) // ví dụ: "A" < "B")- giá trị của bảng mã ASCII
            left = mid + 1;
        else if (cmp > 0) // ví dụ: "C" > "B")
            right = mid - 1;
    }
    return left; // dừng lại vị trí lớn hơn tên sách.
}

int themDauSach(ListDauSach& ds) {
    if (ds.n >= MAX_DAUSACH) {
        cout << "Danh 
    }
}