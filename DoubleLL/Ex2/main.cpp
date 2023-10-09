#include <bits/stdc++.h>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();

        // Prefix ++ overload
        Iterator &operator++();

        // Postfix ++ overload
        Iterator operator++(int);
    };
};

/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin)
{
    this->pList = pList;
    if(begin)
    {
        if(pList != NULL)
        {
            index = 0;
            current = pList->head;
        }
        else
        {
            index = -1;
            current = NULL;
        }
    }
    else
    {
        current = NULL;
        if(pList != NULL)index=pList->count;
        else index = 0;
    }
}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    pList = iterator.pList;
    index = iterator.index;
    current = iterator.current;
    return *this;
}

template <class T>
void DLinkedList<T>::Iterator::set(const T &e)
{
    if(current == NULL)throw out_of_range("Segmentation fault!");
    current->data = e;
}

template<class T>
T& DLinkedList<T>::Iterator::operator*()
{
    //if(current == NULL)throw out_of_range("Segmentation fault!");
    return current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove()
{
    /*
    * TODO: delete Node in pList which Node* current point to.
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
    if(current == NULL)throw out_of_range("Segmentation fault!");
    if(current == pList->head)
    {
        pList->removeAt(0);
        current = nullptr;
        index = -1;
    }
    else
    {
        current=current->previous;
        pList->removeAt(index);
        index--;
    }
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator)
{
    return !(current == iterator.current && index == iterator.index);
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++()
{
    if(index == pList->count)throw out_of_range("Segmentation fault!");
    if (index == - 1) {
        current = pList->head;
        index = 0;
    }
    else
    {
        current = current->next;
        index++;
    }
    return*this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int)
{
    if(index == pList->count)throw out_of_range("Segmentation fault!");
    Iterator temp = *this;
    if (index == - 1) {
        current = pList->head;
        index = 0;
    }
    else
    {
        current = current->next;
        index++;
    }
    return temp;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
