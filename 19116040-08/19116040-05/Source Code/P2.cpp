#include <iostream>
using namespace std;

class linkedList{
    private:
        struct node{
            int vertex1 = -1;
            int vertex2 = -1;
            int weight = -1;
            node *next;
            bool present = false;
        }*head;

        int numberOfEdges;
        int numberOfNodes;

    public:
        linkedList();
        void addNumberOfEdges(int n);
        void calculateNumberOfNodes();
        void insert(int v1, int v2, int w);
        int findRoot(int a, int *container);
        bool find(node *q, int *container);
        void doUnion(node *q, int *container);
        void kruskalAlgorithm();
        int totalEdgeWidth();
        void printSpanningTree();
        void printDotFile();
};

linkedList::linkedList(){
    head = NULL;
}

void linkedList::addNumberOfEdges(int n){
    numberOfEdges = n;
}

void linkedList::calculateNumberOfNodes(){
    int* arr;
    arr = (int*)calloc(numberOfEdges + 1, sizeof(int));
    int count = 0;
    node *q;
    q = head;
    while(q != NULL){
        int v1 = q->vertex1;
        int v2 = q->vertex2;
        if(arr[v1 - 1] == 0){
            arr[v1 - 1] = 1;
            count = count + 1;
        }
        if(arr[v2 - 1] == 0){
            arr[v2 - 1] = 1;
            count = count + 1;
        }
        q = q->next;
    }

    numberOfNodes = count;
    free(arr);
}

void linkedList::insert(int v1, int v2, int w){
    node *s;
    if(head == NULL){
        head = new node;
        head->vertex1 = v1;
        head->vertex2 = v2;
        head->weight = w;
        head->next = NULL;
    }else{
        s = new node;
        s->vertex1 = v1;
        s->vertex2 = v2;
        s->weight = w;
        node *p, *q;
        p = head;
        q = head;
        while(q != NULL){
            if(q->weight > w){
                break;
            }
            p = q;
            q = q->next;
        }
        if(p == q){
            s->next = head;
            head = s;
        }else{
            p->next = s;
            s->next = q;
        }
    }
}

int linkedList::findRoot(int a, int *container){
    int s = container[a - 1];
    if(s >= 0){
        a = findRoot(s, container);
    }
    return(a);
}

bool linkedList::find(node *q, int *container){
    int v1 = q->vertex1;
    int v2 = q->vertex2;

    int r1 = container[v1 - 1];
    int r2 = container[v2 - 1];

    if(r1 != 0 && r2 != 0){
        int x = findRoot(v1, container);
        int y = findRoot(v2, container);
        if(x == y){
            return(false);
        }
    }
    return(true);
}

void linkedList::doUnion(node *q, int *container){
    int v1 = q->vertex1;
    int v2 = q->vertex2;
    q->present = true;

    int r1 = container[v1 - 1];
    int r2 = container[v2 - 1];

    if(r1 == 0 && r2 == 0){
        container[v1 - 1] = -2;
        container[v2 - 1] = v1;
    }else if(r1 == 0){
        int x = findRoot(v2, container);
        container[v1 - 1] = x;
        container[x - 1] = container[x - 1] - 1;
    }else if(r2 == 0){
        int x = findRoot(v1, container);
        container[v2 - 1] = x;
        container[x - 1] = container[x - 1] - 1;
    }else{
        int x = findRoot(v1, container);
        int y = findRoot(v2, container);
        if(container[x-1] < container[y-1]){
            int z = container[y-1];
            container[y-1] = x;
            container[x-1] = container[x-1] + z;
        }else{
            int z = container[x-1];
            container[x-1] = y;
            container[y-1] = container[y-1] + z;
        }
    }
}

void linkedList::kruskalAlgorithm(){
    int* container;
    container = (int*)calloc(numberOfNodes + 1, sizeof(int));

    node *q;
    q = head;
    while(q != NULL){
        bool x = find(q, container);
        if(x == true){
            doUnion(q, container);
        }
        q = q->next;
    }

    free(container);
}

int linkedList::totalEdgeWidth(){
    node *q;
    q  = head;
    int w = 0;
    while(q != NULL){
        if(q->present == true){
            w = w + q->weight;
        }
        q = q->next;
    }
    return(w);
}

void linkedList::printSpanningTree(){
    cout << "// Node1  Node2  Weight\n";
    node *q;
    q = head;
    while(q != NULL){
        if(q->present == true){
            int v1 = q->vertex1;
            int v2 = q->vertex2;
            int w = q->weight;
            cout << "// " << v1 << "      " << v2 << "      " << w << "\n";
        }
        q = q->next;
    }
}

void linkedList::printDotFile(){
    cout << "graph{\n";
    node *q;
    q = head;
    while(q != NULL){
        if(q->present == true){
            int v1 = q->vertex1;
            int v2 = q->vertex2;
            int w = q->weight;
            cout << "\t" << v1 << " -- " << v2 << " [label = \"" << w << "\"];\n";
        }
        q = q->next;
    }
    cout << "}";
}

int main() {
    linkedList l1;

    int n = 0;
    int v1, v2, w;
    while(cin >> v1 >> v2 >> w){
        l1.insert(v1, v2, w);
        n = n + 1;
    }

    l1.addNumberOfEdges(n);
    l1.calculateNumberOfNodes();

    l1.kruskalAlgorithm();
    
    l1.printSpanningTree();
    w = l1.totalEdgeWidth();
    cout << "//Total edge-weight of the MST is: " << w << "\n";

    cout << "//Dot file output is: \n";
    l1.printDotFile();
}
