import java.util.*;
public class HeapSortUsingTree {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size Of The Array: ");
        int n = sc.nextInt();
        
        System.out.print("Enter 1 Number: ");
        HeapTree heap = new HeapTree(sc.nextInt());
        for(int i = 1; i < n; i++){
            System.out.print("Enter " + (i + 1) + " Number: ");
            heap.add(sc.nextInt());
        }
        sc.close();

        ArrayList<Integer> ret = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            ret.add(heap.poll());
        }
        System.out.println("Sorted Array is: " + ret);

    }
}
