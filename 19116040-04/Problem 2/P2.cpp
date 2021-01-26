#include <iostream>
using namespace std;

// Below is the implementation of the class linkedList
class linkedList{
    private :
        struct node{
            int power;
            int coefficient;
            node* next;
        }*head;

        int numberOfNodes = 0;
        int highestPower = 0;

    public :
        linkedList(int n);
        void insert(int p, int c);
        linkedList add(linkedList l1, linkedList l2, linkedList l3);
        void printAll(linkedList l1, node* q);
        void printInitiator(linkedList l1);
};

// Below is the implementation of the constructor of the class linkedList
linkedList::linkedList(int n){
    numberOfNodes = n;
    head = NULL;
}

// Below is the implementation of the insert() function of the class linkedList
// Insertion is done at the head of the linked list
void linkedList::insert(int p, int c){
    node *s;
    if(head == NULL){
        head = new node;
        head->power = p;
        head->coefficient = c;
        head->next = NULL;
        highestPower = p;
    }else{
        s = new node;
        s->power = p;
        s->coefficient = c;
        s->next = head;
        head = s;
    }
}

// Below is the implementation of the add() function of the class linkedList
linkedList linkedList::add(linkedList l1, linkedList l2, linkedList l3){
    int k = l1.highestPower;
    if(k < l2.highestPower){
        k = l2.highestPower;
    }
    if(k < l3.highestPower){
        k = l3.highestPower;
    }

    node *current;
    current = l1.head;

    node *previous;
    previous = l1.head;

    node *p, *q;
    p = l2.head;
    q = l3.head;

    int i = 0;
    while(i <= k){
        int a = 0;
        int b = 0;
        int c = 0;

        if(p != NULL){
            if(p->power == i){
                a = p->coefficient;
                p = p->next;
            }
        }
        if(q != NULL){
            if(q->power == i){
                b = q->coefficient;
                q = q->next;
            }
        }
        if(current != NULL){
            if(current->power == i){
                c = current->coefficient;
            }
        }
        int d = (a + b + c);
        int w = 0;

        if(current != NULL){
            if(current->power == i){
                if(d != 0){
                    current->coefficient = d;
                    w = 1;
                }else{
                    previous->next = current->next;
                    current = current->next;
                }
            }else if(d != 0){
                node *s;
                s = new node;
                s->power = i;
                s->coefficient = d;
                if(previous == current){
                    s->next = l1.head;
                    l1.head = s;
                    previous = s;
                    current = s;
                }else{
                    previous->next = s;
                    s->next = current;
                    current = s;
                }
                w = 1;
            }
        }else{
            if(d != 0){
                node *s;
                s = new node;
                s->power = i;
                s->coefficient = d;
                previous->next = s;
                s->next = current;
                current = s;
                w = 1;
            }
        }

        if(w == 1){
            previous = current;
            current = current->next;
        }
        
        i = i + 1;
    }
    return l1;
}

// Below is the implementation of the printAll() function of the class linkedList
void linkedList::printAll(linkedList l1, node* q){
    node *s;
    s = q->next;

    int p = q->power;
    int c = q->coefficient;

    if(s == NULL){
        cout << c << "x^" << p;
    }else{
        printAll(l1, s);
        cout << " + " << c << "x^" << p;
    }
}

// Below is the implementation of the printInitiator() function of the class linkedList
void linkedList::printInitiator(linkedList l1){
    node *q;
    q = l1.head;
    printAll(l1, q);
    cout << "\n";
}

// Below is the implementation of the main() function of the program
int main() {
    int n1, n2, n3, i;

    cin >> n1;
    linkedList l1(n1);
    /*
        User is asked to enter number of terms for first polynomial expression
        For each term user has to enter power first and then coefficient
    */
    for(i = 0; i < n1; i++){
        int p, c;
        cin >> p;
        cin >> c;
        l1.insert(p, c);
    }

    cin >> n2;
    linkedList l2(n2);
    /*
        User is asked to enter number of terms for second polynomial expression
        For each term user has to enter power first and then coefficient
    */
    for(i = 0; i < n2; i++){
        int p, c;
        cin >> p;
        cin >> c;
        l2.insert(p, c);
    }

    cin >> n3;
    linkedList l3(n3);
    /*
        User is asked to enter number of terms for first polynomial expression
        For each term user has to enter power first and then coefficient
    */
    for(i = 0; i < n3; i++){
        int p, c;
        cin >> p;
        cin >> c;
        l3.insert(p, c);
    }

 
    l1 = l1.add(l1, l2, l3);
    l1.printInitiator(l1);
}
