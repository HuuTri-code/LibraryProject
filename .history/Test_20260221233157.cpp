#include <iostream>
#include <string.h>

#include "InputUtils.h"
#include "Structs.h"
#include "Docgia.h"
#include "Sach.h"
#include "Giaodich.h"
#include "Thongke.h"
#include "File.h"


void testNhapLieu()
{
    char ma[20];

    cout << "Test nhap ma: ";
    nhapMa(ma, 20);
    cout << "=> Ma vua nhap: " << ma << endl;
}

