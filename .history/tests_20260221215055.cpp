
#include <iostream>
#include <cctype>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

// =========================================================
// 1. HAM GIA LAP GETCH CHO LINUX (TU CODE)
// =========================================================
char getch_custom() {
    struct termios old;
    if (tcgetattr(STDIN_FILENO, &old) != 0) return 0;
    struct termios newt = old;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return ch;
}

// =========================================================
// 2. HAM NHAP MA CHUAN (TUONG THICH LINUX & WINDOWS)
// =========================================================
void nhapMa(char* result, int maxLen) {
    int length = 0;
    result[0] = '\0'; // Khoi tao chuoi rong

    while (true) {
        char c = getch_custom();

        // Xu ly Enter: ASCII 10 (\n) tren Linux, 13 (\r) tren Windows
        if (c == 10 || c == 13) {
            if (length > 0) { // It nhat 1 ky tu moi cho xong
                result[length] = '\0';
                cout << endl;
                return;
            }
            continue; 
        }

        // Xu ly Backspace: ASCII 8 hoac 127 (Linux)
        if ((c == 8 || c == 127) && length > 0) {
            length--;
            cout << "\b \b"; // Lui - Xoa - Lui
            continue;
        }

        // Xu ly ky tu hop le: Chu, So, '-', '_'
        if (isalnum(c) || c == '-' || c == '_') {
            if (length < maxLen - 1) {
                if (isalpha(c)) c = toupper(c); // Tu dong viet hoa

                result[length++] = c;
                cout << c; // In ra man hinh
            }
        }
        // Bam Space (ASCII 32) se bi lo di hoan toan vi khong vao if nao
    }
}

// =========================================================
// 3. HAM MAIN DE TEST RIENG
// =========================================================
int main() {
    char testMa[20]; // Khai bao mang du dung

    cout << "===== CHUONG TRINH TEST NHAP MA (LINUX) =====" << endl;
    cout << "- Chi nhan: A-Z, 0-9, '-', '_'" << endl;
    cout << "- Tu dong VIET HOA chu cai." << endl;
    cout << "- Bam SPACE se khong co tac dung." << endl;
    cout << "---------------------------------------------" << endl;
    
    cout << "Nhap ma sach: ";
    nhapMa(testMa, 20);

    cout << "\n>>> Ket qua trong mang: [" << testMa << "]" << endl;
    cout << ">>> Do dai chuoi: " << strlen(testMa) << endl;

    if (strlen(testMa) > 0) {
        cout << "=> TEST THANH CONG!" << endl;
    }

    return 0;
}
