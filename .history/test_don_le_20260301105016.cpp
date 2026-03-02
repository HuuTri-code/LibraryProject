void Prim(int n, int A[][MAX]){
    int visited[MAX] = {0}; // Khởi tạo mảng visited để đánh dấu các đỉnh đã được chọn vào cây khung nhỏ nhất
    visited[1] = 1; // Bắt đầu từ đỉnh 1 (có thể chọn bất kỳ đỉnh nào làm điểm khởi đầu)
    int count = 1; // Đếm số lượng đỉnh đã được chọn vào cây khung nhỏ nhất

    while(count < n){
        int min = INF; 
        int x, y; // Biến x và y để lưu trữ cặp đỉnh có trọng số nhỏ nhất

        for(int i=1;i<=n;i++){
            if(visited[i]){ // Nếu đỉnh i đã được chọn vào cây khung nhỏ nhất
                for(int j=1;j<=n;j++){  // Duyệt qua tất cả các đỉnh j
                    if(!visited[j] && A[i][j] < min){ // Nếu đỉnh j chưa được chọn và trọng số của cạnh (i,j) nhỏ hơn min
                        min = A[i][j]; // Cập nhật min với trọng số nhỏ nhất mới
                        x = i; // Cập nhật x với đỉnh i
                        y = j; // Cập nhật y với đỉnh j
                    }
                }
            }
        }

        printf("(%d,%d) = %d\n", x,y,min);
        visited[y] = 1;
        count++;
    }
}