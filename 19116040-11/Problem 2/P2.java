import java.util.Scanner;

class linkedList{
    class node{
        int vertex1;
        int vertex2;
        int weight;
        node next;
        boolean isPresent = false;
    }

    node head;
    int setContainer[];

    public linkedList(int k){
        head = null;
        setContainer = new int[k];
    }

    public void insert(int v1, int v2, int w){
        node n = new node();
        n.vertex1 = v1;
        n.vertex2 = v2;
        n.weight = w;

        if(head == null){
            n.next = null;
            head = n;
        }else{
            node p, q;
            p = head;
            q = head;
            while(q != null){
                if(q.weight > n.weight){
                    break;
                }else{
                    p = q;
                    q = q.next;
                }
            }
            if(p == q){
                n.next = q;
                head = n;
            }else{
                p.next = n;
                n.next = q;
            }
        }
    }

    public boolean find(node n){
        int v1 = n.vertex1;
        int v2 = n.vertex2;

        int r1 = rootElement(v1);
        int r2 = rootElement(v2);

        if(r1 == r2){
            return(false);
        }else{
            return(true);
        }
    }

    public int rootElement(int v){
        if(setContainer[v - 1] <= 0){
            return(v);
        }else{
            int a = setContainer[v - 1];
            int b = rootElement(a);
            return(b);
        }
    }

    public void union(node n){
        int v1 = n.vertex1;
        int v2 = n.vertex2;

        int root1 = rootElement(v1);
        int root2 = rootElement(v2);

        int r1 = setContainer[root1 - 1];
        int r2 = setContainer[root2 - 1];

        if(r1 == 0 && r2 == 0){
            setContainer[v1 - 1] = -2;
            setContainer[v2 - 1] = v1;
        }else if(r1 == 0){
            setContainer[v1 - 1] = root2;
            setContainer[root2 - 1] = setContainer[root2 - 1] - 1;
        }else if(r2 == 0){
            setContainer[v2 - 1] = root1;
            setContainer[root1 - 1] = setContainer[root1 - 1] - 1;
        }else{
            if(r1 < r2){
                setContainer[root1 - 1] = setContainer[root1 - 1] + setContainer[root2 - 1];
                setContainer[root2 - 1] = root1;
            }else{
                setContainer[root2 - 1] = setContainer[root2 - 1] + setContainer[root1 - 1];
                setContainer[root1 - 1] = root2;
            }
        }
    }

    public void kruskalAlgorithm(){
        node n = head;
        while(n != null){
            if(find(n)){
                union(n);
                n.isPresent = true;
            }
            n = n.next;
        }

        printOutput();
    }

    public void printOutput(){
        node n = head;
        while(n != null){
            if(n.isPresent){
                int v1 = n.vertex1;
                int v2 = n.vertex2;
                int w = n.weight;
                if(v1 < v2){
                    System.out.println(v1 + " " + v2 + " " + w);
                }else{
                    System.out.println(v2 + " " + v1 + " " + w);
                }
            }
            n = n.next;
        }
    }
}

class P2{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int i;
        for(i = 0; i < t; i++){
            int vertices = sc.nextInt();
            int edges = sc.nextInt();
            int j;

            linkedList list = new linkedList(vertices);
            for(j = 0; j < edges; j++){
                int v1 = sc.nextInt();
                int v2 = sc.nextInt();
                int w = sc.nextInt();

                list.insert(v1, v2, w);
            }

            list.kruskalAlgorithm();
        }
    }
}