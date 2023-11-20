#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int  size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* start, T* middle, T* end) {
        int len1 = middle - start + 1;
        int len2 = end - middle;

        T*left = new T[len1];
        T*right = new T[len2];

        for(int i = 0; i < len1;i++){
            left[i] = start[i];
        }
        for(int i = 0; i < len2;i++){
            right[i] = middle[i + 1];
        }

        int i = 0, j = 0, k = 0;
        while(i < len1 and j < len2){
            if(left[i] < right[j]){
                start[k] = left[i];
                i++;
            }
            else{
                start[k] = right[j];
                j++;
            }
            k++;
        }
        while(i < len1){
            start[k] = left[i];
            i++;
            k++;
        }
        while(j < len2){
            start[k] = right[j];
            j++;
            k++;
        }
        delete left;
        delete right;
    }

public:

    static void InsertionSort(T* start, T* end) {
        // TODO
        int size = end - start + 1;
        int i,j,last;
        for(i = 1; i < size; i++){
            last = start[i];
            j = i;
            while((j > 0)&&(start[j - 1] > last)){
                start[j] = start[j - 1];
                j = j - 1;
            }
            start[j] = last;
        }
    }

    static void TimSort(T* start, T* end, int min_size) {
        // TODO
        // You must print out the array after using insertion sort and everytime calling method merge.
        if (start == nullptr) return;
        int size = end - start;
        if(size == 1)return;
        T*temp = start;
        for(int i = 0; i + min_size <= size; i += min_size){
            InsertionSort(temp, temp+min_size-1);
            temp+=min_size;
        }
        cout << "Insertion Sort: ";
        printArray(start,end);
        int count = 0;
        for(int MIN_SIZE = min_size; MIN_SIZE < size; MIN_SIZE *= 2){
            for(int left = 0; left < size; left += 2*MIN_SIZE){
                int mid = min((left + MIN_SIZE - 1), (size - 1));
                int right = min((left + 2*MIN_SIZE - 1), (size - 1));
                if (mid < right){
                    merge(start+left,start+mid, start+right);
                }
                count++;
                cout << "Merge " << count << ": ";
                printArray(start,end);
            }
        }
    }
};
#endif /* SORTING_H */


int main(){
    int array[] = { 19, 20, 18, 17 ,12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 3 };
    int min_size = 4;
    Sorting<int>::TimSort(&array[0], &array[20], min_size);
}