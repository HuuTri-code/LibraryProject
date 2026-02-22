#pragma once

#include <iostream>

#define KEY_UP    1001
#define KEY_DOWN  1002
#define KEY_LEFT  1003
#define KEY_RIGHT 1004
#define KEY_ESC   27
#define KEY_ENTER 13

#ifdef _WIN32
    #include <conio.h>
    inline void setupConsole() {} // Windows không cần setup phức tạp
    inline void restoreConsole() {}

    inline int getKey() {
        int ch = _getch();
        if (ch == 0 || ch == 224) { // Phím đặc biệt trên Windows
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
    #include <stdio.h>

    static struct termios old_term;

    // Chuyển Terminal sang chế độ RAW (không đợi Enter, không hiện phím)
    inline void setupConsole() {
        tcgetattr(STDIN_FILENO, &old_term); // Lưu lại cấu hình hiện tại của Terminal để có thể khôi phục sau này
        struct termios new_term = old_term; // Tạo một bản sao của cấu hình hiện tại để chỉnh sửa
        new_term.c_lflag &= ~(ICANON | ECHO); // Tắt chế độ Canonical (đọc từng ký tự) và Echo (không hiển thị phím đã bấm)
        tcsetattr(STDIN_FILENO, TCSANOW, &new_term); // Áp dụng cấu hình mới ngay lập tức (TCSANOW) để Terminal hoạt động theo chế độ RAW.
        // raw là chế độ mà Terminal sẽ gửi dữ liệu ngay khi người dùng bấm phím, không cần phải đợi họ nhấn Enter, và cũng không hiển thị ký tự đã bấm trên màn hình.
    }

    // Trả lại chế độ bình thường cho Terminal
    inline void restoreConsole() {
        tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
    }

    inline int getKey() {
        char ch;
        if (read(STDIN_FILENO, &ch, 1) <= 0) return 0; // Đọc một ký tự từ Terminal, nếu có lỗi hoặc không đọc được thì trả về 0. < 0 là lỗi, = 0 là EOF (End of File)

        if (ch == 27) { // Bắt đầu chuỗi Escape (phím mũi tên trên Linux)
            char seq[3];
            // Nếu có chuỗi [A, [B... phía sau
            if (read(STDIN_FILENO, &seq[0], 1) > 0 && read(STDIN_FILENO, &seq[1], 1) > 0) { // Đọc tiếp 2 ký tự sau khi đọc được ESC, nếu không đọc được thì trả về KEY_ESC, ESC là phím thoát, nếu có chuỗi [A, [B... phía sau thì sẽ trả về phím mũi tên tương ứng.
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
        if (ch == 10) return KEY_ENTER; // Linux dùng 10 cho Enter
        return ch;
    }
#endif