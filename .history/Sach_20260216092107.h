#pragma once
#include "Structs.h"

// --- Khai báo nguyên mẫu hàm (Prototypes) ---

// Hàm tìm kiếm vị trí chèn để giữ danh sách luôn tăng dần theo tên
int timViTriChen(const ListDauSach &ds, const char* tenSach);

// Hàm tìm kiếm đầu sách theo mã ISBN (Trả về địa chỉ con trỏ)
DauSach* timTheoISBN(const ListDauSach &ds, const char* ISBN);

// Hàm nhập thông tin và thêm một đầu sách mới vào mảng con trỏ
void themDauSach(ListDauSach &ds);

// Hàm in toàn bộ danh sách đầu sách ra màn hình
void inDanhSachDauSach(const ListDauSach &ds);

// Hàm thêm một cuốn sách vào danh sách liên kết của một đầu sách cụ thể
void themCuonSach(DauSach* dauSach);
