#pragma once
#include "Structs.h"

// CÁC THAO TÁC TRÊN ĐẦU SÁCH (Mảng con trỏ)
int timViTriChen(const ListDauSach &ds, const char* tenSach);
DauSach* timTheoISBN(const ListDauSach &ds, const char* ISBN);
void themDauSach(ListDauSach &ds);
void inDanhSachDauSach(const ListDauSach &ds);
bool xoaDauSach(ListDauSach &ds, const char* ISBN);


// CÁC THAO TÁC TRÊN CUỐN SÁCH (Danh sách liên kết đơn)
void themCuonSach(DauSach* dauSach);
bool xoaCuonSach(DauSach* dauSach, const char* maSach);
void inDanhSachCuonSach(const DauSach* dauSach);


// Tra
void traCuuTheoTen(const ListDauSach )