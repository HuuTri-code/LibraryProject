void Prim(int n, int A[][MAX]){
    int visited[MAX] = {0}; // Khởi tạo mảng visited để đánh dấu các đỉnh đã được chọn vào cây khung nhỏ nhất
    visited[1] = 1; // Bắt đầu từ đỉnh 1 (có thể chọn bất kỳ đỉnh nào làm điểm khởi đầu)
    int count = 1; // Đếm số lượng đỉnh đã được chọn vào cây khung nhỏ nhất

    while(count < n){
        int min = INF;
        int x, y;

        for(int i=1;i<=n;i++){
            if(visited[i]){
                for(int j=1;j<=n;j++){
                    if(!visited[j] && A[i][j] < min){
                        min = A[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("(%d,%d) = %d\n", x,y,min);
        visited[y] = 1;
        count++;
    }
}