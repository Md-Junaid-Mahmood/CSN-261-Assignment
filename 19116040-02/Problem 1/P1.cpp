#include <iostream>
using namespace std;

//Below is the implementation of the main function

int main() {
    int n;
    cin >> n;  // User has to enter the length of the initial array
    int arr[n];
    int i = 0;
    for(i = 0; i < n; i++){
        cin >> arr[i];  // User is asked to enter the n-elements of the array
    }
    int k;
    cin >> k; // User has to enter the k-th position for finding the smallest element
    int j = 0;
    int index;

// In the below implementation we have used the concept of selection sort
// Only difference is that the loop will run only for k times
// Time complexity of this method is O(nk)

    for(j = 0; j < k; j++){
        index = j;
        for(i = j; i < n; i++){
            if(arr[i] < arr[index]){
                index = i;
            }
        }
        if(index == j){
            continue;
        }else{
            int temp = arr[index];
            arr[index] = arr[j];
            arr[j] = temp;
        }
    }
    j = j - 1;
    int num = arr[j];
    cout << "Kth smallest element is: " << num; // Program prints the final output
}

// Time complexity of above solution is O(nk)
// Using some comparison-based algorithm, such as QuickSort, MergeSort, HeapSort the time complexity would have been O(nlogn)
// Thus, it has been assumed that above program is mainly used in those situation,
// where k < log(n), as in this situation only above implementation would give better time complexity