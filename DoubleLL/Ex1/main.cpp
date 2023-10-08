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



int main() {
    DLinkedList<int> list;
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(0, idx);
    }
    list.toString();
    cout << list.size();
    int num = 50;
    list.add(10,num);
    list.toString();
    cout << list.size();
}
