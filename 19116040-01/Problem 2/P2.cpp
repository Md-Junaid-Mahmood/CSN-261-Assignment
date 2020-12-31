#include <iostream>
using namespace std;

// Below is the implementation of the main method

int main() {
    int n;
    cin >> n; // User has to enter the length of the initial array
    int arr[n];
    int i;
    int j;
    for(i = 0; i < n; i++){
            cin >> arr[i]; // User has to enter the n-elements of the array
    }
    int num;
    cin >> num; // User has to enter the value or key to find
    i = 0;
    j = n - 1;
    int k;
    /*
        Below is the implementation of the binary search. 
        This binary search has an additional feature that it will return the index 
        corresponding to the first occurence of the key or number
    */
    while( true ){
            if(i>j){
                    k = -1;
                    break;
            }
            int mid = (int)((i+j)/2);
            if(arr[mid] == num){
                    if(mid == 0){
                            k = mid;
                            break;
                    }else if(arr[mid-1] != arr[mid]){
                            k = mid;
                            break;
                    }else{
                            while(mid>=0){
                                    if(arr[mid] == num){
                                            k = mid;
                                            mid = mid - 1;
                                    }else{
                                            break;
                                    }
                            }
                            break;
                    }
            }else if(arr[mid] < num){
                    i = mid + 1;
            }else{
                    j = mid;
            }
    }
    if(k == -1){
            cout << "Given number is not present in the array";
    }else{
            cout << "Given number is prsent at index " << k;
    }
}