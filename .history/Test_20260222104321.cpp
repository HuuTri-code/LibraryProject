#include <iostream>
#include "Test.h"
#include "InputUtils.h"

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
            cout << "\b \b"; // \b dùng 2 lần để xóa ký tự cuối cùng trên console: lần đầu di chuyển con trỏ về vị trí của ký tự cần xóa, lần thứ hai ghi một dấu cách để xóa ký tự đó, và lần thứ ba di chuyển con trỏ trở lại vị trí ban đầu để sẵn sàng cho ký tự tiếp theo.
            // vi dụ nếu người dùng nhập "ABC" rồi nhấn Backspace, console sẽ hiển thị "AB " và con trỏ sẽ ở vị trí sau chữ "B", sẵn sàng nhận ký tự tiếp theo.
            continue;
        }

        if (isalnum(c) || c == '-' || c == '_')
        {
            if (len < maxLen - 1)
            {
                if (isalpha(c))
                    c = toupper(c);

                result[len++] = c;
                cout << (char)c;
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

