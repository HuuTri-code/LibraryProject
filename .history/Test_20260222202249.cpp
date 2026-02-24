#include <iostream>
#include "Test.h"
#include "InputUtils.h"
#include <ctype.h>

using namespace std;

void redrawLine(const char* buffer, int len, int vt)
{
    cout << "\r";               // về đầu dòng
    cout << "Test nhap ma: ";   // in lại prompt
    cout.write(buffer, len);    // in nội dung

    cout << " \033[K";          // xóa phần dư phía sau

    // đưa con trỏ về đúng vị trí
    int moveLeft = len - vt; // số vị trí cần di chuyển sang trái từ cuối chuỗi để đến vị trí vt
    if (moveLeft > 0)
        cout << "\033[" << moveLeft << "D";

    cout.flush();
}

void nhapMa(char* result, int maxLen)           
{
    int len = 0;
    int vt = 0;
    bool daBaoDay = false;

    while (true)
    {
        int c = getch_raw();

        if (c == '\n' || c == '\r')
        {
            if (len > 0)
            {
                result[len] = '\0';
                cout << endl;
                return;
            }
            continue;
        }

        if ((c == 8 || c == 127))
        {
            if (vt > 0)
            {
                for (int i = vt - 1; i < len - 1; i++)
                    result[i] = result[i + 1];

                len--;
                vt--;
                daBaoDay = false;
                redrawLine(result, len, vt);
            }
            continue;
        }

        if (c == 27) // do phím mũi tên trên Ubuntu gửi về 3 ký tự: ESC, '[', và một ký tự khác để xác định phím cụ thể (ví dụ: 'A' cho UP, 'B' cho DOWN, 'C' cho RIGHT, 'D' cho LEFT).
        {
            int c1 = getch_raw();
            int c2 = getch_raw();

            if (c1 == '[') // là mã bắt đầu của chuỗi phím đặc biệt (ví dụ: mũi tên)
            {
                if (c2 == 'D') // D là mã phím LEFT
                {
                    if (vt > 0)
                        vt--;
                }
                else if (c2 == 'C') // RIGHT
                {
                    if (vt < len)
                        vt++;
                }
            }

            redrawLine(result, len, vt); 
            continue;
        }

        // Ký tự hợp lệ
        if (isalnum(c) || c == '-' || c == '_')
        {
            if (len < maxLen - 1)
            {
                if (isalpha(c))
                    c = toupper(c);

                // chèn vào giữa
                for (int i = len; i > vt; i--)
                    result[i] = result[i - 1];

                result[vt] = (char)c;
                len++;
                vt++;
                daBaoDay = false;
                redrawLine(result, len, vt);
            }
            else
            {
                if (!daBaoDay)
                {
                    cout << "\a"; // beep
                    daBaoDay = true;
                }
            }
        }
    }
}

void testNhapLieu()
{
    const int GIOI_HAN = 20; 
    char ma[GIOI_HAN];

    cout << "Dia chi bat dau mang: " << (void*)ma << endl;
    cout << "Dia chi ket thuc mang: " << (void*)(ma + GIOI_HAN - 1) << endl;

    cout << "Test nhap ma: " << flush; // đảm bảo rằng thông báo được in ra trước khi hàm nhapMa bắt đầu nhận input từ người dùng.
    nhapMa(ma, GIOI_HAN);
    cout << "=> Ma vua nhap: " << ma << endl;
}

