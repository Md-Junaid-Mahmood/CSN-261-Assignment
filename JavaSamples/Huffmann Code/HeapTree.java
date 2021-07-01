import java.util.Stack;

class Node{
    int value;
    Node left = null;
    Node right = null;

    public Node(int num){
        this.value = num;
    }
}

public class HeapTree {
    private Node root = null;
    private int count = 0;

    public HeapTree(int num){
        Node node = new Node(num);
        root = node;
        count++;
    }

    public void heapify(Node node){
        Node leftNode = node.left;
        Node rightNode = node.right;

        if(leftNode == null && rightNode == null){
            return;
        }else if(rightNode == null){
            if(leftNode.value < node.value){
                int temp = leftNode.value;
                leftNode.value = node.value;
                node.value = temp;
                heapify(leftNode);
            }
            return;
        }else if(leftNode == null){
            if(rightNode.value < node.value){
                int temp = rightNode.value;
                rightNode.value = node.value;
                node.value = temp;
                heapify(rightNode);
            }
            return;
        }else{
            Node nd = leftNode;
            if(nd.value > rightNode.value){
                nd = rightNode;
            }
            if(nd.value < node.value){
                int temp = nd.value;
                nd.value = node.value;
                node.value = temp;
                heapify(nd);
            }
            return;
        }
    }

    public void add(int entry){
        count += 1;
        int num = count;
        Stack<Integer> stack = new Stack<Integer>();
        while(num != 1){
            stack.push(num%2);
            num = (int)(num/2);
        }
        Stack<Node> path = new Stack<Node>();
        Node prev = root;
        Node next = root;
        while(!stack.isEmpty()){
            prev = next;
            path.push(prev);
            int val = stack.pop();
            if(val == 0){
                next = next.left;
            }else{
                next = next.right;
            }
        }
        Node node = new Node(entry);
        if(count % 2 == 0){
            prev.left = node;
        }else{
            prev.right = node;
        }
        while(!path.isEmpty()){
            heapify(path.pop());
        }
    }

    public int poll(){
        int num = root.value;
        int val = count;
        Stack<Integer> stack = new Stack<Integer>();
        Node next = root;
        Node prev = root;

        while(val != 1){
            stack.push(val%2);
            val = (int)(val/2);
        }
        while(!stack.isEmpty()){
            prev = next;
            if(stack.pop() == 0){
                next = next.left;
            }else{
                next = next.right;
            }
        }
        if(prev == next){
            root = null;
            return(num);
        }
        root.value = next.value;
        if(count%2 == 0){
            prev.left = null;
        }else{
            prev.right = null;
        }
        count--;
        heapify(root);
        return(num);
    }
}
