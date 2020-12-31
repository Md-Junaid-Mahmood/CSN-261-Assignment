#include <iostream>
using namespace std;

// Below function is used to convert decimal numbers into 8-bit binary numbers
// Use of constraint (decimal number is bounded between 0 and 255) is made
// Binary number is returned in the form of a string

string binaryConverter(int n){
    int arr[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int j = 0;
    string str = "";
    for(j = 0; j <= 7; j++){
        if(n >= arr[j]){
            n = n - arr[j];
            str = str + "1";
        }else {
            str = str + "0";
        }
    }
    return(str);
}

// Below function is used to convert a 8-bit binary number into decimal number
// Use of constraint (decimal number is bounded between 0 and 255) is made
// Binary number was stored in the form of strings

int decimalConverter(string str){
    int arr[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int num = 0;
    int i;
    for(i = 0; i < 8; i++){
        char h = str[i];
        if(h == '1'){
            num = (num + arr[i]);
        }
    }
    return(num);
}

// Below is the implementation of Count Sort algorithm
// 2 bit at a time is considered in the below Count Sort algorithm

void countSort(string arr[], string brr[], int i, int j, int n){
    int crr[4] = {0, 0, 0, 0};
    int drr[n];
    int k;
    for(k = 0; k < n; k++){
        string str = arr[k];
        char a = str[i];
        char b = str[j];
        if(a == '0' && b == '0'){
            crr[0] = crr[0] + 1;
            drr[k] = 0;
        }else if(a == '0' && b == '1'){
            crr[1] = crr[1] + 1;
            drr[k] = 1;
        }else if(a == '1' && b == '0'){
            crr[2] = crr[2] + 1;
            drr[k] = 2;
        }else {
            crr[3] = crr[3] + 1;
            drr[k] = 3;
        }
    }
    for(k = 1; k < 4; k++){
        crr[k] = crr[k] + crr[k-1];
    }
    for(k = n - 1; k >= 0 ; k--){
        brr[crr[drr[k]] - 1] = arr[k];
        crr[drr[k]] = crr[drr[k]] - 1;
    }
}

// Below is the implementation of the main method

int main() {
    int n;
    cin >> n; // User has to enter the length of the array
    string arr[n];
    int i;
    for(i = 0; i < n; i++){
        int h;
        cin >> h; // User has to enter the n-elements of the array

        string str = binaryConverter(h); 
        arr[i] = str; // Binary numbers are stored in the form of string in the array
    }
    string brr[n];
    /*
        Since we only have 8-bit numbers and we are considering 2 bit at a time
        for Count Sort algorithm, so we need to call countSort function 4 times
    */
    countSort(arr, brr, 6, 7, n);
    countSort(brr, arr, 4, 5, n);
    countSort(arr, brr, 2, 3, n);
    countSort(brr, arr, 0, 1, n);
    int res[n];
    for(i = 0; i < n; i++){
        int q = decimalConverter(arr[i]);
        res[i] = q;
    }
    cout << "The sorted array is [ ";
    for(i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << "]";
}