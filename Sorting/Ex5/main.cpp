#include <iostream>
#include <algorithm>
using namespace std;

class utility{
public:
    int data;
    int frequency;
    int firstInt;
    utility(){
        data = 20000000;
        frequency = 0;
        firstInt = 0;
    }
};

bool checkSort(utility a, utility b){
    if(a.frequency == b.frequency){
        return a.firstInt < b.firstInt;
    }
    else{
        return a.frequency > b.frequency;
    }
}

void sortByFrequency(int arr[], int n){
    utility*check = new utility[n];
    int *checkF = new int[n];
    for(int i = 0;i < n; i++)checkF[i] = arr[i];
    stable_sort(checkF,checkF+n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check[j].data == checkF[i]){
                check[j].frequency++;
                break;
            }
            else if(check[j].data == 20000000){
                check[j].data = checkF[i];
                check[j].frequency++;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check[i].data == arr[j]){
                check[i].firstInt = j;
                break;
            }
        }
        if(check[i].data == 20000000)break;
    }
    stable_sort(check, check+n, checkSort);
    int indexArray = 0;
    for(int i = 0; i < n; i++){
        if(check[i].data == 20000000)break;
        for(int F = 0; F < check[i].frequency; F++){
            arr[indexArray] = check[i].data;
            indexArray++;
        }
    }
}

int main() {
    int arr[] =  {-4,1,2,2,-4,9,1,-1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortByFrequency(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
