#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    //Helping functions go here
    static void heapSort(T* start, T* end){
        //TODO
        make_heap(start, end);
        sort_heap(start,end);
        Sorting<T>::printArray(start,end);
    }

};
#endif /* SORTING_H */

int main(){
    int arr[4]={4,2,9,1};
    Sorting<int>::heapSort(&arr[0],&arr[4]);
}