import java.util.*;

class P2{
    private static void topologicalSortInitiator(int n, int stack[], int mat[][]){
        int pos[] = new int[1];
        int val[] = new int[n];
        int i;
        for(i = 0; i < n; i++){
            if(val[i] == 1){
                continue;
            }else{
                topologicalSort(n, stack, pos, mat, val, i);
            }
        }
    }
    private static void topologicalSort(int n, int stack[], int pos[], int mat[][], int val[], int i){
        val[i] = 1;
        int j = 0;
        for(j = 0; j < n; j++){
            if(mat[i][j] == 1){
                if(val[j] == 0){
                    topologicalSort(n, stack, pos, mat, val, j);
                }
            }
        }
        stack[pos[0]] = i;
        pos[0] = pos[0] + 1;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mat[][] = new int[n][n];
        int i = 0;
        int j = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                mat[i][j] = sc.nextInt();
            }
        }
        int stack[] = new int[n];
        topologicalSortInitiator(n, stack, mat);
        for(i = n; i > 0; i--){
            System.out.print(stack[i-1] + " ");
        }
        System.out.println("");
    }
}