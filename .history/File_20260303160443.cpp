#include <fstream>
#include <sstream>

bool loadDauSach(const char* filename, ListDauSach& ds)
{
    ifstream file(filename);
    if (!file.is_open()) return false;

    string line;

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