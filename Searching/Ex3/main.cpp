#include <iostream>
#include <math.h>

using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int i = 0;
    int jump = sqrt(n);
    while(i < n){
        cout << i << " ";
        if(arr[i] > x) break;
        else if(arr[i] == x) return i;
        i += jump;
    }
    for(int j = i - jump + 1; j < i; j ++){
        cout << j << " ";
        if(arr[j] ==x) return j ;
    }
    return -1;
}

int main() {
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 611, 612, 613, 1000, 1002, 2000, 2003, 2004, 2005, 2006 };
    int x = 36;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);

    if (index != -1) {
        cout << "\nNumber " << x << " is at index " << index;
    }
    else {
        cout << "\n" << x << " is not in array!";
    }
}
