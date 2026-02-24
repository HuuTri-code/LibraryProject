#include "DocGia.h"
using namespace std;

DocGia* taoDocGia(int maThe) {
    DocGia* newDocGia = new DocGia;

    newDocGia->maThe = maThe;
    newDocGia->trangThaiThe = 1; // mặc định khi tạo mới là thẻ đang hoạt động
    
    newDocGia->pRight = nullptr; // con trỏ pRight được khởi tạo là nullptr, cho biết rằng chưa có con trỏ nào được gán vào nó.
    newDocGia->pLeft = nullptr;


    return newDocGia;
}
