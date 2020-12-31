import java.util.Scanner;

class P1 {
    private static String converter(int n){
        String s = new String();
        while(n != 0){
            if(n%2 == 0){
                s = s + "0";
            }else{
                s = s + "1";
            }
            n = (int)(n/2);
        }
        return(s);
    }

    private static void performBFS(int n, int arr[][]){
        int container[] = new int[n];
        String bfs = new String();
        bfs = getBFS(n, arr, container, 0);

        int len = bfs.length();

        System.out.print("BFS: ");
        int w = 0;
        int j;
        for(j = 0; j < len; j++){
            if(bfs.charAt(j) == '0'){
                if(w == 0){
                    w = 1;
                    System.out.print(bfs.charAt(j) + " ");
                }
            }else{
                System.out.print(bfs.charAt(j) + " ");
            }
        }

        System.out.println("");
    }

    private static void performDFS(int n, int arr[][]){
        int container[] = new int[n];

        String dfs = new String();
        dfs = getDFS(n, arr, container, 0);

        int len = dfs.length();

        System.out.print("DFS: ");
        int w = 0;
        int j;
        for(j = 0; j < len; j++){
            if(dfs.charAt(j) == '0'){
                if(w == 0){
                    w = 1;
                    System.out.print(dfs.charAt(j) + " ");
                }
            }else{
                System.out.print(dfs.charAt(j) + " ");
            }
        }

        System.out.println("");

    }

    private static String getBFS(int n, int arr[][], int container[], int start){
        int queue[] = new int[n];
        int front = 0;
        int rear = 0;
        queue[front] = start;
        front = front + 1;

        container[start] = 1;

        while(rear < front){
            int i;
            for(i = 0; i < n; i++){
                if(arr[queue[rear]][i] == 1){
                    if(container[i] == 0){
                        container[i] = 1;
                        queue[front] = i;
                        front = front + 1;
                    }
                }
            }
            rear = rear + 1;
        }

        int j;
        String s = new String();
        for(j = 0; j < n; j++){
            s = s + queue[j];
        }
        for(j = 0; j < n; j++){
            if(container[j] == 0){
                s = s + getBFS(n, arr, container, j);
            }
        }
        return(s);
    }

    private static String getDFS(int n, int arr[][], int container[], int start){
        int stack[] = new int[n];
        int top = 0;

        stack[top] = start;
        top = top + 1;

        int storage[] = new int[n];
        int count = 0;
        storage[count] = start;
        count = count + 1;

        container[start] = 1;

        while(top > 0){
            int w = 0;
            int num = stack[top - 1];
            int i;
            for(i = 0; i < n; i++){
                if(arr[num][i] == 1){
                    if(container[i] == 0){
                        container[i] = 1;
                        stack[top] = i;
                        top = top + 1;
                        w = 1;

                        storage[count] = i;
                        count = count + 1;
                        break;
                    }
                }
            }
            if(w == 0){
                top = top - 1;
            }
        }

        String s = new String();
        for(top = 0; top < n; top++){
            s = s + storage[top];
        }
        for(top = 0; top < n; top++){
            if(container[top] == 0){
                s = s + getDFS(n, arr, container, top);
            }
        }
        return(s);
    }

    private static int calculateNumberOfEdges(int n, int arr[][]){
        int i, j;
        int num = 0;
        for(i = 0; i < n; i++){
            for(j = i; j < n; j++){
                if(arr[i][j] == 1){
                    num = num + 1;
                }
            }
        }
        return(num);
    }

    private static int calculateNumberOfEdges(int n, int arr[][], int rowColumn[][]){
        int i, j;
        int num = 0;
        for(i = 0; i < n; i++){
            for(j = i; j < n; j++){
                if(arr[i][j] == 1){
                    rowColumn[num][0] = i;
                    rowColumn[num][1] = j;
                    num = num + 1;
                }
            }
        }
        return(num);
    }

    private static void minimumDeletion(int n, int brr[][]){
        int number = calculateNumberOfEdges(n, brr);
        int rowColumn[][] = new int[number][2];
        number = calculateNumberOfEdges(n, brr, rowColumn);

        int count = (int)Math.pow(2, number);

        int finalCount = number;
        int finalArr[] = new int[number];

        int tempCount = 0;
        int tempArr[] = new int[number];

        int i;
        for(i = 0; i < count; i++){
            String s = new String();
            s = converter(i);

            int len = s.length();
            int j;
            for(j = 0; j < len; j++){
                if(s.charAt(j) == '1'){
                    int row = rowColumn[j][0];
                    int column = rowColumn[j][1];
                    brr[row][column] = 0;
                    brr[column][row] = 0;
                    tempArr[tempCount] = j;
                    tempCount = tempCount + 1;
                }
            }

            if(tempCount > finalCount){
                for(j = 0; j < len; j++){
                    if(s.charAt(j) == '1'){
                        int row = rowColumn[j][0];
                        int column = rowColumn[j][1];
                        brr[row][column] = 1;
                        brr[column][row] = 1;
                    }
                }
                for(j = 0; j < tempCount; j++){
                    tempArr[j] = 0;
                }
                tempCount = 0;
                continue;
            }

            String bfs = new String();
            String dfs = new String();

            int cont1[] = new int[n];
            int cont2[] = new int[n];

            bfs = getBFS(n, brr, cont1, 0);
            dfs = getDFS(n, brr, cont2, 0);
            

            for(j = 0; j < len; j++){
                if(s.charAt(j) == '1'){
                    int row = rowColumn[j][0];
                    int column = rowColumn[j][1];
                    brr[row][column] = 1;
                    brr[column][row] = 1;
                }
            }

            if(bfs.equals(dfs)){
                if(tempCount < finalCount){
                    finalCount = tempCount;
                    int z;
                    for(z = 0; z < tempCount; z++){
                        finalArr[z] = tempArr[z];
                    }
                }
            }

            int z;
            for(z = 0; z < tempCount; z++){
                tempArr[z] = 0;
            }
            tempCount = 0;
        }

        System.out.println(finalCount);
        int z;
        for(z = 0; z < finalCount; z++){
            int numb = finalArr[z];
            System.out.println(rowColumn[numb][0] + " " + rowColumn[numb][1]);
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int mat[][] = new int[n][n];
        int i,j;

        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                mat[i][j] = sc.nextInt();
            }
        }

        performBFS(n, mat);
        performDFS(n, mat);

        minimumDeletion(n, mat);
    }
}