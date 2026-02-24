#include <iostream>
#include <cctype>
#include <string.h>
using namespace std;


void NhapChuoiChuCai(char s[], int maxLen)
{
    bool hopLe;

    do
    {
        hopLe = true;
        cin.getline(s, maxLen);

        if (strlen(s) == 0)
        {
            cout << "Khong duoc de trong! Nhap lai: ";
            hopLe = false;
            continue;
        }

        for (int i = 0; i < strlen(s); i++)
        {
            if (!isalpha(s[i]) && s[i] != ' ')
            {
                cout << "Loi: Chi duoc nhap chu cai va khoang trang! Nhap lai: ";
                hopLe = false;
                break;
            }
        }

    } while (!hopLe);
}

int main(){
	char s[100];
	NhapChuoiChuCai(s, 100);
	cout <<"Chuoi hop le vua nhap: " << s << endl;
	return 0;
	
}