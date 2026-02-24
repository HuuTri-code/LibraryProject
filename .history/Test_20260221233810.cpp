#include <iostream>
#include "InputUtils.h"
#include "Structs.h"
#include "Test.h"


void testNhapLieu()
{
    char ma[20];

    cout << "Test nhap ma: ";
    nhapMa(ma, 20);
    cout << "=> Ma vua nhap: " << ma << endl;
}

