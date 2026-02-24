#include <iostream>
#include <cctype>
#include <cstring>
#include "InputUtils.h" // Đảm bảo file này có hàm getch_custom() mình đã viết ở trên

using namespace std;

void nhapMa(char* result, int maxLen)
{
    int length = 0;
    // Đảm bảo chuỗi rỗng ban đầu
    result[0] = '\0';

    while (true)
    {
        // Gọi hàm bắt phím hệ thống (Linux/Windows)
        char c = getch_custom(); 

        // 1. Xử lý Enter (Kết thúc nhập)
        // ASCII 10 là \n (Linux), 13 là \r (Windows)
        if (c == 10 || c == 13) 
        {
            if (length > 0) { // Phải nhập ít nhất 1 ký tự mới cho xong
                result[length] = '\0';
                cout << endl;
                return;
            }
            continue; // Nếu chưa nhập gì mà ấn Enter thì lờ đi
        }

        // 2. Xử lý Backspace (Xóa ký tự)
        // ASCII 8 là Backspace, 127 là Delete/Backspace trên một số bản Linux
        if ((c == 8 || c == 127) && length > 0)
        {
            length--;
            // Lùi con trỏ - Ghi đè khoảng trắng - Lùi con trỏ lại
            cout << "\b \b"; 
            continue;
        }

        // 3. Xử lý ký tự hợp lệ (Chữ, Số, -, _)
        if (isalnum(c) || c == '-' || c == '_')
        {
            // Kiểm tra giới hạn (trừ 1 cho ký tự kết thúc '\0')
            if (length < maxLen - 1)
            {
                if (isalpha(c))
                    c = toupper(c); // Tự động viết hoa

                result[length] = c;
                length++;
                cout << c; // In ra màn hình cho người dùng thấy
            }
        }
    }
}
