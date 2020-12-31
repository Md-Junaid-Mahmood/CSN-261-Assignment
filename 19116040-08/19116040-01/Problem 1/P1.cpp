#include <iostream>
#include <time.h>
using namespace std;

// Below function is the implementation of Quick Sort algorithm
// In this implementation any random element is made as the pivot element
// Random element is accessed by making use of inbuilt rand() and srand() function

void quickSort(int arr[], int i, int j){
    if(i >= j){
        return;
    }

    srand(time(0));
    int r = rand();

    int seq = j - i + 1;
    int a = r % seq;
    a = i + a;
    int p = arr[a];
    arr[a] = arr[j];
    arr[j] = p;

    int num = arr[j];
    int start = i;
    int end = j;
    while ( true ){
        while(start < j){
            if (arr[start] <= num){
                start = start + 1;
            }else {
                break;
            }
        }
        if(start == j){
            break;
        }
        while(end >= i){
            if (arr[end] >= num){
                end = end - 1;
            }else {
                break;
            }
        }
        if(end < start){
            break;
        }else{
            int temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[start];
    arr[start] = temp;
    quickSort(arr, i, start - 1);
    quickSort(arr, start + 1, j);
}

// Below is the main function of the program

int main() {
    int n;
    cin >> n; // User has to enter the total length of the initial array
    int i;
    int j;
    int arr[n];
    for(i = 0; i < n; i++){
        cin >> arr[i]; // User has to enter the n-elements of the array
    }
    quickSort(arr, 0, n-1);
    cout << "Sorted Array is [ ";
    for(i = 0; i < n;  i++){
        cout << arr[i] << " ";
    }
    cout << "]";
}