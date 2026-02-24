#include <conio.h>   // _getch
#include <ctype.h>   // toupper, isalnum

void NhapMa(char s[], int maxLen)
{
    int len = 0;
    char c;

    while (true)
    {
        c = _getch(); // lấy từng ký tự mà không hiển thị trên màn hình 

        if (c == 13) // là phím Enter, 13 là mã ASCII của phím Enter
        {
            if (len == 0) continue; // không cho rỗng
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
