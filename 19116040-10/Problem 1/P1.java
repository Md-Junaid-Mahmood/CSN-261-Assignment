import java.util.Scanner;

class P1{
    private static void doBFS(int mat[][], int row, int column, int total, int nodes){
        int queue[][] = new int[total][2];
        int front = 0;
        int rear = 0;

        queue[front][0] = row;
        queue[front][1] = column;

        front = front + 1;

        int arr[][] = new int[nodes][nodes];

        while(rear < front){
            int r = queue[rear][0];
            int c = queue[rear][1];
            arr[r][c] = 1;

            if(r > 0){
                if(c > 0 && mat[r - 1][c - 1] == 1 && arr[r - 1][c - 1] != 1){
                    queue[front][0] = r - 1;
                    queue[front][1] = c - 1;

                    arr[r - 1][c - 1] = 1;

                    front = front + 1;
                }

                if(mat[r - 1][c] == 1 && arr[r - 1][c] != 1){
                    queue[front][0] = r - 1;
                    queue[front][1] = c;

                    arr[r - 1][c] = 1;

                    front = front + 1;
                }

                if(c < (nodes - 1) && mat[r - 1][c + 1] == 1 && arr[r - 1][c + 1] != 1){
                    queue[front][0] = r - 1;
                    queue[front][1] = c + 1;

                    arr[r - 1][c + 1] = 1;

                    front = front + 1;
                }
            }

            if(r < (nodes - 1)){
                if(c > 0 && mat[r + 1][c - 1] == 1 && arr[r + 1][c - 1] != 1){
                    queue[front][0] = r + 1;
                    queue[front][1] = c - 1;

                    arr[r + 1][c - 1] = 1;

                    front = front + 1;
                }

                if(mat[r + 1][c] == 1 && arr[r + 1][c] != 1){
                    queue[front][0] = r + 1;
                    queue[front][1] = c;

                    arr[r + 1][c] = 1;

                    front = front + 1;
                }

                if(c < (nodes - 1) && mat[r + 1][c + 1] == 1 && arr[r + 1][c + 1] != 1){
                    queue[front][0] = r + 1;
                    queue[front][1] = c + 1;

                    arr[r + 1][c + 1] = 1;

                    front = front + 1;
                }
            }

            if(true){
                if(c > 0 && mat[r][c - 1] == 1 && arr[r][c - 1] != 1){
                    queue[front][0] = r;
                    queue[front][1] = c - 1;

                    arr[r][c - 1] = 1;

                    front = front + 1;
                }

                if(c < (nodes - 1) && mat[r][c + 1] == 1 && arr[r][c + 1] != 1){
                    queue[front][0] = r;
                    queue[front][1] = c + 1;

                    arr[r][c + 1] = 1;

                    front = front + 1;
                }
            }

            rear = rear + 1;
        }

        for(rear = 0; rear < front; rear++){
            int r = queue[rear][0];
            int c = queue[rear][1];

            mat[r][c] = 0;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int mat[][] = new int[n][n];

        int i, j;
        int total = 0;
        int count = 0;

        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                mat[i][j] = sc.nextInt();
                if(mat[i][j] == 1){
                    total = total + 1;
                }
            }
        }

        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    doBFS(mat, i, j, total, n);
                    count = count + 1;
                }
            }
        }

        System.out.println("" + count);
    }
}