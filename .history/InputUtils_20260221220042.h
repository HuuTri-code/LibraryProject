#pragma once

#ifdef _WIN32
    #include <conio.h>
    // Dùng inline để tránh lỗi trùng lặp khi include file .h nhiều nơi
    inline char getch_custom() {
        return _getch();
    }
#else
    #include <termios.h>
    #include <unistd.h>
    #include <iostream>

    inline char getch_custom() {
        char buf = 0;
        struct termios old; // Không gán {0} để tránh Warning

        // 1. Lấy thuộc tính hiện tại
        if (tcgetattr(STDIN_FILENO, &old) < 0) return 0;

        // 2. Tạo bản sao để chỉnh sửa
        struct termios newt = old;
        newt.c_lflag &= ~(ICANON | ECHO); // Tắt đợi Enter và tắt hiện phím

        // 3. Thiết lập chế độ mới
        if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) < 0) return 0;

        // 4. Đọc ký tự
        if (read(STDIN_FILENO, &buf, 1) < 0) buf = 0;

        // 5. QUAN TRỌNG: Khôi phục lại Y HỆT cấu hình gốc ban đầu
        tcsetattr(STDIN_FILENO, TCSANOW, &old);

        return buf;
    }
#endif
