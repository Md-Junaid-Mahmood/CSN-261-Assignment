import java.util.Scanner;

class NodeBTree{
    int currentKey;
    int keys[];
    NodeBTree childPointers[];
    int minimumValue;
    boolean isLeaf;

    public NodeBTree(int val, boolean x){
        keys = new int[2*val];
        childPointers = new NodeBTree[2*val + 1];
        currentKey = 0;
        minimumValue = val;
        isLeaf = x;
    }
}

class BTree{
    NodeBTree root;
    int minimumValueTree;

    public static int numberOfSplitOperations;
    public static int numberOfMergeOperations;

    public BTree(int x){
        minimumValueTree = x;
        root = null;
        numberOfSplitOperations = 0;
        numberOfMergeOperations = 0;
    }

    public NodeBTree findParent(NodeBTree node, int q){
        NodeBTree arr[] = new NodeBTree[q];
        
        int front = 0;
        int rear = 0;
        arr[front] = root;
        front = front + 1;

        while(rear < front){
            int n = arr[rear].currentKey;
            int i;
            for(i = 0; i <= n; i++){
                if(arr[rear].isLeaf == false){
                    if(arr[rear].childPointers[i] == node){
                        return(arr[rear]);
                    }else{
                        arr[front] = arr[rear].childPointers[i];
                        front = front + 1;
                    }
                }
            }
            rear = rear + 1;
        }

        return(null);
    }

    public void insert(int k, int q){
        if(root == null){
            NodeBTree node = new NodeBTree(minimumValueTree, true);
            node.currentKey = 1;
            node.keys[0] = k;
            root = node;
        }else{
            NodeBTree node = root;
            while(node.isLeaf != true){
                int n = node.currentKey;
                int i;
                for(i = 0; i < n; i++){
                    if(node.keys[i] > k){
                        break;
                    }
                }
                node = node.childPointers[i];
            }
            int n = node.currentKey;
            int j;
            for(j = n - 1; j >= 0; j--){
                if(node.keys[j] > k){
                    node.keys[j + 1] = node.keys[j];
                }else{
                    break;
                }
            }
            j = j + 1;
            node.keys[j] = k;
            node.currentKey = node.currentKey + 1;
            if(node.currentKey == 2*minimumValueTree){
                splitTree(node, q);
            }
        }
    }

    public void splitTree(NodeBTree node, int q){
        numberOfSplitOperations = numberOfSplitOperations + 1;
        if(node == root){
            NodeBTree node1 = new NodeBTree(minimumValueTree, node.isLeaf);
            NodeBTree node2 = new NodeBTree(minimumValueTree, node.isLeaf);

            int n = node.currentKey;
            int i;

            for(i = 0; i < minimumValueTree - 1; i++){
                node1.keys[i] = node.keys[i];
                node1.childPointers[i] = node.childPointers[i];
                node1.currentKey = node1.currentKey + 1;
            }
            node1.childPointers[i] = node.childPointers[i];

            for(i = minimumValueTree; i < n; i++){
                node2.keys[i - minimumValueTree] = node.keys[i];
                node2.childPointers[i - minimumValueTree] = node.childPointers[i];
                node2.currentKey = node2.currentKey + 1;
            }
            node2.childPointers[i - minimumValueTree] = node.childPointers[i];

            NodeBTree parent = new NodeBTree(minimumValueTree, false);
            parent.keys[0] = node.keys[minimumValueTree - 1];
            parent.currentKey = 1;
            parent.childPointers[0] = node1;
            parent.childPointers[1] = node2;

            root = parent;
        }else{
            NodeBTree node1 = new NodeBTree(minimumValueTree, node.isLeaf);
            NodeBTree node2 = new NodeBTree(minimumValueTree, node.isLeaf);

            int n = node.currentKey;
            int i;

            for(i = 0; i < minimumValueTree - 1; i++){
                node1.keys[i] = node.keys[i];
                node1.childPointers[i] = node.childPointers[i];
                node1.currentKey = node1.currentKey + 1;
            }
            node1.childPointers[i] = node.childPointers[i];

            for(i = minimumValueTree; i < n; i++){
                node2.keys[i - minimumValueTree] = node.keys[i];
                node2.childPointers[i - minimumValueTree] = node.childPointers[i];
                node2.currentKey = node2.currentKey + 1;
            }
            node2.childPointers[i - minimumValueTree] = node.childPointers[i];

            NodeBTree parent = findParent(node, q);
            n = parent.currentKey;
            int j;
            for(j = n - 1; j >= 0; j--){
                if(parent.keys[j] > node.keys[minimumValueTree]){
                    parent.keys[j + 1] = parent.keys[j];
                    parent.childPointers[j + 2] = parent.childPointers[j + 1];
                }else{
                    break;
                }
            }
            j = j + 1;
            parent.keys[j] = node.keys[minimumValueTree - 1];
            parent.childPointers[j] = node1;
            parent.childPointers[j + 1] = node2;
            parent.currentKey = parent.currentKey + 1;
            if(parent.currentKey == 2*minimumValueTree){
                splitTree(parent, q);
            }
        }
    }

    public void traverse(NodeBTree node){
        int n = node.currentKey;
        int i;
        for(i = 0; i < n; i++){
            if(node.isLeaf == false){
                traverse(node.childPointers[i]);
            }
            System.out.print(node.keys[i] + " ");
        }

        if(node.isLeaf == false){
            traverse(node.childPointers[i]);
        }
    }

    public void traverseInitiator(){
        System.out.print("In order traversal of B Tree: ");
        traverse(root);
        System.out.println("");
    }

    public NodeBTree search(int k, int q){
        NodeBTree arr[] = new NodeBTree[q];
        int front = 0;
        int rear = 0;
        arr[front] = root;
        front = front + 1;

        while(rear < front){
            int n = arr[rear].currentKey;
            int i;
            for(i = 0; i < n; i++){
                if(arr[rear].keys[i] == k){
                    return(arr[rear]);
                }
            }
            
            if(arr[rear].isLeaf == false){
                for(i = 0; i <= n; i++){
                    arr[front] = arr[rear].childPointers[i];
                    front = front + 1;
                }
            }

            rear = rear + 1;
        }

        return(null);
    }

    public boolean check(int k, int q){
        NodeBTree node = search(k, q);
        if(node == null){
            return(true);
        }else{
            return(false);
        }
    }

    public void delete(int k, int q){
        NodeBTree node = search(k, q);
        if(node == null){
            System.out.println("Given element does not exist");
            return;
        }

        if(node.isLeaf == true){
            if(node.currentKey > 1){
                int i;
                int n = node.currentKey;
                for(i = 0; i < n; i++){
                    if(node.keys[i] == k){
                        break;
                    }
                }
                int j;
                for(j = i; j < (n - 1); j++){
                    node.keys[j] = node.keys[j + 1];
                }
                node.keys[j] = 0;
                node.currentKey = node.currentKey - 1;
            }else{
                NodeBTree parent = findParent(node, q);
                int i;
                int n = parent.currentKey;
                for(i = 0; i <= n; i++){
                    if(parent.childPointers[i] == node){
                        break;
                    }
                }
            
                if(i != 0){
                    NodeBTree realChild;
                    realChild = parent.childPointers[i - 1];
                    int x = realChild.currentKey;
                    realChild.keys[x] = parent.keys[i - 1];
                    numberOfMergeOperations = numberOfMergeOperations + 1;
                    realChild.currentKey = realChild.currentKey + 1;

                    int j;
                    for(j = i - 1; j < (n - 1); j++){
                        parent.keys[j] = parent.keys[j + 1];
                        parent.childPointers[j + 1] = parent.childPointers[j + 2];
                    }
                    parent.currentKey = parent.currentKey - 1;
                    parent.keys[j] = 0;
                    parent.childPointers[j + 1] = null;

                    if(realChild.currentKey == 2*minimumValueTree){
                        splitTree(realChild, q);
                    }
                }else{
                    NodeBTree realChild;
                    realChild = parent.childPointers[1];
                    int x = realChild.currentKey;

                    int h;
                    for(h = x - 1; h >= 0; h--){
                        realChild.keys[h + 1] = realChild.keys[h];
                    }
                    realChild.keys[0] = parent.keys[0];
                    numberOfMergeOperations = numberOfMergeOperations + 1;

                    realChild.currentKey = realChild.currentKey + 1;

                    int j;
                    for(j = 0; j < (n - 1); j++){
                        parent.keys[j] = parent.keys[j + 1];
                        parent.childPointers[j] = parent.childPointers[j + 1];
                    }
                    parent.childPointers[j] = parent.childPointers[j + 1];

                    parent.currentKey = parent.currentKey - 1;
                    parent.keys[j] = 0;
                    parent.childPointers[j + 1] = null;

                    if(realChild.currentKey == 2*minimumValueTree){
                        splitTree(realChild, q);
                    }
                }
            }
        }else{
            int n = node.currentKey;
            int i;
            for(i = 0; i < n; i++){
                if(node.keys[i] == k){
                    break;
                }
            }

            while(node.isLeaf != true){
                NodeBTree child = node.childPointers[i];
                node.keys[i] = child.keys[child.currentKey - 1];
                i = child.currentKey - 1;
                node = child;
                numberOfMergeOperations = numberOfMergeOperations + 1;
            }

            node.currentKey = node.currentKey - 1;

            if(node.currentKey == 0){
                NodeBTree parent = findParent(node, q);
                n = parent.currentKey;

                for(i = 0; i <= n; i++){
                    if(parent.childPointers[i] == node){
                        break;
                    }
                }

                if(i != 0){
                    NodeBTree realChild;
                    realChild = parent.childPointers[i - 1];
                    int x = realChild.currentKey;
                    realChild.keys[x] = parent.keys[i - 1];
                    numberOfMergeOperations = numberOfMergeOperations + 1;

                    realChild.currentKey = realChild.currentKey + 1;

                    int j;
                    for(j = i - 1; j < (n - 1); j++){
                        parent.keys[j] = parent.keys[j + 1];
                        parent.childPointers[j + 1] = parent.childPointers[j + 2];
                    }
                    parent.currentKey = parent.currentKey - 1;
                    parent.keys[j] = 0;
                    parent.childPointers[j + 1] = null;

                    if(realChild.currentKey == 2*minimumValueTree){
                        splitTree(realChild, q);
                    }
                }else{
                    NodeBTree realChild;
                    realChild = parent.childPointers[1];
                    int x = realChild.currentKey;

                    int h;
                    for(h = x - 1; h >= 0; h--){
                        realChild.keys[h + 1] = realChild.keys[h];
                    }
                    realChild.keys[0] = node.keys[0];
                    numberOfMergeOperations = numberOfMergeOperations + 1;

                    realChild.currentKey = realChild.currentKey + 1;

                    int j;
                    for(j = 0; j < (n - 1); j++){
                        parent.keys[j] = parent.keys[j + 1];
                        parent.childPointers[j] = parent.childPointers[j + 1];
                    }
                    parent.childPointers[j] = parent.childPointers[j + 1];
                    parent.currentKey = parent.currentKey - 1;
                    parent.keys[j] = 0;
                    parent.childPointers[j + 1] = null;

                    if(realChild.currentKey == 2*minimumValueTree){
                        splitTree(realChild, q);
                    }
                }
            }
        }
    }

    public void printOperations(){
        System.out.println("Total Number of Split Operations: " + numberOfSplitOperations);
        System.out.println("Total Number of Merge Operations: " + numberOfMergeOperations);
    }
}

class P2{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int query = sc.nextInt();
        int q = query;
        int k;

        int r = sc.nextInt();
        BTree tree = new BTree(r);

        sc.nextLine();

        for(k = 0; k < query; k++){
            String s = new String();
            s = sc.nextLine();

            int m = s.length();
            int a = 0;
            int mul = 1;
            for(int v = m - 1; v >= 2; v--){
                int addition = (int)(s.charAt(v));
                addition = addition - 48;
                addition = addition*mul;
                a = a + addition;
                mul = mul * 10;
            }

            if(s.charAt(0) == 'i'){
                if(k == 0){
                    tree.insert(a, q);
                }else if(tree.check(a, q) == true){
                    tree.insert(a, q);
                }else{
                    System.out.println("Value given at query " + (k + 1) + " is already present");
                }
            }else if(s.charAt(0) == 'd'){
                tree.delete(a, q);
            }else{
                System.out.println("Wrong instruction format for query " + (k + 1));
            }
        }

        tree.printOperations();
        tree.traverseInitiator();
        
    }
}