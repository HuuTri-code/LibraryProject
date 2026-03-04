#include <fstream>
#include <sstream>
#include "Structs.h"
#include "File.h"
#include <cstring>
#include <iostream>

useing 

bool loadDauSach(const char* filename, ListDauSach& ds)
{
    ifstream file(filename); // Mở file để đọc
    if (!file.is_open()) return false; // Kiểm tra nếu file không mở được

    string line; // Biến để lưu từng dòng đọc được

    while (getline(file, line)) 
    {
        if (line.empty()) continue;

        // ---------- ĐỌC THÔNG TIN ĐẦU SÁCH ----------

        stringstream ss(line);
        string ISBN, tenSach, tacGia, theLoai;
        int soTrang, namXB, soLuotMuon, tongSoSach;

        getline(ss, ISBN, '|');
        getline(ss, tenSach, '|');
        getline(ss, tacGia, '|');
        getline(ss, theLoai, '|');

        ss >> soTrang;
        ss.ignore(1);
        ss >> namXB;
        ss.ignore(1);
        ss >> soLuotMuon;
        ss.ignore(1);
        ss >> tongSoSach;

        DauSach* dsNew = new DauSach;

        strcpy(dsNew->ISBN, ISBN.c_str());
        strcpy(dsNew->tenSach, tenSach.c_str());
        strcpy(dsNew->tacGia, tacGia.c_str());
        strcpy(dsNew->theLoai, theLoai.c_str());

        dsNew->soTrang = soTrang;
        dsNew->namXuatBan = namXB;
        dsNew->soLuotMuon = soLuotMuon;

        dsNew->dsSach.pHead = dsNew->dsSach.pTail = nullptr;
        dsNew->dsSach.tongSoSach = 0;

        // thêm vào danh sách
        ds.nodes[ds.n++] = dsNew;

        // ---------- ĐỌC #BOOK ----------

        getline(file, line); // đọc dòng #BOOK

        while (getline(file, line))
        {
            if (line == "END") break;

            stringstream ssBook(line);
            string maSach, viTri;
            int trangThai;

            getline(ssBook, maSach, '|');
            getline(ssBook, viTri, '|');
            ssBook >> trangThai;

            Sach* sach = new Sach;
            strcpy(sach->maSach, maSach.c_str());
            strcpy(sach->viTri, viTri.c_str());
            sach->trangThai = trangThai;
            sach->pNext = nullptr;

            addTailSach(dsNew->dsSach, sach);
        }
    }

    file.close();
    return true;
}

bool loadDocGia(const char* filename, TREE_DocGia& root)
{
    ifstream file(filename);
    if (!file.is_open()) return false;

    string line;

    while (getline(file, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);

        int maThe, phai, trangThai;
        string ho, ten;

        ss >> maThe;
        ss.ignore(1);

        getline(ss, ho, '|');
        getline(ss, ten, '|');

        ss >> phai;
        ss.ignore(1);
        ss >> trangThai;

        DocGia* dg = new DocGia;

        dg->maThe = maThe;
        strcpy(dg->ho, ho.c_str());
        strcpy(dg->ten, ten.c_str());
        dg->phai = phai;
        dg->trangThaiThe = trangThai;

        dg->dsMuonTra.pHead = dg->dsMuonTra.pTail = nullptr;

        themDocGia(root, dg);

        getline(file, line); // đọc #MUONTRA

        while (getline(file, line))
        {
            if (line == "END") break;

            stringstream ssMT(line);

            string maSach, ngayMuonStr, ngayTraStr;
            int trangThaiMT;

            getline(ssMT, maSach, '|');
            getline(ssMT, ngayMuonStr, '|');
            getline(ssMT, ngayTraStr, '|');
            ssMT >> trangThaiMT;

            MuonTra* mt = new MuonTra;
            strcpy(mt->maSach, maSach.c_str());

            sscanf(ngayMuonStr.c_str(), "%d/%d/%d",
                   &mt->ngayMuon.ngay,
                   &mt->ngayMuon.thang,
                   &mt->ngayMuon.nam);

            sscanf(ngayTraStr.c_str(), "%d/%d/%d",
                   &mt->ngayTra.ngay,
                   &mt->ngayTra.thang,
                   &mt->ngayTra.nam);

            mt->trangThai = trangThaiMT;
            mt->pNext = nullptr;

            addTailMuonTra(dg->dsMuonTra, mt);
        }
    }

    file.close();
    return true;
}

void capNhatTrangThaiSachDangMuon(TREE_DocGia root, ListDauSach& ds)
{
    if (!root) return;

    capNhatTrangThaiSachDangMuon(root->left, ds);

    MuonTra* mt = root->data.dsMuonTra.pHead;
    while (mt)
    {
        if (mt->trangThai == 0)
        {
            DauSach* dauSach = nullptr;
            Sach* s = timSachTheoMa(ds, mt->maSach, dauSach);
            if (s) s->trangThai = 1;
        }
        mt = mt->pNext;
    }

    capNhatTrangThaiSachDangMuon(root->right, ds);
}