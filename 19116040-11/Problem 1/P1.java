import java.util.Scanner;

class P1{
    public static boolean check(int n, int mat[][]){
        int i, j;
        for(i = 0; i < n; i++){
            int count = 0;
            for(j = 0; j < n; j++){
                if(i != j && mat[i][j] == 1){
                    count = count + 1;
                }
            }
            if(count < 2){
                return(false);
            }
        }
        return(true);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int v = sc.nextInt();

        int mat[][] = new int[n][n];
        int i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                mat[i][j] = sc.nextInt();
            }
        }

        boolean val = check(n, mat);
        if(val == true){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

    }
}