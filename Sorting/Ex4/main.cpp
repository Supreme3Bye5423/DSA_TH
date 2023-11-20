#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

string minDiffPairs(int* arr, int n){
    // STUDENT ANSWER
    if(n == 1)return "";
    sort(arr, arr+n);
    int min = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        if(min > (abs(arr[i] - arr[i + 1]))){
            min = (abs(arr[i] - arr[i + 1]));
        }
    }
    string result;
    for(int i = 0; i < n - 1; i++){
        if ((abs(arr[i] - arr[i + 1])) == min){
            result += "(" + to_string(arr[i]) + ", " + to_string(arr[i + 1]) + "), ";
        }
    }
    result.pop_back();
    result.pop_back();
    return result;
}

int main() {
    int arr[] = {10, -1, -150, 200};
    cout << minDiffPairs(arr,sizeof(arr)/4);
}
