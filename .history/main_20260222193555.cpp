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
    cout << "RAW MODE STARTED\n";
    cout.flush();
    // BẮT BUỘC: Thiết lập Terminal Ubuntu sang chế độ đọc phím thô 
    setupConsole(); 
    
    // Đảm bảo Terminal luôn được khôi phục khi chương trình kết thúc 
    // atexit là một hàm trong thư viện C cho phép đăng ký một hàm sẽ được gọi tự động khi chương trình kết thúc, bất kể kết thúc theo cách nào (thành công, lỗi, hoặc bị giết). Ở đây, chúng ta đăng ký hàm restoreConsole để đảm bảo rằng terminal sẽ được khôi phục về trạng thái ban đầu khi chương trình kết thúc, tránh tình trạng terminal bị "loạn" sau khi chạy xong.
    atexit(restoreConsole);
    
    testNhapLieu();
#else

    runMenu();  

#endif

    return 0;
}
