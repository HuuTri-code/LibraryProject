#pragma once
#include "Structs.h"

//
// -- Code Hoang Te -- 
//

// THAO TAC TREN DOC GIA
DocGia* taoDocGia(int maThe);
bool themDocGia(TREE_DocGia& root, DocGia* newnode);
DocGia* timDocGia(const TREE_DocGia root, int maThe);

void inDanhSachDocGia(const TREE_DocGia root);

// THAO TAC LIEN QUAN DEN MUON TRA
int demSachDangMuon(const DocGia* docGia);






//
// -- Code Huu Tri -- 
//


//
// -- Code Ho Nghia -- 
//