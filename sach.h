#pragma once
#include "structs.h"

void themDauSach(ListDauSach& ds);
void xoaDauSach(ListDauSach& ds, char ISBN[]);
void chenDauSachTheoTen(ListDauSach& ds, DauSach* p);
DauSach* timTheoTen(ListDauSach ds, char ten[]);
void giaiPhongSach(ListDauSach& ds);
