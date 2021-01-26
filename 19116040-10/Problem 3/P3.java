import java.util.Scanner;

class P3{
    public static void findTheRooms(int mat[][], int nodes, int edges, int start){
        int i, j;
        int container[] = new int[nodes];

        int maxCount = 0;

        int queue[] = new int[edges + 1];
        int rear = 0;
        int front = 0;

        queue[front] = start;
        front = front + 1;

        while(rear < front){
            i = queue[rear];
            int w = 0;
            for(j = 0; j < nodes; j++){
                if(mat[i][j] == 1){
                    w = 1;
                    queue[front] = j;
                    front = front + 1;
                }
            }
            if(w == 0){
                container[i] = container[i] + 1;
                if(container[i] > maxCount){
                    maxCount = container[i];
                }
            }
            rear = rear + 1;
        }

        for(i = 0; i < nodes; i++){
            if(container[i] == maxCount){
                j = i + 1;
                System.out.print(j + " ");
            }
        }

        System.out.println("");
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int r = sc.nextInt();

        int mat[][] = new int[n][n];

        int i;
        for(i = 0; i < m; i++){
            int r1 = sc.nextInt();
            int r2 = sc.nextInt();

            mat[r1 - 1][r2 - 1] = 1;
        }

        findTheRooms(mat, n, m, r - 1);

    }
}