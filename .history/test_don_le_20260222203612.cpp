#include <iostream>
#include <cctype>
#include <cstring>
#include <conio.h>

using namespace std;
const int MAX_STR = 100;

void VeLaiDong(char s[], int len, int pos)
{
    cout << "\rNhap chuoi: ";
    for (int i = 0; i < len; i++) cout << s[i];
    cout << " ";
    cout << "\rNhap chuoi: ";
    for (int i = 0; i < pos; i++) cout << s[i];
}

void NhapChuoiChuCai(char s[], int MAX_Len)
{
    int len = 0;
    int pos = 0;
    char c;

    cout << "Nhap chuoi: ";

    while (true)
    {
        c = getch();
        
        //ENTER
        if (c == 13)
        {
            if (len == 0)
            {
                cout << "\nKhong duoc de trong, hay nhap lai!"<< endl <<"Nhap chuoi: ";
                continue;
            }
            break;
        }

        //BACKSPACE
        if (c == 8)
        {
            if (pos > 0)
            {
                for (int i = pos - 1; i < len - 1; i++)
                    s[i] = s[i + 1];

                len--;
                pos--;
                VeLaiDong(s, len, pos);
            }
            continue;
        }

        //PHIM MUI TEN 
        if (c == 0 || c == -32)
        {
            c = getch();

            // MUI TEN TRAI
            if (c == 75 && pos > 0)
            {
                pos--;
                cout << "\b";
            }
            // MUI TEN PHAI
            else if (c == 77 && pos < len)
            {
                cout << s[pos];
                pos++;
            }
            continue;
        }

        // KY TU HOP LE
        if ((isalpha((unsigned char)c) || c == ' ') && len < MAX_Len - 1)
        {
            for (int i = len; i > pos; i--)
                s[i] = s[i - 1];

            s[pos] = c;
            len++;
            pos++;

            VeLaiDong(s, len, pos);
        }
    }

    s[len] = '\0';
    cout << endl;
}

int main()
{
    char s[MAX_STR];

    NhapChuoiChuCai(s, MAX_STR);

    cout << "Chuoi vua nhap: [" << s << "]"<< endl;

    return 0;
}
