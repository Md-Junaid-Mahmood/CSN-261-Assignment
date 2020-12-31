#include <iostream>
using namespace std;

// Below is the implementation of the class stack
// Union data type is used for storing the data as it may contain, int, char or float elements

class stack{
    private :
        struct element{
            union data{
                int aa;
                char bb;
                float cc;
            };
            data dt; // Union data type has been used for storing the heterogeneous elements
            char pos; // this variable of type char contains information about the type of the entered element
        };

        int top = 0;
        static const int maxSize = 30; // maxSize of the stack is set to 30 and can be changed later
        element* arr[maxSize]; // a fixed size array has been used for implementing the stack

    public:

        stack();
        void Push();
        void Pop();
        bool Full();
        bool Empty();
        void printAll();
};

// Below is the implementation of the constructor of the stack class

stack::stack(){
    top = 0;
}

// Below is the implementation of the push() function of the stack class

void stack::Push(){
    element *p;
    p = new element; // allocating the memory dynamically using new keyword

    char n;
    cin >> n; // User has to enter the type of element, they want to insert
// I for integer, C for char and F for float

    if(n == 'I'){
        int a;
        cin >> a; // If user wants to enter integer
        p->dt.aa = a;
        p->pos = 'A';
    }else if(n == 'C'){
        char b;
        cin >> b; // If user wants to enter a character
        p->dt.bb = b;
        p->pos = 'B';
    }else if(n == 'F'){
        float c;
        cin >> c; // If user wants to enter a floating number
        p->dt.cc = c;
        p->pos = 'C';
    }

    bool y = Full();

// If stack is not full then push the coressponding element
// Else print the error message that stack is full

    if(y == false){
        arr[top] = p;
        top = top + 1;
    }else{
        cout << "Stack is full! Can not push more elements" << "\n";
    }

}

// Below is the implementation of the pop() function of the stack class

void stack::Pop(){
    bool y = Empty();

// If stack is not empty, then pop out the corresponding element
// Else print the error message that stack is empty

    if(y == false){
        element *p;
        p = arr[top- 1];

        if(p->pos == 'A'){
            cout << "The popped element is: ";
            cout << p->dt.aa << "\n";
        }else if(p->pos == 'B'){
            cout << "The popped element is: ";
            cout << p->dt.bb << "\n";
        }else if(p->pos == 'C'){
            cout << "The popped element is: "; 
            cout << p->dt.cc << "\n";
        }

        delete p; // freeing the allocated memory using delete keyword
        top = top - 1;
    }else{
        cout << "Stack is empty! Can not do pop operation" << "\n";
    }
}

// Below is the implementation of the printAll() function of the stack class

void stack::printAll(){
    element *w;
    int x = top - 1;
    cout << "The current status of stack is: " << "\n";
    while(x>=0){
        w = arr[x];
        if(w->pos == 'A'){
            cout << w->dt.aa << "\n";
        }else if(w->pos == 'B'){
            cout << w->dt.bb << "\n";
        }else if(w->pos == 'C'){
            cout << w->dt.cc << "\n";
        }
        x = x - 1;
    }
}

// Below is the implementation of the Full() function of the stack class

bool stack::Full(){
    if(top >= maxSize){
        return(true);
    }else{
        return(false);
    }
}

// Below is the implementation of the Empty() function of the stack class

bool stack::Empty(){
    if(top == 0){
        return(true);
    }else{
        return(false);
    }
}

// Below is the implementation of the main method

int main() {
    stack st;

    char n;
    cin >> n; // User has to enter his choice on what to do
/*
    I for Insert
    D for Delete
    E for exit
    P for Print
*/
    while(n != 'E'){
        if(n == 'I'){
            st.Push();
        }else if(n == 'D'){
            st.Pop();
        }else if(n == 'P'){
            st.printAll();
        }
        cin >> n; // Taking the input again and again until user presses E for exit
    }
    cout << "Program is stopped";
}