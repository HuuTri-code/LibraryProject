#include <iostream>
#include <string.h>

#include "InputUtils.h"
#include "Structs.h"
#include "Docgia.h"
#include "Sach.h"
#include "Giaodich.h"
#include "Thongke.h"
#include "File.h"



using namespace std;

#define TEST_MODE 0

int main()
{
#if TEST_MODE
    setupConsole();
    atexit(restoreConsole);

    testNhapLieu();
#else

    runMenu();  

#endif

    return 0;
}
