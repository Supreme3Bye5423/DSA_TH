#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
        clear(root);
    }

    void clear(Node *root) {
        if (root == nullptr)return;
        clear(root->pLeft);
        clear(root->pRight);
        delete root;
        root = nullptr;
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node *recursiveAdd(Node *root, T value) {
        if (root == nullptr)root = new Node(value);
        else {
            if (value > root->value)root->pRight = recursiveAdd(root->pRight, value);
            else root->pLeft = recursiveAdd(root->pLeft, value);
        }
        return root;
    }

    void add(T value) {
        //TODO
        if (root == nullptr) {
            root = recursiveAdd(nullptr, value);
        } else recursiveAdd(root, value);
    }
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.

    bool findi(Node*root, T i){
        if(root == nullptr)return false;
        if(root->value == i)return true;
        if(i < root->value)return findi(root->pLeft,i);
        else return findi(root->pRight,i);
    }

    bool find(T i) {
        // TODO: return true if value i is in the tree; otherwise, return false.
        return findi(root,i);
    }

    T sumOf(Node*root, T l, T r){
        if(root == nullptr)return 0;
        T result = sumOf(root->pLeft,l,r) + sumOf(root->pRight,l,r);
        if(l <= root->value && root->value <= r)result += root->value;
        return result;
    }

    T sum(T l, T r) {
        // TODO: return the sum of all element in the tree has value in range [l,r].
        return sumOf(root,l,r);
    }

// STUDENT ANSWER END
};

int main(){
    int values[] = { 66,60,84,67,21,45,62,1,80,35 };
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }

    cout << bst.find(5) << endl;
    cout << bst.sum(10, 40);
}