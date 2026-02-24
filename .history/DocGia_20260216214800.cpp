#include "Docgia.h"
using namespace std;

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

    return newDocGia; // trả về con trỏ đến đối tượng DocGia mới được tạo ra, 
    // cho phép người gọi có thể sử dụng đối tượng này để thực hiện các thao tác tiếp theo như thêm vào cây 
    // hoặc quản lý thông tin của độc giả.
}

bool themDocGia(TREE_DocGia& root, DocGia* newnode) {
    // newnode là con trỏ đến đối tượng DocGia mới được tạo ra, chứa thông tin của độc giả cần thêm vào cây.
    if (root == nullptr) {
        root = newnode; // gán nút mới làm nút gốc của cây.
        return true; // trả về true để báo hiệu rằng việc thêm độc giả mới đã thành công.
    }
    
    // if này so sánh mã thẻ của độc giả mới (newnode->maThe) với mã thẻ của nút hiện tại (root->maThe) để xác định vị trí chèn nút mới vào cây.
    if (newnode->maThe == root->maThe) {
        cout 
    }
}