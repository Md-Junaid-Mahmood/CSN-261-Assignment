import java.util.*;
public class QuickSort{
    public void quickSort(int arr[]){
        int n = arr.length;
        partition(arr, 0, n - 1);
    }

    public void partition(int arr[], int start, int end){
        if(start >= end){
            return;
        }
        Random rand = new Random();
        int pos = rand.nextInt(end - start);
        pos += start;
        int temp = arr[pos];
        arr[pos] = arr[end];
        arr[end] = temp;

        int pivot = arr[end];
        int i = start;
        int j = end - 1;

        while(i <= j){
            while(i <= j && arr[i] < pivot){
                i++;
            }
            
            while(j >= i && arr[j] > pivot){
                j--;
            }
            if(j > i){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        arr[end] = arr[i];
        arr[i] = pivot;
        partition(arr, start, i - 1);
        partition(arr, i + 1, end);
    }

    public void printSorted(int arr[]){
        System.out.print("Sorted Array is: ");
        int n = arr.length;
        for(int i = 0; i < n; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size of the array: ");
        int n = sc.nextInt();

        int arrObject[] = new int[n];
        for(int i = 0; i < n; i++){
            System.out.print("Enter the " + (i + 1) + " element: ");
            arrObject[i] = sc.nextInt();
        }

        QuickSort qs = new QuickSort();
        qs.quickSort(arrObject);
        qs.printSorted(arrObject);
        sc.close();
    }
}
