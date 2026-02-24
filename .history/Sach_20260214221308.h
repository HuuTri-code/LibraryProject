#pragma once
#include "Structs.h"

// thao tác đầu sách
void themDauSach(ListDauSach& ds);
void xoaDauSach(ListDauSach& ds);
void inDanhSachDauSach(ListDauSach ds);

// thao tác cuốn sách
void themCuonSach(DauSach* dauSach);
void xoaCuonSach(DauSach* dauSach);
void inDanhMucSach(DauSach* dauSach);
