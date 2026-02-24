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
        int c = getch_raw();

        if (c == '\r' || c == '\n')
        {
            result[len] = '\0'; // kết thúc chuỗi bằng ký tự null, để mảng hợp lệ
            cout << endl;
            return;
        }

        if ((c == 8 || c == 127) && len > 0) // hỗ trợ cả Backspace (8) và Delete (127) tùy hệ thống
        {
            len--; 
            cout << "\b \b";
            continue;
        }

        if (c >= 1000) {
            continue; // bỏ qua các mã phím đặc biệt (như mũi tên) có giá trị ASCII lớn hơn 255.
        }
        // isalnum(c
        if (isalnum(c) || c == '-' || c == '_')
        {
            if (len >= maxLen - 1)
            {
                cout << '\a';   // beep cảnh báo
                continue;
            }

            if (isalpha(c))
                c = toupper(c);

            result[len++] = (char)c;
            cout << (char)c << flush;
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

