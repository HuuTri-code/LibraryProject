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
#if TEST_MODE // nếu 0 thì chạy menu, nếu 1 thì chạy test;
    // BẮT BUỘC: Thiết lập Terminal Ubuntu sang chế độ đọc phím thô 
    setupConsole(); 
    
    // Đảm bảo Terminal luôn được khôi phục khi chương trình kết thúc [cite: 59]
    atexit(restoreConsole);
    testNhapLieu();
#else

    runMenu();  

#endif

    return 0;
}
