#pragma once
#include "Structs.h"

//
// -- Code Hoang Te -- 
//


// Trả về địa chỉ của vùng nhớ vừa cấp phát trên Heap
DocGia* taoDocGia(int maThe);

// Sử dụng tham chiếu (&) để tác động trực tiếp vào cấu trúc cây
bool themDocGia(TREE_DocGia& root, DocGia* newnode);

// Trả về con trỏ đến Độc giả nếu thấy, ngược lại trả về nullptr
DocGia* timDocGia(const TREE_DocGia root, int maThe);

// Duyệt theo thứ tự In-order (Trái - Gốc - Phải) để có danh sách tăng dần theo mã thẻ
void inDanhSachDocGia(const TREE_DocGia root);

int demSachDangMuon(const DocGia* docGia);






//
// -- Code Huu Tri -- 
//


//
// -- Code Ho Nghia -- 
//