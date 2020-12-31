import java.util.Scanner;

class P4{
    public static int calculateExplosives(int n, int mat[][]){
        boolean val = true;
        int count = 0;
        while(val){
            int index = 0;
            int subCount = 0;
            int i;
            for(i = 0; i < n; i++){
                if(mat[0][i] == 1){
                    subCount = subCount + 1;
                }
            }
            for(i = 1; i < n; i++){
                int j;
                int tempCount = 0;
                for(j = 0; j < n; j++){
                    if(mat[i][j] == 1){
                        tempCount = tempCount + 1;
                    }
                }
                if(tempCount > subCount){
                    subCount = tempCount;
                    index = i;
                }
            }
            for(i = 0; i < n; i++){
                mat[index][i] = 0;
                mat[i][index] = 0;
            }
            if(subCount == 0){
                val = false;
            }else{
                count = count + 1;
            }
        }

        return(count);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int mat[][] = new int[n][n];

        int i;
        for(i = 0; i < m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();

            u = u - 1;
            v = v - 1;

            mat[u][v] = 1;
            mat[v][u] = 1;
        }

        int count = calculateExplosives(n, mat);
        System.out.println("" + count);
    }
}