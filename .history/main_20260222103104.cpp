#include <iostream>
#include <string.h>

#include "InputUtils.h"
#include "Structs.h"
#include "Docgia.h"
#include "Sach.h"
#include "Giaodich.h"
#include "Thongke.h"
#include "File.h"
#include "Test.h"
#include "runMenu.h"


using namespace std;

#define TEST_MODE 1

int main()
{
#if TEST_MODE 1 // nếu 0 thì chạy menu, nếu 1 thì chạy test;
    testNhapLieu();
#else

    runMenu();  

#endif

    return 0;
}
