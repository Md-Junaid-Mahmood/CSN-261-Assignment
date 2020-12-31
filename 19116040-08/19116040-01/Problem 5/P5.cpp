#include <iostream>
using namespace std;

// Below is the implementation of the binary search algorithm
// This algorithm is used to find the position of the element during Insertion Sort algorithm

int binarySearch(int arr[], int i, int j) {
    int k;
    int num = arr[j];
    j = j - 1;
    while( true){
        if( i > j){
            k = 0;
            return(k);
        }
        int mid = (int)((i + j)/2);
        if(arr[mid] > num){
            j = mid - 1;
        }else if(arr[mid] <= num){
            if(arr[mid+1] >= num){
                k = mid + 1;
                return(k);
            }else{
                i = mid + 1;
            }
        }
    }
}

// Below is the implementation of the main method

int main() {
    int n;
    cin >> n; // User has to enter the length of the array
    int i;
    int j;
    int arr[n];
    for(i = 0; i < n; i++){
        cin >> arr[i]; // User has to enter the n-elements of the array
    }

    for(j = 1; j < n; j++){
        int k = binarySearch(arr, 0, j);
        int t;
        int s = arr[j];
        for(t = j; t > k; t--){
            arr[t] = arr[t-1];
        }
        arr[k] = s;
    }
    cout << "The sorted array is [ ";
    for(j = 0; j < n; j++){
        cout << arr[j] << " ";
    }
    cout << "]";
}