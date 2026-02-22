#include <iostream>
#include "InputUtils.h" // Chứa getch_custom
// Nếu bạn để hàm nhapMa ở file Sach.h hoặc InputUtils.h thì include nó vào
// Ở đây giả sử nhapMa được khai báo trong một file .h nào đó của bạn
void nhapMa(char* result, int maxLen); 

using namespace std;

int main() {
    char testMa[20]; // Phải là mảng char chứ không phải char đơn
    cout << "Nhap ma sach test: ";
    nhapMa(testMa, 20);
    cout << "Ket qua sau khi nhap: [" << testMa << "]" << endl;
    return 0;
}
