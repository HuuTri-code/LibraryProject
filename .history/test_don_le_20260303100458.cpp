#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define TRUE 1
#define FALSE 0

// Ham doc ma tran tu file
void Init(int A[][MAX], int *n) {
    int i, j;
    FILE *fp;
    fp = fopen("DDEULER.IN", "r");
    if (fp == NULL) {
        printf("Khong tim thay file du lieu!");
        return;
    }
    fscanf(fp, "%d", n); // Doc so dinh cua do thi
    for (i = 1; i <= *n; i++) {
        for (j = 1; j <= *n; j++) {
            fscanf(fp, "%d", &A[i][j]); // Doc ma tran ke
        }
    }
    fclose(fp);
}

// Ham kiem tra dieu kien co duong di Euler (Co dung 2 dinh bac le)
int Kiemtra(int A[][MAX], int n, int *u) {
    int i, j, s, d = 0;
    for (i = 1; i <= n; i++) {
        s = 0; 
        for (j = 1; j <= n; j++) {
            s += A[i][j]; // Tinh tong hang de tim bac cua dinh i
        }
        if (s % 2 != 0) {
            d++;    // so dinh bac le thi tang bien dem d len 1
            *u = i; // Luu lai dinh bac le de lam diem bat dau
        }
    }
    if (d != 2) return FALSE; // Neu so dinh bac le khac 2 thi khong co duong di
    return TRUE;
}

// Thuat toan tim duong di Euler bang Stack
void DDEULER(int A[][MAX], int n, int u) {
    int v, x, top, dCE;
    int stack[MAX], CE[MAX]; // Stack de luu dinh dang xet va mang CE de luu ket qua duong di Euler
    top = 1; // Khoi tao Stack voi dinh bat dau u
    stack[top] = u; // Day dinh bat dau vao Stack
    dCE = 0;
    do {
        v = stack[top]; // Lay dinh o dinh Stack de xet
        x = 1; // Khoi tao x de tim canh noi v voi x, cho 

        while (x <= n && A[v][x] == 0) x++;
        
        if (x > n) { // Neu dinh v khong con canh noi nao nua
            dCE++; 
            CE[dCE] = v; // Dua v vao ket qua duong di
            top--;       // Lay v ra khoi Stack
        } else { // Neu con canh noi (v, x)
            top++; 
            stack[top] = x; // Day x vao Stack
            A[v][x] = 0;    // Xoa canh (v, x) de khong di qua nua
            A[x][v] = 0;    // Doi voi do thi vo huong, xoa luon chieu nguoc lai
        }
    } while (top != 0);

    // In ket qua ra man hinh (In nguoc tu trong mang CE)
    printf("\nCo duong di Euler: ");
    for (x = dCE; x > 0; x--) {
        printf("%3d", CE[x]);
    }
}

int main() {
    int A[MAX][MAX], n, u;
    Init(A, &n);
    if (Kiemtra(A, n, &u)) {
        DDEULER(A, n, u); // Neu thoa man thi tim va in duong di
    } else {
        printf("\nKhong co duong di Euler");
    }
    return 0;
}
