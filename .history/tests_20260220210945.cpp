#include <conio.h>   // _getch
#include <ctype.h>   // toupper, isalnum

void NhapMa(char s[], int maxLen)
{
    int len = 0;
    char c;

    while (true)
    {
        c = _getch(); 

        if (c == 13) // Enter 
        {
            if (len == 0) continue; // == 0 là 
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

        // Kiểm tra hợp lệ
        if (len < maxLen)
        {
            if (isalnum(c) || c == '-' || c == '_')
            {
                c = toupper(c); // tự động in hoa
                s[len++] = c;
                cout << c;
            }
        }
    }
}
