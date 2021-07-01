import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

class Node{
    int value;
    char code = 'X';
    Node leftReserved = null;
    Node rightReserved = null;
    Node left = null;
    Node right = null;

    public Node(int num){
        this.value = num;
    }

    public Node(int num, char ch){
        this.value = num;
        this.code = ch;
    }

    public Node(Node node){
        this.value = node.value;
        this.code = node.code;
        this.left = node.left;
        this.right = node.right;
        this.leftReserved = node.leftReserved;
        this.rightReserved = node.rightReserved;
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

    public HeapTree(int num, char ch){
        Node node = new Node(num, ch);
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

                char tempCh = leftNode.code;
                leftNode.code = node.code;
                node.code = tempCh;
                
                Node vari = leftNode.leftReserved;
                leftNode.leftReserved = node.leftReserved;
                node.leftReserved = vari;

                vari = leftNode.rightReserved;
                leftNode.rightReserved = node.rightReserved;
                node.rightReserved = vari;
                heapify(leftNode);
            }
            return;
        }else if(leftNode == null){
            if(rightNode.value < node.value){
                int temp = rightNode.value;
                rightNode.value = node.value;
                node.value = temp;
                
                char tempCh = rightNode.code;
                rightNode.code = node.code;
                node.code = tempCh;

                Node vari = rightNode.leftReserved;
                rightNode.leftReserved = node.leftReserved;
                node.leftReserved = vari;

                vari = rightNode.rightReserved;
                rightNode.rightReserved = node.rightReserved;
                node.rightReserved = vari;
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
                
                char tempCh = nd.code;
                nd.code = node.code;
                node.code = tempCh;

                Node vari = nd.leftReserved;
                nd.leftReserved = node.leftReserved;
                node.leftReserved = vari;

                vari = nd.rightReserved;
                nd.rightReserved = node.rightReserved;
                node.rightReserved = vari;
                heapify(nd);
            }
            return;
        }
    }

    public void add(int entry){
        count += 1;

        Node node = new Node(entry);
        if(count == 1){
            root = node;
            return;
        }

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
        
        if(count % 2 == 0){
            prev.left = node;
        }else{
            prev.right = node;
        }
        while(!path.isEmpty()){
            heapify(path.pop());
        }
    }

    public void add(int entry, char ch){
        count += 1;

        Node node = new Node(entry, ch);
        if(count == 1){
            root = node;
            return;
        }

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
        
        if(count % 2 == 0){
            prev.left = node;
        }else{
            prev.right = node;
        }
        while(!path.isEmpty()){
            heapify(path.pop());
        }
    }

    public void add(Node node){
        count += 1;
        if(count == 1){
            root = node;
            return;
        }
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
            count = 0;
        }else{
            root.value = next.value;
            root.code = next.code;
            root.leftReserved = next.leftReserved;
            root.rightReserved = next.rightReserved;
            if(count%2 == 0){
                prev.left = null;
            }else{
                prev.right = null;
            }
            count--;
            heapify(root);
        }
        return(num);
    }

    public void printNode(){
        Queue<Node> queue = new ArrayDeque<Node>();
        queue.add(root);
        while(!queue.isEmpty()){
            Node current = queue.poll();
            if(current.left != null){
                queue.add(current.left);
            }
            if(current.right != null){
                queue.add(current.right);
            }
            System.out.print(current.value + " ");
        }
        System.out.println("");
    }

    public void pollAndInsert(){
        Node node1 = new Node(root);
        poll();

        Node node2 = new Node(root);
        poll();
        
        node1.left = null;
        node1.right = null;
        
        node2.left = null;
        node2.right = null;
        

        Node node = new Node(node1.value + node2.value);
        
        node.leftReserved = node1;
        node.rightReserved = node2;
        add(node);
    }

    public Node getTree(){
        return(root);
    }
}