import java.util.Scanner;

class P2{
    public static int getMaximumBandWidth(int n, int mat[][], int start, int end){
        int storage[][] = new int[n][n];
        int i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                storage[i][j] = -1;
            }
        }
        int container[] = new int[n];
        container[start] = 1;
        int count = 0;

        for(i = 0; i < n; i++){
            if(mat[start][i] > 0){
                storage[count][i] = mat[start][i];
            }
        }
        count = count + 1;

        while(start != end){
            start = end;
            for(i = 0; i < n; i++){
                if(container[i] == 0 && (storage[count - 1][i] > storage[count - 1][start])){
                    start = i;
                }
            }
            container[start] = 1;
            for(i = 0; i < n; i++){
                if(mat[start][i] > 0 && container[i] == 0){
                    if(Math.min(storage[count - 1][start], mat[start][i]) > storage[count - 1][i]){
                        storage[count][i] = Math.min(storage[count - 1][start], mat[start][i]);
                    }else{
                        storage[count][i] = storage[count - 1][i];
                    }
                }else{
                    storage[count][i] = storage[count - 1][i];
                }
            }
            count = count + 1;
        }

        return(storage[count - 1][end]);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int mat[][] = new int[n][n];
        int i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                mat[i][j] = sc.nextInt();
            }
        }
        String a = new String();
        String b = new String();

        sc.nextLine();
        a = sc.nextLine();
        b = sc.nextLine();

        char begin = a.charAt(0);
        char finish = b.charAt(0);

        int start = (int)(begin);
        int end = (int)(finish);

        start = start - 65;
        end = end - 65;

        int value = getMaximumBandWidth(n, mat, start, end);
        System.out.println("" + value);
    }
}