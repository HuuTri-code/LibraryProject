#include <iostream>
#include "Test.h"
#include "InputUtils.h"
#include <ctype.h>

using namespace std;

void nhapMa(char* result, int maxLen)
{
    int len = 0;
    while (true)
    {
        int c = getch_raw(); // 

        // 1. Xử lý ENTER: Chỉ thoát khi đã nhập ít nhất 1 ký tự
        if (c == '\r' || c == '\n')
        {
            if (len > 0) {
                result[len] = '\0'; // Kết thúc chuỗi [cite: 45]
                cout << endl;
                return;               
            } else {
                continue; // Ngăn việc nhấn Enter khi chưa nhập gì [cite: 44]
            }
        }

        // 2. Xử lý Backspace (Mã 8 cho Win, 127 cho Linux)
        if ((c == 8 || c == 127) && len > 0)
        {
            len--; 
            cout << "\b \b" << flush; // Xóa ký tự trên màn hình [cite: 47]
            continue;
        }

        // 3. Bỏ qua các phím chức năng (F1, mũi tên...) đã định nghĩa >= 1000
        if (c >= 1000) continue; 

        // 4. Lọc ký tự hợp lệ theo yêu cầu của thầy
        // Ép kiểu (unsigned char) để an toàn cho hàm isalnum 
        if (isalnum((unsigned char)c) || c == '-' || c == '_') 
        {
            if (len < maxLen - 1) 
            {
                if (isalpha((unsigned char)c)) c = toupper(c); // Tự động in hoa 

                result[len++] = (char)c;
                cout << (char)c << flush; // In ngay lập tức ra màn hình 
            } else {
                cout << "\a" << flush; // Tiếng beep cảnh báo đầy bộ nhớ
            }
        }
    }   
}

void testNhapLieu()
{
    char ma[20];

    cout << "Test nhap ma: " << flush; // đảm bảo rằng thông báo được in ra trước khi hàm nhapMa bắt đầu nhận input từ người dùng.
    nhapMa(ma, 20);
    cout << "=> Ma vua nhap: " << ma << endl;
}

