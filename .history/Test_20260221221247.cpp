#include "Console.h"
#include <iostream>

using namespace std;

int main() {
    setupConsole(); // Bật chế độ "nhạy" một lần duy nhất ở đầu

    cout << "--- TEST CONSOLE MUOT (Nhan ESC de thoat) ---\n";
    cout << "Hay bam cac phim mui ten hoac phim bat ky...\n";

    while (true) {
        int k = getKey();

        if (k == KEY_ESC) break;

        if (k == KEY_UP)    cout << ">> Ban vua bam: LEN\n";
        else if (k == KEY_DOWN)  cout << ">> Ban vua bam: XUONG\n";
        else if (k == KEY_LEFT)  cout << ">> Ban vua bam: TRAI\n";
        else if (k == KEY_RIGHT) cout << ">> Ban vua bam: PHAI\n";
        else if (k == KEY_ENTER) cout << ">> Ban vua bam: ENTER\n";
        else {
            cout << ">> Phim khac: " << (char)k << " (Ma: " << k << ")\n";
        }
    }

    restoreConsole(); // QUAN TRONG: Phải trả lại chế độ cũ cho Ubuntu trước khi thoát
    cout << "Da thoat va khoi phuc Terminal.\n";
    return 0;
}