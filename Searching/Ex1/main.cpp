#include <iostream>
#include <math.h>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    if(right >= left){
        int mid = floor((right - left)/2);
        if (x == arr[mid + left]){
            cout << "We traverse on index: " << mid + left << endl;
            return mid + left;
        }
        if (x < arr[mid + left]){
            cout << "We traverse on index: " << mid + left << endl;
            return binarySearch(arr, left, left + mid - 1, x);
        }
        if (x > arr[mid + left]){
            cout << "We traverse on index: " << mid + left << endl;
            return binarySearch(arr, left + mid + 1, right, x);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
}
