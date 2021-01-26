#include <iostream>
using namespace std;

// Below is the implementation of the class stack
class stack{
    private :
        char* arr;
        int top = -1;
    
    public :
        stack(int n);
        bool insert(char c);
        void remove();
        bool isEmpty();
        void freeMemory();
        char showLastElement();
};

// Below is the implementation of the constructor of the class stack
stack::stack(int n){
    top = 0;
    arr = (char*)malloc(n*sizeof(char)); 
    /*
        Dynamically allocating the memory to the stack based on the size of the input string
        The string consists of the sequences of square brackets, curly brackets and parentheses
    */
}

// Below is the implementation of the insert() function of the class stack
bool stack::insert(char c){
    bool xyz = isEmpty(); // Checks whether stack is empty
    if(xyz == true){
        if(c == '[' || c == '{' || c == '('){
            arr[top] = c;
            top = top + 1;
            return(true);
        }else{
            cout << "Unbalanced " << c << "\n";
            return(false);
        }
    }else{
        char d = arr[top - 1];
        if(c == '['){
            if(d == '['){
                arr[top] = c;
                top = top + 1;
                return(true);
            }else{
                char e;
                if(d == '{'){
                    e = '}';
                }else{
                    e = ')';
                }
                cout << "Missing priority of " << d << e << " and []\n";
                return(false);
            }
        }else if(c == '{'){
            if(d == '{' || d == '['){
                arr[top] = c;
                top = top + 1;
                return(true);
            }else{
                cout << "Missing priority of () and {}\n";
                return(false);
            }
        }else if(c == '('){
            arr[top] = c;
            top = top + 1;
            return(true);
        }else{
            int x1 = int(c);
            int x2 = int(d);
            int x3 = x1 - x2;
            if(x3 == 1 || x3 == 2){
                remove();
                return(true);
            }else{
                cout << "Unbalanced " << d << " and " << c << "\n";
                return(false);
            }
        }
    }
}

// Below is the implementation of the remove() function of the class stack
void stack::remove(){
    top = top - 1;
}

// Below is the implementation of the isEmpty() function of the class stack
bool stack::isEmpty(){
    if(top == 0){
        return(true);
    }else{
        return(false);
    }
}

// Below is the implementation of the freeMemory() function of the class stack
void stack::freeMemory(){
    free(arr); // Deallocating the memory of the stack
    top = -1;
}

// Below is the implementation of the showLastElement() function of the class stack
char stack::showLastElement(){
    char ch = ' ';
    if(isEmpty() == true){
        cout << "Stack is empty\n";
    }else{
        ch = arr[top - 1];
    }
    return(ch);
}

// Below is the implementation of the main function of the program 
int main() {
    string txt;
    cin >> txt; // User is asked to enter a string as input
    int n = txt.length();
    stack st(n);
    int i = 0;
    bool val = true;
    while(val == true && i < n){
        char ch = txt[i];
        val = st.insert(ch);
        i = i + 1;
    }
    if(val == true && i == n){
        if(st.isEmpty() == true){
            cout << "No error found\n";
        }else{
            char ch = st.showLastElement();
            cout << "Unbalanced " << ch << "\n";
        }
    }
    st.freeMemory();
    cout << "Program is stopped\n";
}