#include <iostream>

using namespace std;

int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos;
    if(left <= right && x >= arr[left] && x <= arr[right]){
        pos = left + (((double)(right - left) / (arr[right] - arr[left]))
                 * (x - arr[left]));
        if(arr[pos] == x){
            cout << "We traverse on index: " << pos << endl;
            return pos;
        }
        if(arr[pos] > x){
            cout << "We traverse on index: " << pos << endl;
            return interpolationSearch(arr, left, pos - 1, x);
        }
        if(arr[pos] < x){
            cout << "We traverse on index: " << pos << endl;
            return interpolationSearch(arr,pos + 1, right, x);
        }
    }
    return -1;
}

int main() {
    int arr[] = { 2,3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int result = interpolationSearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
}
