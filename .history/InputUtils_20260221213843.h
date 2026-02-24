#pragma once

#ifdef _WIN32
    #include <conio.h>
    char getch_custom() {
        return _getch();
    }
#else
    #include <termios.h>
    #include <unistd.h>

    char getch_custom() {
        char buf = 0;
        struct termios old = {0};

        if (tcgetattr(0, &old) < 0) return 0;

        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;

        if (tcsetattr(0, TCSANOW, &old) < 0) return 0;

        if (read(0, &buf, 1) < 0) return 0;

        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;

        tcsetattr(0, TCSANOW, &old);

        return buf;
    }
#endif
