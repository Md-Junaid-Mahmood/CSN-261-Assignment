import java.util.Scanner;
class P1{
    private static void minimumNumberOfNode(int arr[], int n){
        arr[0] = 1;
        arr[1] = 2;
        if(n == 0){
            arr[2] = 1;
        }else if(n == 1){
            arr[2] = 2;
        }else{
            int i = 2;
            while(i <= n){
                arr[2] = 1 + arr[1] + arr[0];
                arr[0] = arr[1];
                arr[1] = arr[2];
                i = i + 1;
            }
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int height = sc.nextInt();
        int arr[] = new int[3];
        minimumNumberOfNode(arr, height);
        int output = arr[2];
        System.out.println("" + output);
    }
}