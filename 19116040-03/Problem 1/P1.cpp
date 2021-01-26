#include <iostream>
using namespace std;

// Below is the implementation of the class aeroplane
class aeroplane{
    private:

        struct node{
            string passengerID;
            int rowNumber;
            char seatNumber;
            node* next = NULL;
        };
        /*
        The struct node will store the passenger details
        For storing passenger details of a particular row and of given side linked list data type is used
        */

        int* arr;
        /*
        Above arr is used for storing the status of seats for a particular row
        1 when only left side is occupied 
        2 when only right side is occupied
        3 when both the rows are occupied
        0 in all other cases
        Memory will be allocated to it dynamically
        */

        node* leftSide;
        node* rightSide;
        /*
        Above mentioned leftSide and rightSide are used for accesing the first element 
        of left side and right side of the given row
        Memory will be allocated to it dynamically
        */

    public:

        aeroplane(int n);
        bool entry(int n);
        bool exit();
        void exitAll(int n);
        void printAll(int n);
        void freeMemory();
        bool checkEntry(string a, int b, char c, int n);
        bool checkExit(string a, int b, char c);
};

// Below is the implementation of the constructor of the class aeroplane
aeroplane::aeroplane(int n){
    leftSide = (node*)malloc(n*sizeof(node));
    rightSide = (node*)malloc(n*sizeof(node));
    arr = (int*)calloc(n, sizeof(int));
    /*
    Dynamically allocating the memory based on the number of rows entered by the user
    */

}

// Below is the implementation of the function entry(int n) of the class aeroplane
bool aeroplane::entry(int n){
    string a;
    cin >> a;

    int b;
    cin >> b;

    char c;
    cin >> c;
    /*
    Taking input from the user for entering the passenger details on the plane
    Input must be in the order - passenger ID, boarding row number and Seat number
    */

    node *s;
    s = new node;
    s->passengerID = a;
    s->rowNumber = b;
    s->seatNumber = c;
    /*
    We have dynamically allocated memory to a node in the above lines of code
    */

    bool xyz;
    xyz = checkEntry(a, b, c, n);
    /*
    Checking passenger with given passengerID exists on the plane or not
    If it exists the error message will be printed
    */

    if(xyz == true){
        if(c == 'A' || c == 'B' || c == 'C'){
            if(arr[b-1] == 2 || arr[b-1] == 0){
                (leftSide + b - 1)->passengerID = s->passengerID;
                (leftSide + b - 1)->rowNumber = s->rowNumber;
                (leftSide + b - 1)->seatNumber = s->seatNumber;
                (leftSide + b - 1)->next = NULL;
                cout << "Push " << s->passengerID << "\n";
                if(arr[b-1] == 2){
                    arr[b-1] = 3;
                }else{
                    arr[b-1] = 1;
                }
            }else{
                char d = (leftSide + b - 1)->seatNumber;
                if(c == 'C'){
                    node *q;
                    q = new node;
                    q->passengerID = (leftSide + b - 1)->passengerID;
                    q->rowNumber = (leftSide + b - 1)->rowNumber;
                    q->seatNumber = (leftSide + b - 1)->seatNumber;
                    q->next = (leftSide + b - 1)->next;

                    (leftSide + b - 1)->passengerID = s->passengerID;
                    (leftSide + b - 1)->rowNumber = s->rowNumber;
                    (leftSide + b - 1)->seatNumber = s->seatNumber;
                    (leftSide + b - 1)->next = q;
                    cout << "Push " << s->passengerID << "\n";
                }else if(c == 'B'){
                    node *q;
                    q = new node;
                    if(d == 'A'){
                        q->passengerID = (leftSide + b - 1)->passengerID;
                        q->rowNumber = (leftSide + b - 1)->rowNumber;
                        q->seatNumber = (leftSide + b - 1)->seatNumber;
                        q->next = (leftSide + b - 1)->next;
                        
                        (leftSide + b - 1)->passengerID = s->passengerID;
                        (leftSide + b - 1)->rowNumber = s->rowNumber;
                        (leftSide + b - 1)->seatNumber = s->seatNumber;
                        (leftSide + b - 1)->next = q;
                        cout << "Push " << s->passengerID << "\n";
                    }else if(d == 'C'){
                        s->next = (leftSide + b - 1)->next;
                        (leftSide + b - 1)->next = s;
                        cout << "Pop " << (leftSide + b - 1)->passengerID << "\n";
                        cout << "Push " << s->passengerID << "\n";
                        cout << "Push " << (leftSide + b - 1)->passengerID << "\n";
                    }
                }else if(c == 'A'){
                    node *q;
                    q = new node;
                    q = (leftSide + b - 1);

                    int k = 1;
                    while(q->next != NULL){
                        q = q->next;
                        k = 2;
                    }
                    q->next = s;
                    s->next = NULL;
                    if(k == 1){
                        cout << "Pop " << (leftSide + b - 1)->passengerID << "\n";
                        cout << "Push " << s->passengerID << "\n";
                        cout << "Push " << (leftSide + b - 1)->passengerID << "\n";
                    }else{
                        cout << "Pop " << (leftSide + b - 1)->passengerID << "\n";
                        cout << "Pop " << q->passengerID << "\n";
                        cout << "Push " << s->passengerID << "\n";
                        cout << "Push " << q->passengerID << "\n";
                        cout << "Push " << (leftSide + b - 1)->passengerID << "\n";
                    }
                }
            }
        }else if(c == 'D' || c == 'E' || c == 'F'){
            if(arr[b-1] == 1 || arr[b-1] == 0){
                (rightSide + b - 1)->passengerID = s->passengerID;
                (rightSide + b - 1)->rowNumber = s->rowNumber;
                (rightSide + b - 1)->seatNumber = s->seatNumber;
                (rightSide + b - 1)->next = NULL;
                cout << "Push " << s->passengerID << "\n";
                if(arr[b-1] == 1){
                    arr[b-1] = 3;
                }else{
                    arr[b-1] = 2;
                }
            }else{
                char d = (rightSide + b - 1)->seatNumber;
                if(c == 'F'){
                    node *q;
                    q = new node;
                    q->passengerID = (rightSide + b - 1)->passengerID;
                    q->rowNumber = (rightSide + b - 1)->rowNumber;
                    q->seatNumber = (rightSide + b - 1)->seatNumber;
                    q->next = (rightSide + b - 1)->next;

                    (rightSide + b - 1)->passengerID = s->passengerID;
                    (rightSide + b - 1)->rowNumber = s->rowNumber;
                    (rightSide + b - 1)->seatNumber = s->seatNumber;
                    (rightSide + b - 1)->next = q;
                    cout << "Push " << s->passengerID << "\n";
                }else if(c == 'E'){
                    node *q;
                    q = new node;
                    if(d == 'D'){
                        q->passengerID = (rightSide + b - 1)->passengerID;
                        q->rowNumber = (rightSide + b - 1)->rowNumber;
                        q->seatNumber = (rightSide + b - 1)->seatNumber;
                        q->next = (rightSide + b - 1)->next;

                        (rightSide + b - 1)->passengerID = s->passengerID;
                        (rightSide + b - 1)->rowNumber = s->rowNumber;
                        (rightSide + b - 1)->seatNumber = s->seatNumber;
                        (rightSide + b - 1)->next = q;
                        cout << "Push " << s->passengerID << "\n";
                    }else if(d == 'F'){
                        s->next = (rightSide + b - 1)->next;
                        (rightSide + b - 1)->next = s;
                        cout << "Pop " << (rightSide + b - 1)->passengerID << "\n";
                        cout << "Push " << s->passengerID << "\n";
                        cout << "Push " << (rightSide + b - 1)->passengerID << "\n";
                    }
                }else if(c == 'D'){
                    node *q;
                    q = new node;
                    q = (rightSide + b - 1);
                    int k = 1;
                    while(q->next != NULL){
                        q = q->next;
                        k = k + 1;
                    }
                    q->next = s;
                    s->next = NULL;
                    if(k == 1){
                        cout << "Pop " << (rightSide + b - 1)->passengerID << "\n";
                        cout << "Push " << s->passengerID << "\n";
                        cout << "Push " << (rightSide + b - 1)->passengerID << "\n";
                    }else{
                        cout << "Pop " << (rightSide + b - 1)->passengerID << "\n";
                        cout << "Pop " << q->passengerID << "\n";
                        cout << "Push " << s->passengerID << "\n";
                        cout << "Push " << q->passengerID << "\n";
                        cout << "Push " << (rightSide + b - 1)->passengerID << "\n";
                    }
                }
            }
        }
    }else{
        cout << "ERROR! Invalid details entered by the user\n";
        return(false);
    }
    return(true);
}

// Below is the implementation of the function exit() of the class aeroplane
bool aeroplane::exit(){
    string a;
    cin >> a;

    int b;
    cin >> b;

    char c;
    cin >> c;
    /*
    Taking input from the user about the passenger they want to remove from the plane
    Input must be in the order - passenger ID, boarding row number and Seat number
    */

    bool xyz;
    xyz  = checkExit(a, b, c);
    /*
    The above function checks whether the details entered by the user are valid or not.
    If it is not valid then error message will be printed
    */

    if(xyz == true){
        if(c == 'A' || c == 'B' || c == 'C'){
            node *r;
            r = (leftSide + b - 1);
            if(r->next == NULL){
                if(arr[b - 1] == 3){
                    arr[b - 1] = 2;
                }else{
                    arr[b - 1] = 0;
                }
                cout << "Pop " << r->passengerID << "\n";
            }else{
                node *r1, *r2;
                r1 = (leftSide + b - 1);
                r2 = (leftSide + b - 1);
                int k = 0;
                while(r1->seatNumber != c){
                    r2 = r1;
                    r1 = r1->next;
                    k = k + 1;
                }
                if(r1 == r2){
                    r2 = (leftSide + b - 1)->next;
                    cout << "Pop " << (leftSide + b - 1)->passengerID << "\n";
                    (leftSide + b - 1)->passengerID = r2->passengerID;
                    (leftSide + b - 1)->rowNumber = r2->rowNumber;
                    (leftSide + b - 1)->seatNumber = r2->seatNumber;
                    (leftSide + b - 1)->next = r2->next;
                    delete r2;
                }else{
                    if(k == 1){
                        cout << "Pop " << (leftSide + b - 1)->passengerID << "\n";
                        cout << "Pop " << r1->passengerID << "\n";
                        cout << "Push " << (leftSide + b - 1)->passengerID << "\n";
                    }else if(k == 2){
                        cout << "Pop " << (leftSide + b - 1)->passengerID << "\n";
                        cout << "Pop " << r2->passengerID << "\n";
                        cout << "Pop " << r1->passengerID << "\n";
                        cout << "Push " << r2->passengerID << "\n";
                        cout << "Push " << (leftSide + b - 1)->passengerID << "\n";
                    }
                    r2->next = r1->next;
                    delete r1;
                }
            }
        }else if(c == 'D' || c == 'E' || c == 'F'){
            node *r;
            r = (rightSide + b - 1);
            if(r->next == NULL){
                if(arr[b - 1] == 3){
                    arr[b - 1] = 1;
                }else{
                    arr[b - 1] = 0;
                }
                cout << "Pop " << r->passengerID << "\n";
            }else{
                node *r1, *r2;
                r1 = (rightSide + b - 1);
                r2 = (rightSide + b - 1);
                int k = 0;
                while(r1->seatNumber != c){
                    r2 = r1;
                    r1 = r1->next;
                    k = k + 1;
                }
                if(r1 == r2){
                    r2 = (rightSide + b - 1)->next;
                    cout << "Pop " << (rightSide + b - 1)->passengerID << "\n";
                    (rightSide + b - 1)->passengerID = r2->passengerID;
                    (rightSide + b - 1)->rowNumber = r2->rowNumber;
                    (rightSide + b - 1)->seatNumber = r2->seatNumber;
                    (rightSide + b - 1)->next = r2->next;
                    delete r2;
                }else{
                    if(k == 1){
                        cout << "Pop " << (rightSide + b - 1)->passengerID << "\n";
                        cout << "Pop " << r1->passengerID << "\n";
                        cout << "Push " << (rightSide + b - 1)->passengerID << "\n";
                    }else if(k == 2){
                        cout << "Pop " << (rightSide + b - 1)->passengerID << "\n";
                        cout << "Pop " << r2->passengerID << "\n";
                        cout << "Pop " << r1->passengerID << "\n";
                        cout << "Push " << r2->passengerID << "\n";
                        cout << "Push " << (rightSide + b - 1)->passengerID << "\n";
                    }
                    r2->next = r1->next;
                    delete r1;
                }
            }
        }
    }else{
        cout << "ERROR! Invalid details entered by the user \n";
        return(false);
    }
    return(true);
    /*
    Using delete keyword we are deallocating the memory allocated to the node
    This memory was initially allocated using new keyword in the entry(int n) function
    */
}

// Below is the implementation of the function exitAll(int n) of the class aeroplane
void aeroplane::exitAll(int n){
    cout << "The LIFO order of passengers is: \n";
    /*
    Using this function all passengers can be removed from the plane in the LIFO order
    */

    int i = 1;
    for(i = 1; i <= n; i++){
        if(arr[i - 1] == 1 || arr[i - 1] == 3){
            node *s;
            s = (leftSide + i - 1);
            cout << "Pop " << s->passengerID << "\n";
            if(s->next != NULL){
                node *r;
                r = s->next;
                cout << "Pop " << r->passengerID << "\n";
                if(r->next == NULL){
                    delete r;
                }else{
                    node *t;
                    t = r->next;
                    delete r;
                    cout << "Pop " << t->passengerID << "\n";
                    delete t;
                }

            }
        }
        if(arr[i - 1] == 2 || arr[i - 1] == 3){
            node *s;
            s = (rightSide + i - 1);
            cout << "Pop " << s->passengerID << "\n";
            if(s->next != NULL){
                node *r;
                r = s->next;
                cout << "Pop " << r->passengerID << "\n";
                if(r->next == NULL){
                    delete r;
                }else{
                    node *t;
                    t = r->next;
                    delete r;
                    cout << "Pop " << t->passengerID << "\n";
                    delete t;
                }
            }
        }
        arr[i - 1] = 0;
    }

    /*
    Using delete keyword memory was deallocated from the node
    This allocation was initially done using new keyword in the entry(int n) function
    */
}

// Below is the implementation of the function printAll(int n) of the class aeroplane
void aeroplane::printAll(int n){
    cout << "Flight occupancy status is: \n";
    /*
    This function just prints the passengerID of all the passengers currently in the board
    */

    cout << "\tA \tB \tC \t || \tF \tE \tD \n";
    int i = 1;
    for(i = 1; i <= n; i++){
        string x1 = "0";
        string x2 = "0";
        string x3 = "0";

        string x4 = "0";
        string x5 = "0";
        string x6 = "0";

        if(arr[i - 1] == 1 || arr[i-1] == 3){
            node *s;
            s = (leftSide + i - 1);
            while(s != NULL){
                char d = s->seatNumber;
                if(d == 'A'){
                    x1 = s->passengerID;
                }else if(d == 'B'){
                    x2 = s->passengerID;
                }else if(d == 'C'){
                    x3 = s->passengerID;
                }
                s = s->next;
            }
        }

        if(arr[i - 1] == 2 || arr[i-1] == 3){
            node *s;
            s = (rightSide + i - 1);
            while(s != NULL){
                char d = s->seatNumber;
                if(d == 'D'){
                    x4 = s->passengerID;
                }else if(d == 'E'){
                    x5 = s->passengerID;
                }else if(d == 'F'){
                    x6 = s->passengerID;
                }
                s = s->next;
            }
        }

        
        cout << "Row " << i  << "\t" << x1 << "\t" << x2 << "\t" << x3 << "\t || \t" << x6 << "\t" << x5 << "\t" << x4 << "\n";
    }
    cout << "__________________________________________________________\n";
}

// Below is the implementation of the function freeMemory() of the class aeroplane
void aeroplane::freeMemory(){
    free(leftSide);
    free(rightSide);
    free(arr);
    /*
    Using free() function the memory allocated to the various arrays are freed.
    This allocation was initially done using malloc() and calloc() function in the constructor of the class aeroplane
    */
}

// Below is the implementation of the function checkEntry(string a, int n) of the class aeroplane
bool aeroplane::checkEntry(string a, int b, char c, int n){
    /*
    This function returns true if there is no passenger in the plane having the same passengerID
    Here argument string a is used for comparisons with other passengerID
    It will return false if it finds a match
    */

    int i = b;
    if(c == 'A' || c == 'B' || c == 'C'){
        if(arr[i - 1] == 1 || arr[i - 1] == 3){
            node *s;
            s = (leftSide + i - 1);
            while(s != NULL){
                char ch = s->seatNumber;
                if(ch == c){
                    return(false);
                }
                s = s->next;
            }
        }
    }else if(c == 'D' || c == 'E' || c == 'F'){
        if(arr[i - 1] == 2 || arr[i - 1] == 3){
            node *s;
            s = (rightSide + i - 1);
            while(s != NULL){
                char ch = s->seatNumber;
                if(ch == c){
                    return(false);
                }
                s = s->next;
            }
        }
    }

    for(i = 1; i <= n; i++){
        if(arr[i - 1] == 1 || arr[i - 1] == 3){
            node *s;
            s = (leftSide + i - 1);
            while(s != NULL){
                string p = s->passengerID;
                int x = p.compare(a);
                if(x == 0){
                    return(false);
                }
                s = s->next;
            }
        }else if(arr[i - 1] == 2 || arr[i - 1] == 3){
            node *s;
            s = (rightSide + i - 1);
            while(s != NULL){
                string p = s->passengerID;
                int x = p.compare(a);
                if(x == 0){
                    return(false);
                }
                s = s->next;
            }
        }
    }
    return(true);
}

// Below is the implementation of the function checkExit(string a, int b, char c) of the class aeroplane
bool aeroplane::checkExit(string a, int b, char c){
    /*
    Below function checks whether the details entered by the user for removing a passenger is valid or not
    It will return true if it is valid
    Else it will return false
    */

    if(c == 'A' || c == 'B' || c == 'C'){
        if(arr[b - 1] == 1 || arr[b - 1] == 3){
            node *s;
            s = (leftSide + b - 1);
            while(s != NULL){
                string r1 = s->passengerID;
                char r2 = s->seatNumber;
                int x = a.compare(r1);
                if(x == 0 && r2 == c){
                    return(true);
                }
                s = s->next;
            }
        }
    }else if(c == 'D' || c == 'E' || c == 'F'){
        if(arr[b - 1] == 2 || arr[b - 1] == 3){
            node *s;
            s = (rightSide + b - 1);
            while(s != NULL){
                string r1 = s->passengerID;
                char r2 = s->seatNumber;
                int x = a.compare(r1);
                if(x == 0 && r2 == c){
                    return(true);
                }
                s = s->next;
            }
        }
    }
    return(false);
}

// Below is the implementation of the main function
int main(){
    int n;
    cin >> n;
    /*
    User has to enter the number of rows present in the aeroplane
    */

    aeroplane arp(n);
    string c;
    cin >> c;
    /*
    User is asked to enter his choice
    E1 for Passenger Entry
    E2 for Passenger Exit
    E for Program Exit
    P for Print
    X for Full Exit
    */

    int numberOfPassengers = 0;
    while(c.compare("E") != 0){
        if(c.compare("E1") == 0){
            if(numberOfPassengers < 6*n){
                bool q = arp.entry(n);
                if(q == true){
                    numberOfPassengers = numberOfPassengers + 1;
                }
            }else{
                string a1;
                int a2;
                char a3;
                cin >> a1;
                cin >> a2;
                cin >> a3;
                cout << "Aeroplane is full! Can not make new entry!\n";

                /*
                Even after the aeroplane is full, details of the user are accepted
                and after accepting the details error message is shown.
                This is done to ensure that the program may not run into unexpected state
                during the execution.
                */
            }            
        }else if(c.compare("E2") == 0){
            if(numberOfPassengers > 0){
                bool q = arp.exit();
                if(q == true){
                    numberOfPassengers = numberOfPassengers - 1;
                }
            }else{
                string a1;
                int a2;
                char a3;
                cin >> a1;
                cin >> a2;
                cin >> a3;
                cout << "Aeroplane is empty! Can not make furthur exit!\n";

                /*
                Even after the aeroplane is empty, details of the user are accepted
                and after accepting the details error message is shown.
                This is done to ensure that the program may not run into unexpected state
                during the execution.
                */
            }
        }else if(c.compare("P") == 0){
            arp.printAll(n);
        }else if(c.compare("X") == 0){
            arp.exitAll(n);
            numberOfPassengers = 0;
        }
        cin >> c;
        cout << "\n";
    }
    cout << "Program is stopped";
    arp.freeMemory();
}
