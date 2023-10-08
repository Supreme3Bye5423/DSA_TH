#include <bits/stdc++.h>
using namespace std;

template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
    void toString()
    {
        cout << "[";
        Node*run = head;
        while(run != NULL) {
            if (run->next != NULL)
            {
                cout << run->data << ", ";
            }
            else
            {
                cout << run->data;
            }
            run = run ->next;
        }
        cout << "]";
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

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

};

template<class T>
DLinkedList<T>::DLinkedList()
{
    head = new Node();
    tail = new Node();
    count = 0;
}

template<class T>
DLinkedList<T>::~DLinkedList() {
    delete head;
    delete tail;
}

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    if (count == 0)
    {
        Node*newNode = new Node(e);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node*newNode = new Node(e);
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    if (index < 0 || index > count)
    {
        throw out_of_range("");
    }
    else
    {
        Node*run = head;
        if (count == 0)
        {
            add(e);
            return;
        }
        else if (index == 0)
        {
            Node*newNode = new Node(e);
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
        else if (index == count)
        {
            add(e);
            return;
        }
        else
        {
            Node*temp = head;
            Node*run = temp->next;
            for(int i = 0; i < index - 1; i++)
            {
                temp = run;
                run = run->next;
            }
            Node*newNode = new Node(e);
            newNode->next = run;
            newNode->previous = temp;
            run->previous = newNode;
            temp->next = newNode;
        }
        count++;
    }
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */
    return count;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count)
    {
        throw out_of_range("");
    }
    else{
        count--;
        if (count == 0)
        {
            int val = head->data;
            clear();
            return val;
        }
        else if (index == 0)
        {
            Node*temp = head;
            head= head->next;
            head->previous = nullptr;
            int val = temp->data;
            delete temp;
            return val;
        }
        else if (index == count)
        {
            Node*temp = tail;
            tail = tail->previous;
            tail->next = nullptr;
            int val = temp->data;
            delete temp;
            return val;
        }
        else
        {
            Node *temp = head;
            Node* run = temp->next;
            for(int i = 0; i < index - 1; i++)
            {
                temp = run;
                run = run->next;
            }
            int val = run->data;
            Node*next = run->next;
            temp->next = next;
            next->previous = temp;
            delete run;
            return val;
        }
    }
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node*run = head;
    int index = 0;
    while(run != NULL)
    {
        if (run->data == item)
        {
            removeAt(index);
            return true;
        }
        run = run->next;
        index++;
    }
    return false;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    head = nullptr;
    tail = nullptr;
    count = 0;
}

int main() {
    DLinkedList<int> list;
    int size = 3;
    int value[] = {0,2,3};

    for(int idx=0; idx < size; idx++){
        list.add(value[idx]);
    }
    list.removeItem(3);
    cout << list.size();
    list.toString();
}
