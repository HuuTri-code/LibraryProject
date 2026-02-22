#include <iostream>
#include "Test.h"
#include "InputUtils.h"

using namespace std;



void testNhapLieu()
{
    char ma[20];

    cout << "Test nhap ma: ";
    nhapMa(ma, 20);
    cout << "=> Ma vua nhap: " << ma << endl;
}

