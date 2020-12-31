#include <iostream>
#include <time.h>
using namespace std;

/*
#include <time.h> is included to make use of rand() and srand() function in an efficient manner
*/

// Below is the implementation of the class linkedList
class linkedList{
    private :
        struct node{
            int number;
            node* next;
        }*head;

    int numberOfSoldiers;
    int numberOfLift;
    int capacityOfLift;

    node* arr;

    public :
        linkedList(int n, int m, int c);
        void createList();
        void startLift();
        void allocateMemoryToArray();
        void freeMemory();
        void insert(int i);
        void printAll();

};

// Below is the implementation of the constructor of the class linkedList
linkedList::linkedList(int n, int m, int c){
    head = NULL;
    numberOfSoldiers = n;
    numberOfLift = m;
    capacityOfLift = c;
}

// Below is the implementation of the allocateMemoryToArray() function of the class linkedList
void linkedList::allocateMemoryToArray(){
    arr = (node*)malloc(numberOfLift*sizeof(node));
    /*
        Memory is dynamically allocated to the array
        The purpose of the array is to store the pointers
        The pointers will serve as top of the stack for each respective lift
    */
}

// Below is the implementation of the freeMemory() function of the class linkedList
void linkedList::freeMemory(){
    free(arr);
    delete head;
    /*
        The head of the linked list is deleted
        Using free() function memory allocated to the array is reclaimed
    */
}

// Below is the implementation of the insert() function of the class linkedList
void linkedList::insert(int i){
    node *s;
    if(head == NULL){
        head = new node;
        head->number = i;
        head->next = NULL;
    }else{
        int w = 0;
        node *p, *q;
        p = head;
        q = head;
        while(q != NULL){
            if(q->number > i){
                w = 1;
                break;
            }

            p = q;
            q = q->next;
        }
        if(w == 0){
            s = new node;
            s->number = i;
            s->next = NULL;
            p->next = s;
        }else{
            if(p == q){
                s = new node;
                s->number = i;
                s->next = head;
                head = s;
            }else{
                s = new node;
                s->number = i;
                s->next = q;
                p->next = s;
            }
        }
    }
}

// Below is the implementation of the printAll() function of the class linkedList
void linkedList::printAll(){
    node *q;
    q = head;
    cout << "Final sorted list is: ";
    while(q->next != NULL){
        cout << "S" << q->number << ", ";
        q = q->next;
    }
    cout << "S" << q->number << "\n";
}

// Below is the implementation of the createList() function of the class linkedList
void linkedList::createList(){
    int i = 1;
    int k = 0;
    int num = 0;
    while(i <= numberOfSoldiers){
        k = k + 1;
        if(head == NULL){
            head = new node;
            head->number = i;
            head->next = NULL;

            if(k == capacityOfLift){
                (arr + num)->number = i;
                (arr + num)->next = NULL;
                num = num + 1;
                k = 0;
            }
        }else{
            node *s;
            s = new node;
            s->number = i;
            s->next = head;

            if(k == capacityOfLift){
                (arr + num)->number = i;
                (arr + num)->next = head;
                num = num + 1;
                k = 0;
            }

            head = s;
        }
        
        i = i + 1;
    }
}

// Below is the implementation of the startLift() function of the class linkedList
/*
    This function will start the job of chossing random numbers to pop out the soldiers from the respective lift
*/
void linkedList::startLift(){
    int size[numberOfLift];
    int t = 0;
    for(t = 0; t < numberOfLift; t++){
        size[t] = 0;
    }

    linkedList l1(numberOfSoldiers, numberOfLift, capacityOfLift);

    t = 0;
    srand(time(0));
    for(t = 0; t < numberOfSoldiers; t++){
        int r = rand();
        r = r%numberOfLift;

        while(size[r] == capacityOfLift){
            r = r + 1;
            r = r%numberOfLift;
        }

        size[r] = size[r] + 1;

        int a = (arr + r)->number;
        int b = r + 1;
        cout << "Soldier ID S" << a << " popped out from the random lift " << b << "\n";
            
        l1.insert(a);
        l1.printAll();

        if(size[r] == capacityOfLift){
            continue;
        }else{
            (arr + r)->number = ((arr + r)->next)->number;
            (arr + r)->next = ((arr + r)->next)->next;
        }
    }
    delete l1.head;
}

// Below is the implementation of the main function of the program
int main(){
    int n, m, c;
    /*
        User is asked to enter the value of n, m, c
        n is number of Soldiers
        m is number of Lifts
        c is capacity of each lift
    */
    cin >> n;
    cin >> m;
    cin >> c;

    cout << "Soldiers in the respective Lifts at the Ground Floor are as: \n";
    int i = 1;
    int j = 1;
    int k = 1;
    for(i = 1; i <= m; i++){
        cout << "Soldiers in Lift " << i << ": ";
        for(k = 1; k < c; k++){
            cout << "S" << j << ", ";
            j = j + 1;
        }
        cout << "S" << j << "\n";
        j = j + 1;
        k = 0;
    }

    cout << "Soldiers exit form the random lifts at the top floor are as: \n";

    linkedList l1(n, m, c);
    l1.allocateMemoryToArray();

    l1.createList();
    l1.startLift();

    l1.freeMemory();
}
