import java.util.*;
public class MergeSort{
    public void mergeSort(int arr[]){
        int n = arr.length;
        partition(arr, 0, n - 1);
        return;
    }

    public void partition(int arr[], int start, int end){
        if(start >= end){
            return;
        }
        int mid = (int)((start + end)/2);
        partition(arr, start, mid);
        partition(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    public void merge(int arr[], int start, int mid, int end){
        int i = start;
        int j = mid + 1;
        int ret[] = new int[end - start + 1];
        int counter = 0;
        while(i <= mid && j <= end){
            if(arr[i] < arr[j]){
                ret[counter] = arr[i];
                i++;
            }else{
                ret[counter] = arr[j];
                j++;
            }
            counter++;
        }
        while(i <= mid){
            ret[counter] = arr[i];
            i++;
            counter++;
        }
        while(j <= end){
            ret[counter] = arr[j];
            j++;
            counter++;
        }
        for(i = 0; i < counter; i++){
            arr[start + i] = ret[i];
        }
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

        MergeSort ms = new MergeSort();
        ms.mergeSort(arrObject);
        ms.printSorted(arrObject);
        sc.close();
    }
}
