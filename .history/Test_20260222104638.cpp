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
            cout << "\b \b";
            continue;
        }

        // isalnum là một hàm trong thư viện ctype.h của ngôn ngữ lập trình C/C++, được sử dụng để kiểm tra xem một ký tự có phải là một ký tự chữ cái (a-z, A-Z) hoặc một chữ số (0-9) hay không. Hàm này trả về một giá trị khác 0 (thường là 1) nếu ký tự là chữ cái hoặc chữ số, và trả về 0 nếu ký tự không phải là chữ cái hoặc chữ số.
        // isalnum được khai 
        if (isalnum(c) || c == '-' || c == '_')
        {
            if (len < maxLen - 1) 
            {
                if (isalpha(c)) // 
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

