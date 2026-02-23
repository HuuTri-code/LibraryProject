#include <iostream>
#include "Test.h"
#include "InputUtils.h"

using namespace std;

void nhapMa(char* result, int maxLen)
{
    int len = 0;

    while (true)
    {
        int c = getch_raw(); // getch_raw bằng với getch() trên Windows, nhưng trên Linux nó được định nghĩa để đọc một ký tự từ bàn phím mà không cần nhấn Enter, trả về mã ASCII của ký tự đó. Nếu có lỗi trong quá trình đọc, hàm sẽ trả về 0.

        if (c == '\r' || c == '\n')
        {
            if (len > 0) {
                result[len] = '\0'; // kết thúc chuỗi bằng ký tự null, để mảng hợp lệ
                cout << endl;
                return;               
            } else {
                continue;
            }

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
        // isalnum(c) kiểm tra xem ký tự có phải là chữ cái hoặc số hay không.
        if (isalnum(c) || c == '-' || c == '_')
        {
            if (len < maxLen - 1)
            {
                if (isalpha(c)) c = toupper(c); // Tự động in hoa [cite: 47-48]

                result[len++] = (char)c;
                cout << (char)c << flush;
            }
            else {
                cout << "\a" << flush; // Hết chỗ nhập thì phát tiếng kêu        }
    }
}

void testNhapLieu()
{
    char ma[20];

    cout << "Test nhap ma: " << flush; // đảm bảo rằng thông báo được in ra trước khi hàm nhapMa bắt đầu nhận input từ người dùng.
    nhapMa(ma, 20);
    cout << "=> Ma vua nhap: " << ma << endl;
}

