import java.util.Scanner;

class P3{
    public static int countLevelInBFS(int n, int mat[][], int u){
        int AHouse = u - 1;
        int container[] = new int[n];
        container[AHouse] = 1;

        int queue[] = new int[n];
        int front = 0;
        int rear = 0;

        int level[] = new int[n];
        level[AHouse] = 0;

        int BHouse = n - 1;

        queue[front] = AHouse;
        front = front + 1;

        while(rear < front){
            int i = queue[rear];
            int j;
            for(j = 0; j < n; j++){
                if(container[j] == 0 && mat[i][j] == 1){
                    queue[front] = j;
                    front = front + 1;
                    level[j] = level[i] + 1;
                    container[j] = 1;
                }
            }
            rear = rear + 1;
        }
        
        return(level[BHouse]);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int v = sc.nextInt();
        int mat[][] = new int[n][n];
        int i;
        for(i = 0; i < v; i++){
            int r1 = sc.nextInt();
            int r2 = sc.nextInt();
            r1 = r1 - 1;
            r2 = r2 - 1;
            mat[r1][r2] = 1;
            mat[r2][r1] = 1;
        }

        int q = sc.nextInt();
        for(i = 0; i < q; i++){
            int u = sc.nextInt();
            int level = countLevelInBFS(n, mat, u);
            if(level == 0){
                System.out.println("impossible");
            }else{
                System.out.println("" + level);
            }
        }
    }
}