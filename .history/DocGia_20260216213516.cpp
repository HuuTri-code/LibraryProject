#include "Docgia.h"
using namespace std;

// Hàm tạo mới một độc giả với mã thẻ được cung cấp và trả về con trỏ đến đối tượng DocGia mới được tạo.
DocGia* taoDocGia(int maThe) {
    DocGia* newDocGia = new DocGia;

    newDocGia->maThe = maThe;
    newDocGia->trangThaiThe = 1; // mặc định khi tạo mới là thẻ đang hoạt động
    
    // con trỏ pRight được khởi tạo là nullptr, cho biết rằng chưa có con trỏ nào được gán vào nó.
    newDocGia->pRight = nullptr; 
    newDocGia->pLeft = nullptr; 
    
    // khởi tạo con trỏ pHead của danh sách mượn trả là nullptr, cho biết rằng chưa có giao dịch mượn trả nào được thêm vào danh sách này.
    newDocGia->dsMuonTra.pHead = nullptr; 
    newDocGia->dsMuonTra.pTail = nullptr;

    return newDocGia;
}

bool themDocGia(TREE_DocGia& root, int maThe) {

}