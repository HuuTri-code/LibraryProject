#include <iostream>


void testNhapLieu()
{
    char ma[20];

    cout << "Test nhap ma: ";
    nhapMa(ma, 20);
    cout << "=> Ma vua nhap: " << ma << endl;
}

void runMenu()
{
    TREE_DocGia root = nullptr;
    ListDauSach ds;
    ds.n = 0;

    int choice;

    do {
        choice = menu();
        ...
    } while (choice != 0);
}
