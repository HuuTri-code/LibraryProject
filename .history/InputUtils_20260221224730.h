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

    static struct termios old_term;

    inline void setupConsole() {
        tcgetattr(STDIN_FILENO, &old_term);
        struct termios new_term = old_term;
        new_term.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
    }

    inline void restoreConsole() {
        tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
    }

    inline int getch_raw() {
        char ch;
        if (read(STDIN_FILENO, &ch, 1) <= 0) return 0;
        return ch;
    }

    inline int getKey() {
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
