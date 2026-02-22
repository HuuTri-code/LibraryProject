#include <cctype>
#include <cstring>
#include "InputUtils.h"

void nhapMa(char* result, int maxLen)
{
    int length = 0;

    while (true)
    {
        char c = getch_custom();

        if (c == '\n' || c == '\r')
        {
            result[length] = '\0';
            cout << endl;
            return;
        }

        if (c == 8 && length > 0)
        {
            length--;
            cout << "\b \b";
            continue;
        }

        // Kiểm tra ký tự hợp lệ
        if (isalnum(c) || c == '-' || c == '_')
        {
            if (length < maxLen - 1)
            {
                if (isalpha(c))
                    c = toupper(c);

                result[length++] = c;
                cout << c;
            }
        }
    }
}
