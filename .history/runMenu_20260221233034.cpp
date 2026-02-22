#include <iostream>
#include <string.h>

#include "InputUtils.h"
#include "Structs.h"
#include "Docgia.h"
#include "Sach.h"
#include "Giaodich.h"
#include "Thongke.h"
#include "File.h"

void runMenu()
{
    TREE_DocGia root = nullptr;
    ListDauSach ds;
    ds.n = 0;

    int choice;

    do {
        choice = menu();
    } while (choice != 0);
}
