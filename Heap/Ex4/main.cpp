#include <iostream>

using namespace std;

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
    void push(T item)
    {
        ensureCapacity(count + 1);
        elements[count] = item;
        reheapUp(count);
        count++;
    }
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity)
    {
        if (minCapacity > capacity)
        {
            int newCapacity = max(2 * capacity, minCapacity);
            T* newElements = new T[newCapacity];
            memcpy(newElements, elements, count * sizeof(T));
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }
    }
    void reheapUp(int position)
    {
        int parent = (position - 1) / 2;
        while (position > 0 && elements[position] > elements[parent])
        {
            swap(elements[position], elements[parent]);
            position = parent;
            parent = (position - 1) / 2;
        }
    }
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
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i = 0; i < count; i++){
        if(elements[i] == item){
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    if (getItem(item) == -1) return;
    int index = getItem(item);
    swap(elements[index], elements[count - 1]);
    count -= 1;
    reheapUp(index);
    reheapDown(index);
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    delete[]elements;
    count = 0;
    capacity = 10;
    elements = new T[capacity];
}

int main() {
    Heap<int> maxHeap;
    int arr[] = {42,35,30,15,20,21,18,3,7,14};
    for (int i = 0; i < 10; i++)
        maxHeap.push(arr[i]);
    maxHeap.remove(42);
    maxHeap.remove(35);
    maxHeap.remove(30);
    maxHeap.printHeap();
    maxHeap.clear();
    maxHeap.printHeap();
}
