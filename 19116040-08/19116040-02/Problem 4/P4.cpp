#include <iostream>
using namespace std;

// Below is the implementation of the circularQueue class
// Union data type has been used for storing the elements of the queue
// Elements are of heterogeneous type, like, integer, character and floating numbers

class circularQueue{
    private:
        struct node{
            union elements{
                int aa;
                char bb;
                float cc;
            };

            elements elem; // Union data type to store the elements of the circular queue
            char pos; // This variable of type char contains information about the type of the entered element
            
            node* next; // A pointer to the next node of the list
        }*head, *end;

        static const int size = 30; // A variable to decide the maximum number of nodes allowed in the circular queue
        int numberOfNodes;

    public :

        circularQueue();
        void Insert();
        void Delete();
        void printAll();
        bool Overflow();
        bool Underflow();
};

// Below is the implementation of the constructor of the circularQueue class

circularQueue::circularQueue(){
    numberOfNodes = 0;
    head = NULL;
    end = NULL;
}

// Below is the implementation of the Insert() function of the circularQueue class
// This function will add new elements in the circular queue

void circularQueue::Insert(){
    node *s;
    s = new node; // dynamically allocating the memory to a node using new keyword

    char n;
    cin >> n;// User has to enter the type of element, they want to insert
// I for integer, C for char and F for float

    if(n == 'I'){
        int a;
        cin >> a; // If user wants to enter integer
        s->elem.aa = a;
        s->pos = 'A';
    }else if(n == 'C'){
        char b;
        cin >> b; // If user wants to enter character
        s->elem.bb = b;
        s->pos = 'B';
    }else if(n == 'F'){
        float c;
        cin >> c; // If user wants to enter floating number
        s->elem.cc = c;
        s->pos = 'C';
    }

    bool y = Overflow();

// If queue is not full then insert the coressponding element
// Else print the error message that queue is full

    if(y == false){
        if(numberOfNodes == 0){
            head = s;
            head->next = head;
        }else if(numberOfNodes == 1){
            end = s;
            head->next = end;
            end->next = head;
        }else{
            s->next = head;
            end->next = s;
            end = s;
        }
        numberOfNodes = numberOfNodes + 1;
    }else{
        cout << "Circular Queue is full! Can not insert more elements\n";
    }
    
}

// Below is the implementation of the Delete() function of the circularQueue class

void circularQueue::Delete(){
    bool y = Underflow();

// If queue is not empty, then delete the corresponding element
// Else print the error message that queue is empty
   
    if(y == false){
        node *s;
        s = head;
        head = head->next;
        cout << "The deleted element is: ";
        if(s->pos == 'A'){
            cout << s->elem.aa << "\n";
        }else if(s->pos == 'B'){
            cout << s->elem.bb << "\n";
        }else if(s->pos == 'C'){
            cout << s->elem.cc << "\n";
        }

        delete s; // freeing the allocated memory using delete keyword
        numberOfNodes = numberOfNodes - 1;
    }else{
        cout << "Circular Queue is empty! Can not do delete operation\n";
    }
}

// Below is the implementation of the printAll() function of the circularQueue class

void circularQueue::printAll(){
    int x;
    node *w;
    w = head;
    cout << "The current status of the Queue is:\n" ;
    for(x = 0; x < numberOfNodes; x++){
        if(w->pos == 'A'){
            cout << w->elem.aa << "\n";
        }else if(w->pos == 'B'){
            cout << w->elem.bb << "\n";
        }else if(w->pos == 'C'){
            cout << w->elem.cc << "\n";
        }
        w = w->next;
    }
}

// Below is the implementation of the Overflow() function of the circularQueue class

bool circularQueue::Overflow(){
    if(numberOfNodes >= size){
        return(true);
    }else{
        return(false);
    }
}

// Below is the implementation of the Underflow() function of the circularQueue class

bool circularQueue::Underflow(){
    if(numberOfNodes == 0){
        return(true);
    }else{
        return(false);
    }
}

// Below is the implementation of the main method

int main() {
    circularQueue cq;
    char n;
    cin >> n;// User has to enter his choice on what to do
/*
    I for Insert
    D for Delete
    E for exit
    P for Print
*/
    while(n != 'E'){
        if(n == 'I'){
            cq.Insert();
        }else if(n == 'D'){
            cq.Delete();
        }else if(n == 'P'){
            cq.printAll();
        }
        cin >> n; // Taking the input again and again until user presses E for exit
    }
    cout << "Program is stopped";
}