import java.util.*;
public class HeapSort{
    public static void printSorted(ArrayList<Integer> arr){
        System.out.print("Sorted Array is: ");
        int n = arr.size();
        for(int i = 0; i < n; i++){
            System.out.print(arr.get(i) + " ");
        }
        System.out.println("");
    }
    public static void main(String args[]){
        Heap heap = new Heap();
    
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size of the array: ");
        int n = sc.nextInt();

        for(int i = 0; i < n; i++){
            System.out.print("Enter the " + (i + 1) + " element: ");
            heap.initialAdd(sc.nextInt());
        }
        sc.close();

        int mid = (int)(n/2);
        for(int i = mid; i >= 0; i--){
            heap.heapify(i);
        }

        ArrayList<Integer> ret = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            ret.add(heap.poll());
        }

        printSorted(ret);
    }
}