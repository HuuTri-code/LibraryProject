#include <iostream>
#include <conio.h>
#include <cctype>

using namespace std;

void NhapMa(char s[], int maxLen)
{
    int len = 0;
    char c;

    while (true)
    {
        c = _getch();

        // Enter
        if (c == 13)
        {
            if (len == 0) continue;
            s[len] = '\0';
            cout << endl;
            break;
        }

        // Backspace
        if (c == 8 && len > 0)
        {
            len--;
            cout << "\b \b";
            continue;
        }

        // Kiểm tra độ dài
        if (len >= maxLen) continue;

        // Kiểm tra hợp lệ
        if (isalnum(c) || c == '-' || c == '_')
        {
            c = toupper(c);
            s[len++] = c;
            cout << c;
        }
    }
}
