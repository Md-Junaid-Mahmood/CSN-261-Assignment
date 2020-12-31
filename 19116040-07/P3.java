import java.util.Scanner;

class P3{
    private static void sortArray(int arr[], int n){
        int i;
        int j;
        for(i = 0; i < n; i++){
            for(j = (i + 1); j < n; j++){
                if(arr[j] < arr[i]){
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }

    private static void inOrderTraversal(int arr[], int crr[], int n, int i, int pos[]){
        int j = 2*i + 1;
        if(j < n){
            inOrderTraversal(arr, crr, n, j, pos);
        }

        crr[pos[0]] = arr[i];
        pos[0] = pos[0] + 1;

        j = 2*i + 2;
        if(j < n){
            inOrderTraversal(arr, crr, n, j, pos);
        }
    }

    private static void inOrderTraversalInitiator(int arr[], int crr[], int n){
        int pos[] = new int[1];
        pos[0] = 0;
        inOrderTraversal(arr, crr, n, 0, pos);
    }

    private static int getIndex(int arr[], int n, int key){
        int i;
        for(i = 0; i < n; i++){
            if(arr[i] == key){
                return(i);
            }
        }
        return(n);
    }

    private static int numberOfSwaps(int arr[], int sortArr[], int n){
        int i;
        int swap1 = 0;
        int swap2 = -1;
        for(i = 0; i < n; i++){
            if(arr[i] != sortArr[i]){
                int j = getIndex(sortArr, n, arr[i]);
                if(arr[j] == sortArr[i]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    swap1 = swap1 + 1;
                }else{
                    swap2 = swap2 + 1;
                }
            }
        }
        if(swap2 == -1){
            swap2 = 0;
        }
        int swap = swap1 + swap2;
        return(swap);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i;
        int arr[] = new int[n];
        int brr[] = new int[n];
        int crr[] = new int[n];

        for(i = 0; i < n; i++){
            arr[i] = sc.nextInt();
            brr[i] = arr[i];
        }

        sortArray(brr, n);
        inOrderTraversalInitiator(arr, crr, n);

        int swap = numberOfSwaps(crr, brr, n);
        System.out.println("" + swap);
    }
}