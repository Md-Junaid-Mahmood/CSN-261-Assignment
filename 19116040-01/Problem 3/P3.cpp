#include <iostream>
using namespace std;

// Below is the implementation of the main method

int main() {
    int n;
    cin >> n; // User has to enter the length of array
    int i;
    int arr[n];
    for(i = 0; i < n; i++){
        cin >> arr[i]; // User has to n-elements of the array
    }

    /*
     In the for loop below elements are being interchanged by making use of only loop variable
    */

    for(i = 0; i < (int)(n/2); i++){
        arr[i] = (arr[i] + arr[n - 1 - i] - (arr[n - 1 - i] = arr[i]));
    }
    cout << "The reversed array is [ ";
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "]";
}