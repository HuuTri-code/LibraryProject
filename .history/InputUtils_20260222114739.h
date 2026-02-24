#pragma once
#include <iostream>
#include <cctype>
#include <cstring>

#define KEY_UP    1001
#define KEY_DOWN  1002
#define KEY_LEFT  1003
#define KEY_RIGHT 1004
#define KEY_ESC   27
#define KEY_ENTER 13

using namespace std;

#ifdef _WIN32 // Tự động nhận diện nếu đang chạy trên Windows
    #include <conio.h>

    inline void setupConsole() {}
    inline void restoreConsole() {}

    inline int getch_raw() {
        return _getch();
    }

    inline int getKey() {
        int ch = _getch();
        if (ch == 0 || ch == 224) {
            ch = _getch();
            switch (ch) {
                case 72: return KEY_UP;
                case 80: return KEY_DOWN;
                case 75: return KEY_LEFT;
                case 77: return KEY_RIGHT;
            }
        }
        return ch;
    }

#else
    #include <termios.h>
    #include <unistd.h>

    static struct termios old_term;// lưu lại cấu hình cũ của terminal để có thể khôi phục sau khi thoát chương trình.

    inline void setupConsole() { // thiết lập chế độ "nhạy" cho terminal, cho phép đọc phím mà không cần nhấn Enter và tắt hiển thị ký tự khi nhập.
        if (tcgetattr(STDIN_FILENO, &old_term) == -1) return;
        struct termios new_term = old_term;

        // Tắt ICANON (chế độ dòng) và ECHO (tự in phím)
        new_term.c_lflag &= ~(ICANON | ECHO);
        
        // QUAN TRỌNG: Thiết lập đọc từng ký tự ngay lập tức
        new_term.c_cc[VMIN] = 1;  // Đọc ít nhất 1 ký tự
        new_term.c_cc[VTIME] = 0; // Không đợi (timeout)

        tcsetattr(STDIN_FILENO, TCSANOW, &new_term);    
}

    inline void restoreConsole() { // Khôi phục cấu hình cũ.
        tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
    }

    inline int getch_raw() { // đọc một ký tự từ bàn phím mà không cần nhấn Enter, trả về mã ASCII của ký tự đó. Nếu có lỗi trong quá trình đọc, hàm sẽ trả về 0.
        char ch;
        if (read(STDIN_FILENO, &ch, 1) <= 0) return 0;
        return (unsigned char)ch; // unsigned là để đảm bảo rằng giá trị trả về luôn dương, tránh trường hợp khi đọc một ký tự có mã ASCII lớn hơn 127, nó sẽ được hiểu là một số âm nếu không được chuyển đổi sang unsigned char.
    }

    inline int getKey() { // đọc một phím từ bàn phím và trả về mã tương ứng với phím đó, bao gồm cả các phím đặc biệt như mũi tên và Enter. Nếu có lỗi trong quá trình đọc, hàm sẽ trả về 0.
        char ch;
        if (read(STDIN_FILENO, &ch, 1) <= 0) return 0;

        if (ch == 27) {
            char seq[2];
            if (read(STDIN_FILENO, &seq[0], 1) > 0 &&
                read(STDIN_FILENO, &seq[1], 1) > 0) {

                if (seq[0] == '[') {
                    switch (seq[1]) {
                        case 'A': return KEY_UP;
                        case 'B': return KEY_DOWN;
                        case 'C': return KEY_RIGHT;
                        case 'D': return KEY_LEFT;
                    }
                }
            }
            return KEY_ESC;
        }

        if (ch == 10) return KEY_ENTER; // Enter Linux
        return ch;
    }
#endif

void nhapMa(char* result, int maxLen);