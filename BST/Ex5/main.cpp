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

    void getMin(Node*root, int &min){
        if(root == nullptr)return;
        min = root->value;
        getMin(root->pLeft, min);
    }

    T getMin() {
        //TODO: return the minimum values of nodes in the tree.
        int min = root->value;
        getMin(root,min);
        return min;
    }

    void getMax(Node*root, int &max){
        if(root == nullptr)return;
        max = root->value;
        getMax(root->pRight, max);
    }

    T getMax() {
        //TODO: return the maximum values of nodes in the tree.
        int max = root->value;
        getMax(root,max);
        return max;
    }
    // STUDENT ANSWER END
};

int main(){
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(i);
    }
    cout << bst.getMin() << endl;
    cout << bst.getMax() << endl;
}