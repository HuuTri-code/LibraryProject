#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

#include "Structs.h"
#include "File.h"
#include "Sach.h"
#include "Docgia.h"
#include "Giaodich.h"


//////////////////////////////////////////////////////////
//// LOAD DAU SACH
//////////////////////////////////////////////////////////

bool loadDauSach(const char* filename, ListDauSach& ds)
{
    ifstream file(filename);   

    if (!file.is_open()) 
    {
        cout << "Khong mo duoc file DauSach\n";
        return false;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty()) continue;

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

        ds.nodes[ds.n++] = dsNew;

        getline(file, line); // #BOOK

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

    cout << "Load DauSach thanh cong\n";

    return true;
}

//////////////////////////////////////////////////////////
//// LOAD DOC GIA
//////////////////////////////////////////////////////////

bool loadDocGia(const char* filename, TREE_DocGia& root)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Khong mo duoc file DocGia\n";
        return false;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);

        int maThe;
        string ho, ten, gioitinh;
        int trangThai;

        ss >> maThe;
        ss.ignore(1);

        getline(ss, ho, '|');
        getline(ss, ten, '|');
        getline(ss, gioitinh, '|');

        ss >> trangThai;

        DocGia* dg = new DocGia;

        dg->maThe = maThe;

        strcpy(dg->ho, ho.c_str());
        strcpy(dg->ten, ten.c_str());
        strcpy(dg->giotinh, gioitinh.c_str());

        dg->trangThaiThe = trangThai;

        dg->dsMuonTra.pHead = dg->dsMuonTra.pTail = nullptr;

        themDocGia(root, dg);

        getline(file, line); // #MUONTRA

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

    cout << "Load DocGia thanh cong\n";

    return true;
}

//////////////////////////////////////////////////////////
//// CAP NHAT TRANG THAI SACH
//////////////////////////////////////////////////////////

void capNhatTrangThaiSachDangMuon(TREE_DocGia root, ListDauSach& ds)
{
    if (root == nullptr) return;

    capNhatTrangThaiSachDangMuon(root->pLeft, ds);

    MuonTra* mt = root->dsMuonTra.pHead;

    while (mt != nullptr)
    {
        if (mt->trangThai == 0)
        {
            DauSach* dauSach = nullptr;

            Sach* s = timSachTheoMa(ds, mt->maSach, dauSach);

            if (s != nullptr)
            {
                s->trangThai = 1;
            }
        }

        mt = mt->pNext;
    }

    capNhatTrangThaiSachDangMuon(root->pRight, ds);
}