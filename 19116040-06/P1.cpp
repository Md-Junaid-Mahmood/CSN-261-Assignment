#include <iostream>
using namespace std;

/*
    Below is the implementation of the class linkedList
*/
class linkedList{
    private :
        struct node{
            int nodeNumber;
            node* firstPointer;
            node* secondPointer;
        }*head;
    
        int numberOfNodes = 0;

    public :
        linkedList();
        void insertNode(int a, int b, int c);
        void insertLastNode(int a, int b);
        bool checkForNode(int a, node *q);
        linkedList duplicateList();
        void deleteNode(int a);
        void printHighestReferenceNodes();
        void printCycles(int *arr, int *brr, node *q, string *crr, int *d);
        void printCycleInitiator();
        bool checkPermutation(string str1, string str2);
        void printAll();
};

/*
    Below is the implementation of constructor of the class linkedList
*/
linkedList::linkedList(){
    head = NULL;
}

/*
    Below is the implementation of insertNode function of the class linkedList
*/
void linkedList::insertNode(int a, int b, int c){
    node *r, *s;
    numberOfNodes = numberOfNodes + 1;
    
    if(head == NULL){
        head = new node;
        head->nodeNumber = a;

        r = new node;
        r->nodeNumber = b;
        r->firstPointer = NULL;
        r->secondPointer = NULL;

        s = new node;
        s->nodeNumber = c;
        s->firstPointer = NULL;
        s->secondPointer = NULL;

        head->firstPointer = r;
        head->secondPointer = s;
    }else{
        node *q;

        bool xyz = checkForNode(a, head);
        if(xyz == true){
            node *p;
            p = head;
            while(true){
                node *m, *n;
                m = p->firstPointer;
                n = p->secondPointer;
                if(p->nodeNumber == a){
                    q = p;
                    break;
                }else if(m != NULL && m->nodeNumber == a){
                    q = m;
                    break;
                }else if(n != NULL && n->nodeNumber == a){
                    q = n;
                    break;
                }else{
                    p = m;
                }
            }
        }else{
            q = new node;
            q->nodeNumber = a;
        }

        xyz = checkForNode(b, head);
        if(xyz == true){
            node *p;
            p = head;
            while(true){
                node *m, *n;
                m = p->firstPointer;
                n = p->secondPointer;
                if(p->nodeNumber == b){
                    r = p;
                    break;
                }else if(m != NULL && m->nodeNumber == b){
                    r = m;
                    break;
                }else if(n != NULL && n->nodeNumber == b){
                    r = n;
                    break;
                }else{
                    p = m;
                }
            }
        }else{
            r = new node;
            r->nodeNumber = b;
            r->firstPointer = NULL;
            r->secondPointer = NULL;
        }

        xyz = checkForNode(c, head);
        if(xyz == true){
            node *p;
            p = head;
            while(true){
                node *m, *n;
                m = p->firstPointer;
                n = p->secondPointer;
                if(p->nodeNumber == c){
                    s = p;
                    break;
                }else if(m != NULL && m->nodeNumber == c){
                    s = m;
                    break;
                }else if(n != NULL && n->nodeNumber == c){
                    s = n;
                    break;
                }else{
                    p = m;
                }
            }
        }else{
            s = new node;
            s->nodeNumber = c;
            s->firstPointer = NULL;
            s->secondPointer = NULL;
        }

        q->firstPointer = r;
        q->secondPointer = s;
    }
}

/*
    Below is the implementation of insertLastNode function of the class linkedList
*/
void linkedList::insertLastNode(int a, int b){
    node *p, *q, *r;
    numberOfNodes = numberOfNodes + 1;

    p = head;
    while(p->nodeNumber != a){
        p = p->firstPointer;
    }
    r = p;
    p = head;
    while(true){
        node *m, *n;
        m = p->firstPointer;
        n = p->secondPointer;
        if(p->nodeNumber == b){
            q = p;
            break;
        }else if(m != NULL && m->nodeNumber == b){
            q = m;
            break;
        }else if(n != NULL && n->nodeNumber == b){
            q = n;
            break;
        }else{
            p = m;
        }
    }

    r->secondPointer = q;
}

/*
    Below is the implementation of checkForNode function of the class linkedList
*/

bool linkedList::checkForNode(int a, node *q){
    node *r, *s;
    r = q->firstPointer;
    s = q->secondPointer;
    if(q->nodeNumber == a){
        return(true);
    }else if(r != NULL && r->nodeNumber == a){
        return(true);
    }else if(s != NULL && s->nodeNumber == a){
        return(true);
    }else if(r != NULL){
        return(checkForNode(a, r));
    }else{
        return(false);
    }
}

/*
    Below is the implementation of printAll function of the class linkedList
*/
void linkedList::printAll(){
    node *p;
    p = head;

    cout << "  Node   Next Pointer   Second Pointer\n";
    cout << "  ------------------------------------\n";
    while(p != NULL){
        node *a, *b;
        a = p->firstPointer;
        b = p->secondPointer;

        int x, y, z;
        x = p->nodeNumber;

        if(a == NULL){
            y = -1;
        }else{
            y = a->nodeNumber;
        }

        if(b == NULL){
            z = -1;
        }else{
            z = b->nodeNumber;
        }
        if(y > 0){
            cout << "   " << x << "           " << y << "              " << z << "\n";
        }else{
            cout << "   " << x << "          " << y << "              " << z << "\n";
        }
        p = a;
    }
}

/*
    Below is the implementation of duplicateList function of the class linkedList
*/
linkedList linkedList::duplicateList(){
    linkedList l2;
    node *p;
    p = head;

    int num = 0;
    p = head;

    while(p != NULL){
        node *q;
        q = new node;
        q->nodeNumber = p->nodeNumber;
        q->firstPointer = p->firstPointer;
        p->firstPointer = q;
        p = q->firstPointer;
        num = num + 1;
    }

    p = head;
    while(p != NULL){
        (p->firstPointer)->secondPointer = (p->secondPointer)->firstPointer;
        p = (p->firstPointer)->firstPointer;
    }

    p = head;

    node *r;
    r = p->firstPointer;

    l2.head = r;
    p->firstPointer = r->firstPointer;
    p = r->firstPointer;

    while(p != NULL){
        r->firstPointer = p->firstPointer;
        r = p->firstPointer;

        p->firstPointer = r->firstPointer;
        p = r->firstPointer;
    }
    l2.numberOfNodes = num;
    return(l2);
}

/*
    Below is the implementation of deleteNode function of the class linkedList
*/
void linkedList::deleteNode(int a){
    node *p, *q;

    p = head;
    q = head;

    while(q->nodeNumber != a){
        p = q;
        q = q->firstPointer;
    }

    if(p == q){
        p = q->secondPointer;
        node *r;
        r = head;
        while(r != NULL){
            if(r->secondPointer == q){
                r->secondPointer = p;
            }
            r = r->firstPointer;
        }

        head = q->firstPointer;
        delete q;
    }else{
        p->firstPointer = q->firstPointer;
        p = q->secondPointer;

        node *r;
        r = head;

        while(r != NULL){
            if(r->secondPointer == q){
                r->secondPointer = p;
            }
            r = r->firstPointer;
        }

        delete q;
    }
    numberOfNodes = numberOfNodes - 1;
}

/*
    Below is the implementation of printHighestReferenceNodes function of the class linkedList
*/
void linkedList::printHighestReferenceNodes(){
    int* arr;
    arr = (int*)calloc(numberOfNodes, sizeof(int));
    arr[0] = -1;
    node *r;
    r = head;
    while(r != NULL){
        node *m, *n;
        m = r->firstPointer;
        n = r->secondPointer;

        if(m != NULL){
            int a = m->nodeNumber;
            arr[a - 1] = arr[a - 1] + 1;
        }
        if(n != NULL){
            int a = n->nodeNumber;
            arr[a - 1] = arr[a - 1] + 1;
        }
        r = r->firstPointer;
    }
    int k = -1;
    for(int i = 0; i < numberOfNodes; i++){
        if(arr[i] > k){
            k = arr[i];
        }
    }

    cout << "Maximum number of references to a node: " << k << "\n";
    cout << "  Highest reference nodes are: \n";
    for(int i = 0; i < numberOfNodes; i++){
        if(arr[i] == k){
            int j = i + 1;
            cout << "  Node " << j << "\n";
        }
    }
    free(arr);
}

/*
    Below is the implementation of checkPermutation function of the class linkedList
*/
bool linkedList::checkPermutation(string str1, string str2){
    int n1 = str1.length();
    int n2 = str2.length();
    if(n1 != n2){
        return(false);
    }

    int* arr1;
    arr1 = (int*)calloc(numberOfNodes, sizeof(int));

    int* arr2;
    arr2 = (int*)calloc(numberOfNodes, sizeof(int));

    for(int i = 0; i < n1; i++){
        int a = (int)(str1[i]);
        int b = (int)(str2[i]);
        a = a - 1;
        b = b - 1;
        arr1[a] = arr1[a] + 1;
        arr2[b] = arr2[b] + 1;
    }

    for(int i = 0; i < numberOfNodes; i++){
        if(arr1[i] != arr2[i]){
            free(arr1);
            free(arr2);
            return(false);
        }
    }

    free(arr1);
    free(arr2);
    return(true);
}

/*
    Below is the implementation of printCycles function of the class linkedList
*/
void linkedList::printCycles(int *container, int *path, node *q, string *storage, int *count){
    node *r, *s;
    r = q->firstPointer;
    s = q->secondPointer;

    if(r != NULL){
        int a = r->nodeNumber;
        if(container[a - 1] != 1){
            int* cont;
            cont = (int*)calloc(numberOfNodes, sizeof(int));
            for(int z = 0; z < numberOfNodes; z++){
                cont[z] = container[z];
            }
            cont[a - 1] = 1;

            int* pt;
            pt = (int*)calloc(numberOfNodes + 1, sizeof(int));
            for(int z = 0; z <= numberOfNodes; z++){
                pt[z] = path[z];
            }

            pt[pt[0]] = a;
            pt[0] = pt[0] + 1;
            printCycles(cont, pt, r, storage, count);
        }else{
            int k = path[0];
            int j = 0;
            for(j = 1; j < k; j++){
                if(path[j] == a){
                    break;
                }
            }
            string word = "";
            for(int i = j; i < k; i++){
                int t = path[i];
                char c = (char)t;
                word = word + c;
            }
            bool val = false;
            for(int i = 0; i < count[0]; i++){
                if(checkPermutation(word, storage[i])){
                    val = true;
                    break;
                }
            }
            if(val == false){
                storage[count[0]] = word;
                count[0] = count[0] + 1;
            }
        }
    }

    if(s != NULL){
        int a = s->nodeNumber;
        if(container[a - 1] != 1){
            int* cont;
            cont = (int*)calloc(numberOfNodes, sizeof(int));
            for(int z = 0; z < numberOfNodes; z++){
                cont[z] = container[z];
            }
            cont[a - 1] = 1;

            int* pt;
            pt = (int*)calloc(numberOfNodes + 1, sizeof(int));
            for(int z = 0; z <= numberOfNodes; z++){
                pt[z] = path[z];
            }

            pt[pt[0]] = a;
            pt[0] = pt[0] + 1;
            printCycles(cont, pt, s, storage, count);
        }else{
            int k = path[0];
            int j = 0;
            for(j = 1; j < k; j++){
                if(path[j] == a){
                    break;
                }
            }
            string word = "";
            for(int i = j; i < k; i++){
                int t = path[i];
                char c = (char)t;
                word = word + c;
            }

            bool val = false;
            for(int i = 0; i < count[0]; i++){
                if(checkPermutation(word, storage[i])){
                    val = true;
                    break;
                }
            }
            if(val == false){
                storage[count[0]] = word;
                count[0] = count[0] + 1;
            }
        }
    }

    free(container);
    free(path);
}

/*
    Below is the implementation of printCycleInitiator function of the class linkedList
*/
void linkedList::printCycleInitiator(){
    int* container;
    container = (int*)calloc(numberOfNodes, sizeof(int));
    int a = head->nodeNumber;
    container[a - 1] = 1;

    int *path;
    path = (int*)calloc(numberOfNodes + 1, sizeof(int));
    path[0] = 2;
    path[1] = a;

    int num = 1;
    for(int i = 1; i <= numberOfNodes; i++){
        num = num * 2;
    }
    string* storage;
    storage = (string*)calloc(num, sizeof(string));
    
    int* count;
    count = (int*)calloc(1, sizeof(int));
    count[0] = 0;

    printCycles(container, path, head, storage, count);
    cout << "Total Number of Unique Cycles are: " << count[0] << "\n";
    for(int y = 0; y < count[0]; y++){
        string str = storage[y];
        cout << "  Cycle " << (y + 1) << ": ";
        int n = str.length();
        for(int x = 0; x < n; x++){
            cout << (int)(str[x]) << " ";
        }
        cout << (int)(str[0]) << "\n";
    }

    free(storage);
    free(count);
}

/*
    Below is the implementation of main function
*/
int main() {
    linkedList l1;

    int n;
    cin >> n;
    /*
        User is asked to enter the number of nodes in the original linked-list.
    */

    int a, b, c;
    int i;

    for(i = 1; i <= n; i++){
        cin >> a >> b >> c;
        /*
            User is asked to enter the nodes of the original linked-list.
            User must first enter the node 
            User must then enter the next pointer of the above node if it exists and -1 if it is Null
            User must then enter the second pointer of the above node.
        */
        if(i < n){
            l1.insertNode(a, b, c);
        }else{
            l1.insertLastNode(a, c);
        }
    }

    cout << "A)Original linked List: \n";
    l1.printAll();
    cout << "\n";

    linkedList l2;
    l2 = l1.duplicateList();

    cout << "B)Duplicate linked List: \n";
    l2.printAll();
    cout << "\n";

    int numb;
    cin >> numb;
    /*
        User is asked to enter the node which is to be deleted from the duplicate list
    */
    l2.deleteNode(numb);
    cout << "C)Deletion of node " << numb << " is done on the duplicate list\n";
    cout << "  Duplicate linked List after deletion: \n";
    l2.printAll();
    cout << "\n";

    cout << "D)";
    l1.printHighestReferenceNodes();
    cout << "\n";

    cout << "E)";
    l1.printCycleInitiator();
    cout << "\n";
}
