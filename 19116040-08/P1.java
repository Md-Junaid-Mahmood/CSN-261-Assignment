import java.util.Scanner;

class node{
    int number;
    node leftChild;
    node rightChild;
}

class BinarySearchTree{
    node root = null;

    BinarySearchTree(int n){
        root = new node();
        root.number = n;
        root.leftChild = null;
        root.rightChild = null;
    }

    public node addLeftChild(node vertex, int n){
        node abc = new node();
        abc.number = n;
        abc.leftChild = null;
        abc.rightChild = null;
        vertex.leftChild = abc;
        return(abc);
    }

    public node addRightChild(node vertex, int n){
        node abc = new node();
        abc.number = n;
        abc.leftChild = null;
        abc.rightChild = null;
        vertex.rightChild = abc;
        return(abc);
    }
}

class P1{
    private static void sequenceCreator(int arr[], int start, int end, BinarySearchTree bst, node vertex){
        if(start >= end){
            return;
        }
        int mid = (int)((start + end)/2);

        
        int m1 = (int)((start + mid - 1)/2);
        if(m1 >= start && m1 != mid){
            node vt1 = new node();
            vt1 = bst.addLeftChild(vertex, arr[m1]);
            sequenceCreator(arr, start, mid - 1, bst, vt1);
        }

        int m2 = (int)((mid + 1 + end)/2);
        if(m2 != mid){
            node vt2 = new node();
            vt2 = bst.addRightChild(vertex, arr[m2]);
            sequenceCreator(arr, mid + 1, end, bst, vt2);
        } 
    }

    private static BinarySearchTree sequenceInitiator(int arr[], int start, int end){
        int r = (int)((start + end)/2);
        int root = arr[r];
        BinarySearchTree bst = new BinarySearchTree(root);

        sequenceCreator(arr, start, end, bst, bst.root);
        return(bst);
    }

    private static void sortArray(int n, int arr[]){
        int i;
        int j;
        for(i = 0; i < (n-1); i++){
            for(j = 0; j < (n-1); j++){
                if(arr[j + 1] < arr[j]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    private static void printSequence(int n, BinarySearchTree bst){
        node arr[] = new node[n];
        int front = 0; 
        int rear = 0;
        arr[front] = bst.root;
        front = front + 1;
        while(rear < front){
            node vt = arr[rear];
            if(vt.leftChild != null){
                arr[front] = vt.leftChild;
                front = front + 1;
            }
            if(vt.rightChild != null){
                arr[front] = vt.rightChild;
                front = front + 1;
            }
            rear = rear + 1;
        }
        for(rear = 0; rear < n; rear++){
            System.out.print(arr[rear].number + " ");
        }
        System.out.println("");
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        int i;
        for(i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }

        sortArray(n, arr);

        BinarySearchTree bst;
        bst = sequenceInitiator(arr, 0, n - 1);
        printSequence(n, bst);
    }
}