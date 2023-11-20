#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    T*min = nullptr;
    for (auto it = start; it != end - 1; it++){
        min = it;
        for(auto temp = it + 1; temp != end; temp++){
            if(*temp < *min){
                min = temp;
            }
        }
        if (min != it){
            swap(*min,*it);
            printArray(start,end);
        }
    }
    printArray(start,end);
}

int main() {
    int arr[] = {9, 2, 8, 1, 0, -2};
    Sorting<int>::selectionSort(&arr[0], &arr[6]);
}
