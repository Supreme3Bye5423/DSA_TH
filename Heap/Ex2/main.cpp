#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);

    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();

    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position)
    {
        int child = 2 * position + 1;
        while (child < count) {
            if (child + 1 < count && elements[child] < elements[child + 1]) {
                child++;
            }
            if (elements[position] < elements[child]) {
                swap(elements[position], elements[child]);
                position = child;
                child = 2 * position + 1;
            } else {
                break;
            }
        }
    }
};

template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return (count == 0) ? true: false;
}

template<class T>
T Heap<T>::peek(){
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for(int i = 0; i < count; i++){
        if(elements[i] == item){
            return true;
        }
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if(count == 0)return false;
    elements[0] = elements[size() - 1];
    count--;
    reheapDown(0);
    return true;
}

template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count+1);
    elements[count] = item;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if(minCapacity > capacity){
        int newCapacity = minCapacity;
        T* newElements = new T[newCapacity];
        memcpy(newElements,elements,count*sizeof(T));
        delete []elements;
        elements = newElements;
        capacity = newCapacity;
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    if(position > 0){
        int parent = (position - 1)/2;
        if(parent >= 0 && elements[position] > elements[parent]){
            swap(elements[position],elements[parent]);
            reheapUp(parent);
        }
    }
}

int main() {
    Heap<int> maxHeap;
    for(int i = 0; i <5;i++)
        maxHeap.push(i);
    maxHeap.printHeap();
}
