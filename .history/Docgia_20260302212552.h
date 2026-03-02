#pragma once
#include "Structs.h"

//
// -- Code Hoang Te -- 
//

#include "Docgia.h"
#include <iostream>
#include <cstring>

using namespace std;

// 1. NHOM HAM KHOI TAO VA THEM MOI (CORE)
// 

DocGia* taoDocGia(int maThe);
bool themDocGia(TREE_DocGia& root, DocGia* newnode);


// 2. NHOM HAM TIM KIEM VA TRUY XUAT

// Tim kiem mot doc gia trong cay dua vao ma the (Duyet vong lap)
DocGia* timDocGia(const TREE_DocGia root, int maThe);

// Dem so luong sach ma mot doc gia cu the dang muon (trang thai = 0)
int demSachDangMuon(const DocGia* docGia);


// =========================================================
// 3. NHOM HAM HIEN THI (DISPLAY)
// =========================================================

// In toan bo danh sach doc gia trong cay theo thu tu ma the tang dan (Inorder)
void inDanhSachDocGia(const TREE_DocGia root);


// =========================================================
// 4. NHOM HAM GIAI PHONG BO NHO (CLEANUP)
// =========================================================

// Giai phong danh sach lien ket MuonTra cua tung doc gia
void giaiPhongMuonTra(ListMuonTra &list);

// Giai phong toan bo cay doc gia (Duyet hau thu tu - Postorder)
void giaiPhongCay(TREE_DocGia &root);


//
// -- Code Huu Tri -- 
//


//
// -- Code Ho Nghia -- 
//