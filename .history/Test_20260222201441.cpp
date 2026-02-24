#include <iostream>
#include "Test.h"
#include "InputUtils.h"
#include <ctype.h>

using namespace std;

void redrawLine(const char* buffer, int len, int cursorPos)
{
    // cursorPos là vị trí con trỏ trong buffer, len là độ dài hiện tại của chuỗi đã nhập. Hàm này sẽ vẽ lại dòng nhập sau mỗi lần có sự thay đổi (nhập mới, xóa, di chuyển con trỏ) để đảm bảo giao diện luôn đúng với trạng thái hiện tại của buffer.
    cout << "\r";               // về đầu dòng
    cout << "Test nhap ma: ";   // in lại prompt
    cout.write(buffer, len);    // in nội dung

    cout << " \033[K";          // xóa phần dư phía sau

    // đưa con trỏ về đúng vị trí
    int moveLeft = len - cursorPos;
    if (moveLeft > 0)
        cout << "\033[" << moveLeft << "D";

    cout.flush();
}

void nhapMa(char* result, int maxLen)           
{
    int len = 0;
    int cursorPos = 0;
    bool daBaoDay = false;

    while (true)
    {
        int c = getch_raw();

        // ENTER
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

        // BACKSPACE
        if ((c == 8 || c == 127))
        {
            if (cursorPos > 0)
            {
                for (int i = cursorPos - 1; i < len - 1; i++)
                    result[i] = result[i + 1];

                len--;
                cursorPos--;
                daBaoDay = false;
                redrawLine(result, len, cursorPos);
            }
            continue;
        }

        // MŨI TÊN (Linux raw mode ESC [ D / C)
        if (c == 27)
        {
            int c1 = getch_raw();
            int c2 = getch_raw();

            if (c1 == '[')
            {
                if (c2 == 'D') // LEFT
                {
                    if (cursorPos > 0)
                        cursorPos--;
                }
                else if (c2 == 'C') // RIGHT
                {
                    if (cursorPos < len)
                        cursorPos++;
                }
            }

            redrawLine(result, len, cursorPos);
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
                for (int i = len; i > cursorPos; i--)
                    result[i] = result[i - 1];

                result[cursorPos] = (char)c;
                len++;
                cursorPos++;
                daBaoDay = false;
                redrawLine(result, len, cursorPos);
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

