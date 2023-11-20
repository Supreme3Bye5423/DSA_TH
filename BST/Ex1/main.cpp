#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class BinarySearchTree {
public:
    class Node;

private:
    Node *root;
public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
        clear(this->root);
    }

    void clear(Node *root) {
        if (root == nullptr)return;
        clear(root->pLeft);
        clear(root->pRight);
        delete root;
        root = nullptr;
    }

    //Helping function

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

    Node *deleteNode(Node *root, T value) {
        //Base case
        if (root == nullptr)return root;
        //Finding the node to delete
        if (root->value > value){
            root->pLeft = deleteNode(root->pLeft, value);
            return root;
        }
        else if (root->value < value){
            root->pRight = deleteNode(root->pRight, value);
            return root;
        }
        //Already find that node

        if (root ->pLeft == nullptr) {
            Node *temp = root->pRight;
            delete root;
            return temp;
        }
        else if (root->pRight == nullptr){
            Node*temp = root->pLeft;
            delete root;
            return temp;
        }
        else{
            Node*succParent = root;

            Node*succ = root->pRight;
            while(succ->pLeft != nullptr){
                succParent = succ;
                succ = succ->pLeft;
            }
            if(succParent != root) succParent->pLeft = succ->pRight;
            else succParent->pRight = succ->pRight;

            root->value = succ->value;

            delete succ;
            return root;
        }
    }

    void deleteNode(T value){
        //TODO
        root = deleteNode(root,value);
    }

    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }

    string inOrder(){
        return inOrderRec(this->root);
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
};

int main(){
    BinarySearchTree<int> bst;
    bst.add(9);
    bst.add(2);
    bst.add(10);
    bst.add(8);
    cout << bst.inOrder()<<endl;
    bst.add(11);
    bst.deleteNode(9);
    cout << bst.inOrder();
}