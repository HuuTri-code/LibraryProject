#pragma once
#include <iostream>
#include <string.h>


#define MAX_DAUSACH 1000

// 1. Cau truc Ngay thang 

struct Ngay {
    int ngay, thang, nam;
};

// 2. Danh sach MUONTRA (Lien ket don - pTail de them o cuoi cho nhanh) 

struct MuonTra {
    char maSach[25];   

    Ngay ngayMuon;
    Ngay ngayTra;

    int trangThai;     // 0: dang muon, 1: da tra, 2: lam mat 

    MuonTra* pNext;
};

struct ListMuonTra {
    MuonTra *pHead = nullptr, *pTail = nullptr; // Them pTail de AddTail la O(1)
    // int soLuongMuon = 0; // Kiem tra muon 3 cuon ma bo luon do de loi khi quên xoá node. còn những danh sách nhỏ, chọn cách duyệt trực tiếp."
};

// --- 3. Danh sach Doc gia (Cay BST - Tim kiem theo Ma the)

struct DocGia {
    int maThe;         
    char ho[50], ten[20], giotinh[5]; 
    int trangThaiThe;  // 0: khoa, 1: hoat dong 

    ListMuonTra dsMuonTra; 
    DocGia *pLeft, *pRight;
    //DocGia* pLeft;
    //DocGia* pRight;
};
typedef DocGia* TREE_DocGia;

// --- 4. Danh muc sach (Lien ket don - Luu cac cuon sach cu the) 

struct Sach {
    char maSach[25];   
    int trangThai;     // 0: cho muon duoc, 1: da muon, 2: thanh ly 
    char viTri[20];
    
    Sach* pNext;
};

struct ListSach {
    Sach *pHead = nullptr, *pTail = nullptr;
    int tongSoSach = 0;
};

// --- 5. Dau sach (Mang con tro)
//  Lưu ý: Khi thêm đầu sách phải chèn đúng vị trí để giữ tăng dần theo tên.
struct DauSach {
    char ISBN[20], tenSach[100], tacGia[50], theLoai[30];
    int soTrang, namXuatBan; 
    int soLuotMuon = 0;      

    ListSach dsSach;         
};

struct ListDauSach {
    int n = 0;
    DauSach* nodes[MAX_DAUSACH]; 
};

    