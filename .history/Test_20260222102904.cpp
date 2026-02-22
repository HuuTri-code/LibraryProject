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
            result[len] = '\0';
            cout << endl;
            return;
        }

        if ((c == 8 || c == 127) && len > 0) // hỗ trợ cả Backspace (8) và Delete (127) tùy hệ thống
        {
            len--;
            cout << "\b \b";
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

    cout << "Test nhap ma: " << flush;
    nhapMa(ma, 20);
    cout << "=> Ma vua nhap: " << ma << endl;
}

