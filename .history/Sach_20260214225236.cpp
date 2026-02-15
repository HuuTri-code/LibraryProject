#include "Sach.h"
using namespace std;

int timViTriChen(ListDauSach ds, const char* tenSach) {
    int left = 0;
    int right = ds.n - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1); // phep dich phai <-> chia, cho ngau.
        int cmp = strcmp(ds.nodes[mid]->tenSach, tenSach);

        if (cmp == 0)
            return mid;
        else if (cmp)
    }
}