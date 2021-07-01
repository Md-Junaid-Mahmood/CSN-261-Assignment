import java.util.*;
public class HuffmanCode {
    public static HashMap<Integer, Integer> print(Node node){
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        Queue<Node> queue = new ArrayDeque<Node>();
        Queue<Integer> path = new ArrayDeque<Integer>();
        queue.add(node);
        path.add(1);
        while(!queue.isEmpty()){
            Node current = queue.poll();
            int length = path.poll();
            if(current.code == 'X'){
                if(current.leftReserved != null){
                    queue.add(current.leftReserved);
                    path.add(2*length);
                }
                if(current.rightReserved != null){
                    queue.add(current.rightReserved);
                    path.add(2*length + 1);
                }
            }else{
                map.put((int)(current.code), length);
                //System.out.println("Code for " + current.code + " is " + length);
            }
        }
        return(map);
    }

    /*
        int n = 7;
        HeapTree heap = new HeapTree(10, 'A');
        heap.add(20, 'B');
        heap.add(35, 'C');
        heap.add(15, 'D');
        heap.add(45, 'E');
        heap.add(50, 'F');
        heap.add(5, 'G');
    */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number Of Distinct Code: ");
        int n = sc.nextInt();

        System.out.print("Enter 1 code: ");
        sc.nextLine();
        String str = sc.nextLine();
        char ch1 = str.charAt(0);
        System.out.print("Enter 1 code\'s frequence: ");
        int freq1 = sc.nextInt();
        HeapTree heap = new HeapTree(freq1, ch1);

        for(int i = 1; i < n; i++){
            System.out.print("Enter " + (i + 1) + " code: ");
            sc.nextLine();
            str = sc.nextLine();
            char ch = str.charAt(0);
            System.out.print("Enter " + (i + 1) + " code\'s frequence: ");
            int freq = sc.nextInt();
            heap.add(freq, ch);
        }
        sc.close();

        for(int i = 1; i < n; i++){
            heap.pollAndInsert();
        }

        Node node = heap.getTree();
        HashMap<Integer, Integer> map = print(node);
        int arr[] = new int[26];
        for(int i = 0; i < 26; i++){
            arr[i] = 0;
        }

        for(Integer key: map.keySet()){
            int length = map.get(key);
            int k = key;
            arr[k - 65] = length;
        }

        for(int i = 0; i < 26; i++){
            if(arr[i] != 0){
                System.out.println("Code for " + (char)(i + 65) + " is " + arr[i]);
            }
        }
    }
}
