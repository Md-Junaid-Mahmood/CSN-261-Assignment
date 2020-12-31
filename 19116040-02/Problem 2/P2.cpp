#include <iostream>
using namespace std;

// Below is the implementation of the class linkedList
// Use of union data type is made as it is a memory efficient solution for storing unique ID of a student

class linkedList{
    private :
        struct node{
            union id{
                char rollNumber[21];
                char mobile[11];
                char otherID[21];
            };
            id identity;            // Union data type has been used for storing the unique ID of a student 
            std::string fullName;   // string data type for storing full name of a student
            std::string courseCode; // string data type for storing course code
            int age;                // integer data type for storing the age of a student
            std::string branch;     // string data type for storing branch of a student
            node *next;             // a pointer which will point to the next node
        }*p;

    public :
        linkedList();
        void add(char a, string b, string c, string d, int e, string f);
        void printAll(int n);
};

// Below is the implementation of the constructor of the class linkedList

linkedList::linkedList(){
    p = NULL;
}

// Below is the implementation of the add() function of the linkedList class
// This function will add new elements to the database

void linkedList::add(char a, string b, string c, string d, int e, string f){
    node *q, *r, *s;
    if(p == NULL){
        p = new node; // Allocating the memory of the node dynamically using new keyword

// Based on the choice entered by the user, the identity field of the node is being filled.
// Since it is of type union, it saves memory

        if(a == 'R'){
            int n = b.length();
            int i = 0;
            for(i = 0; i < n; i++){
                p->identity.rollNumber[i] = b.at(i);
            }
            p->identity.rollNumber[i] = '\0'; // to mark the end of char array
        }else if(a == 'M'){
            int n = b.length();
            int i = 0;
            for(i = 0; i < n; i++){
                p->identity.mobile[i] = b.at(i);
            }
            p->identity.mobile[i] = '\0'; // to mark the end of char array
        }else if(a == 'O'){
            int n = b.length();
            int i = 0;
            for(i = 0; i < n; i++){
                p->identity.otherID[i] = b.at(i);
            }
            p->identity.otherID[i] = '\0'; // to mark the end of char array
        }

        p->fullName = c;
        p->courseCode = d;
        p->age = e;
        p->branch = f;
        p->next = NULL;

    }else {
        s = new node; // Allocating the memory of the node dynamically using new keyword

// Based on the choice entered by the user, the identity field of the node is being filled.
// Since it is of type union, it saves memory

        if(a == 'R'){
            int n = b.length();
            int i = 0;
            for(i = 0; i < n; i++){
                s->identity.rollNumber[i] = b.at(i);
            }
            s->identity.rollNumber[i] = '\0'; // to mark the end of char array
        }else if(a == 'M'){
            int n = b.length();
            int i = 0;
            for(i = 0; i < n; i++){
                s->identity.mobile[i] = b.at(i);
            }
            s->identity.mobile[i] = '\0'; // to mark the end of char array
        }else if(a == 'O'){
            int n = b.length();
            int i = 0;
            for(i = 0; i < n; i++){
                s->identity.otherID[i] = b.at(i);
            }
            s->identity.otherID[i] = '\0'; // to mark the end of char array
        }

        s->fullName = c;
        s->courseCode = d;
        s->age = e;
        s->branch = f;

        q = p;
        r = q;

// Below set of comparisons is to set the correct position of the node based on its age

        while(q != NULL){
            if(q->age > e){
                break;
            }
            r = q;
            q = q->next;
        }
        if(r == q){
            q = s;
            s = p;
            p = q;
            p->next = s;
        }else if(q == NULL){
            r->next = s;
            s->next = NULL;
        }else{
            r->next = s;
            s->next = q;
        }
    }
}

// Below is the implementation of printAll() function of linkedList class
// This function will print all the nodes in the linked list

void linkedList::printAll(int n){
    node *w;
    w = p;
    int i;
    cout << "The sorted list of student is : \n";
    for(i = 0; i < n; i++){
        cout << w->identity.rollNumber << ", ";
        cout << w->fullName << ", ";
        cout << w->courseCode << ", ";
        cout << w->age << ", ";
        cout << w->branch << "\n";
        w = w->next;
    }
}

// Below is the implementation of the main function

int main() {
    linkedList L1;
    int n;
    cin >> n; // User is asked to enter the number of students whose details are to be entered in the database
    int i = 0;
    for(i = 0; i < n; i++){

// At each iteration details of the ith student are to be given as the input

        char a;
        string b, c, c1, c2, d, f;
        int e;

/*
    User has to enter the choice for ith student
        R for Roll number
        M for Mobile number
        O other unique ID
*/
        cin >> a;

        cin >> b; // User is asked to enter the corresponding value of the ID

        cin >> c1;
        getline(cin, c2, '\n'); // Use of this function is neccessary to read the complete name of the student if name has multiple spaces within it
        c = c1 + c2; // This variable c contains the full name of the ith student

        cin >> d; // User has to enter the course code of the student

        cin >> e; // User has to enter the age of the student

        cin >> f; // User has to enter the branch of the student

        L1.add(a, b, c, d, e, f); // Calling the add() function to fill the database
    }

    L1.printAll(n); // Calling the printAll() function to print all the nodes of the linked list
}

//While entering the detail of the student, values fields except fullName should not contain spaces within it

