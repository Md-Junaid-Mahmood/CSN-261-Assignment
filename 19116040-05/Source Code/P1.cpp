#include <iostream>
using namespace std;

class linkedList{
    private:
        struct node{
            int vertex;
            node* next;
        };

        int numberOfEdges;
        int numberOfNodes;
        node* adjacencyList;

    public:
        linkedList(int n);
        void insert(int a, int b);
        void calculateNumberOfNodes();
        void bfs();
        void dfs();
        bool checkCycle(int *arr, int a, int b);
        bool checkInitiator();
        int findDiameter(int i);
        int findDiameterInitiator();
};

linkedList::linkedList(int n){
    adjacencyList = (node*)malloc((n + 1)*sizeof(node));
    numberOfEdges = n;
    for(int i = 1; i <= (n+1); i++){
        (adjacencyList + i - 1)->vertex = i;
        (adjacencyList + i - 1)->next = NULL;
    }
}

void linkedList::calculateNumberOfNodes(){
    int i;
    int count = 0;
    for(i = 1; i <= (numberOfEdges+1); i++){
        if((adjacencyList + i - 1)->next != NULL){
            count = count + 1;
        }
    }
    
    numberOfNodes = count;
}

void linkedList::insert(int a, int b){
    if((adjacencyList + a - 1)->next == NULL){
        (adjacencyList + a - 1)->vertex = a;
        (adjacencyList + a - 1)->next = NULL;

        node *s;
        s = new node;
        s->vertex = b;
        s->next = NULL;
        (adjacencyList + a - 1)->next = s;
    }else{
        node *s;
        s = new node;
        s->vertex = b;

        node *p, *q;
        p = (adjacencyList + a - 1)->next;
        q = (adjacencyList + a - 1)->next;
        if(q->vertex > b){
            (adjacencyList + a - 1)->next = s;
            s->next = q;
        }else{
            while(q != NULL && q->vertex < b){
                p = q;
                q = q->next;
            }
            p->next = s;
            s->next = q;
        }
    }

    int temp = a;
    a = b;
    b = temp;

    if((adjacencyList + a - 1)->next == NULL){
        (adjacencyList + a - 1)->vertex = a;
        (adjacencyList + a - 1)->next = NULL;

        node *s;
        s = new node;
        s->vertex = b;
        s->next = NULL;
        (adjacencyList + a - 1)->next = s;
    }else{
        node *s;
        s = new node;
        s->vertex = b;

        node *p, *q;
        p = (adjacencyList + a - 1)->next;
        q = (adjacencyList + a - 1)->next;
        if(q->vertex > b){
            (adjacencyList + a - 1)->next = s;
            s->next = q;
        }else{
            while(q != NULL && q->vertex < b){
                p = q;
                q = q->next;
            }
            p->next = s;
            s->next = q;
        }
    }
}

void linkedList::bfs(){
    int i = 1;

    int* queue;
    char* container;
    int* output;
    int k = 0;

    queue = (int*)calloc(numberOfNodes, sizeof(int));
    container = (char*)calloc(numberOfNodes, sizeof(char));

    int front = 0;
    int rear = 0;

    queue[front] = i;
    front = front + 1;
    container[i - 1] = 'A';

    while(rear < front){
        node *q;
        q = (adjacencyList + queue[rear] - 1)->next;
        while(q != NULL){
            if(container[q->vertex - 1] != 'A'){
                queue[front] = q->vertex;
                front = front + 1;
                container[q->vertex - 1] = 'A';
            }
            q = q->next;
        }
        rear = rear + 1;
    }
    cout << "BFS Traversal is: ";
    for(i = 0; i < front; i++){
        cout << queue[i] << " ";
    }
    cout << "\n";
    free(queue);
    free(container);
}

void linkedList::dfs(){
    int i = 1;
    
    int* stack;
    char* container;
    int* output;
    int k = 0;

    stack = (int*)calloc(numberOfNodes, sizeof(int));
    container = (char*)calloc(numberOfNodes, sizeof(char));
    output = (int*)calloc(numberOfNodes, sizeof(int));

    int top =  0;

    stack[top] = i;
    top = top + 1;
    container[i - 1] = 'A';
    output[k] = i;
    k = k + 1;

    while(top > 0){
        node *q;
        int w;
        q = (adjacencyList + stack[top - 1] - 1)->next;
        while(q != NULL){
            w = 0;
            if(container[q->vertex - 1] != 'A'){
                stack[top] = q->vertex;
                top = top + 1;
                container[q->vertex - 1] = 'A';
                output[k] = q->vertex;
                k = k + 1;
                w = 1;
            }
            if(w == 1){
                break;
            }
            q = q->next;
        }
        if(w == 1){
            continue;
        }else{
            top = top - 1;
        }
    }
    cout << "DFS Traversal is: ";
    for(i = 0; i < k; i++){
        cout << output[i] << " ";
    }
    cout << "\n";

    free(stack);
    free(container);
    free(output);
}

bool linkedList::checkCycle(int *arr, int a, int b){
    node *q;
    q = (adjacencyList + b - 1)->next;
    while(q != NULL){
        if(q->vertex == a){
            q = q->next;
        }else{
            if(arr[q->vertex - 1] == 1){
                return(true);
            }else{
                arr[q->vertex - 1] == 1;
            }
            q = q->next;
        }
    }
    return(false);
}

bool linkedList::checkInitiator(){
    int i = 1;

    int* stack;
    int* container;

    stack = (int*)calloc(numberOfNodes, sizeof(int));
    container = (int*)calloc(numberOfNodes, sizeof(int));

    int top =  0;

    stack[top] = i;
    top = top + 1;
    container[i - 1] = 1;
    
    while(top > 0){
        node *q;
        int w;
        q = (adjacencyList + stack[top - 1] - 1)->next;
        int a = (adjacencyList + stack[top - 1] - 1)->vertex;
        while(q != NULL){
            w = 0;
            if(container[q->vertex - 1] != 1){
                stack[top] = q->vertex;
                top = top + 1;
                container[q->vertex - 1] = 1;
                
                if(checkCycle(container, a, q->vertex)){
                    return(true);
                }

                w = 1;
            }
            if(w == 1){
                break;
            }
            q = q->next;
        }
        if(w == 1){
            continue;
        }else{
            top = top - 1;
        }
    }
    free(stack);
    free(container);
    return(false);
}

int linkedList::findDiameter(int i){
    int sum = 0;
    int* queue;
    char* container;
    int* path;

    queue = (int*)calloc(numberOfNodes, sizeof(int));
    container = (char*)calloc(numberOfNodes, sizeof(char));
    path = (int*)calloc(numberOfNodes, sizeof(int));

    int front = 0;
    int rear = 0;

    queue[front] = i;
    front = front + 1;
    container[i - 1] = 'A';
  
    while(rear < front){
        node *q;
        q = (adjacencyList + queue[rear] - 1)->next;
        while(q != NULL){
            if(container[q->vertex - 1] != 'A'){
                queue[front] = q->vertex;
                front = front + 1;
                container[q->vertex - 1] = 'A';
                path[q->vertex - 1] = path[queue[rear] - 1] + 1;
            }
            q = q->next;
        }
        rear = rear + 1;
    }

    for(i = 0; i < numberOfNodes; i++){
        if(path[i] > sum){
            sum = path[i];
        }
    }

    free(queue);
    free(container);
    free(path); 

    return(sum);
}

int linkedList::findDiameterInitiator(){
    int i, j;
    int diameter = 0;
    for(i = 1; i <= numberOfNodes; i++){
        int count = findDiameter(i);
        if(diameter < count){
            diameter = count;
        }
    }
    return(diameter);
}

int main() {
    int n;
    cin >> n;
    linkedList l1(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a;
        cin >> b;
        l1.insert(a, b);
    }

    l1.calculateNumberOfNodes();

    l1.bfs();
    l1.dfs();
    
    cout << "Does graph contain a cycle: ";
    if(l1.checkInitiator()){
        cout << "YES \n";
    }else{
        cout << "NO \n";
    }

    int dia = l1.findDiameterInitiator();
    cout << "Diameter of the given graph is: " << dia << "\n";

}
