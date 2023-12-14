#include <iostream>
using namespace std;

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int left = index*2 + 1;
    int right = index*2 + 2;
    int largest = index;
    if(left < numberOfElements and maxHeap[left] > maxHeap[largest]){
        largest = left;
    }
    if(right < numberOfElements and maxHeap[right] > maxHeap[largest]){
        largest = right;
    }
    if(largest != index){
        swap(maxHeap[index], maxHeap[largest]);
        reheapDown(maxHeap,numberOfElements,largest);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if(index > 0){
        int parent = (index - 1)/2;
        if(maxHeap[index] > maxHeap[parent]){
            swap(maxHeap[index], maxHeap[parent]);
            reheapUp(maxHeap, numberOfElements, parent);
        }
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    reheapUp(arr,size,7);
    cout << "[ ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << "]";
}
