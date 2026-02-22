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


using namespace std;

#define TEST_MODE 4

int main()
{
#if TEST_MODE // nếu 0 thì chạy menu, nếu 1 thì chạy test;
    setupConsole();
    atexit(restoreConsole);

    testNhapLieu();
#else

    runMenu();  

#endif

    return 0;
}
