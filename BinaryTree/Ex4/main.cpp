#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN
    // STUDENT ANSWER BEGIN
// You can define other functions here to help you.

    int height(Node*root){
        if(root == nullptr)return 0;
        int lh = height(root->pLeft);
        int rh = height(root->pRight);
        return 1 + (lh > rh ? lh: rh);
    }

    int getHeight() {
        // TODO: return height of the binary tree.
        return height(root);
    }

    string preOrder(Node*root){
        if(root == nullptr)return "";
        string result = to_string(root->value) + " ";
        return result + preOrder(root->pLeft) + preOrder(root->pRight);
    }

    string preOrder() {
        // TODO: return the sequence of values of nodes in pre-order.
        return preOrder(root);
    }

    string inOrder(Node*root){
        if(root == nullptr)return "";
        string result = to_string(root->value) + " ";
        return inOrder(root->pLeft) + result + inOrder(root->pRight);
    }

    string inOrder() {
        // TODO: return the sequence of values of nodes in in-order.
        return inOrder(root);
    }

    string postOrder(Node*root){
        if(root == nullptr)return "";
        string result = to_string(root->value) + " ";
        return postOrder(root->pLeft) + postOrder(root->pRight) + result;
    }

    string postOrder() {
        // TODO: return the sequence of values of nodes in post-order.
        return postOrder(root);
    }
    // STUDENT ANSWER END
};

int main() {
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4);
    binaryTree.addNode("L", 3, 6);
    binaryTree.addNode("R", 5, 9);
    binaryTree.addNode("LL", 4, 10);
    binaryTree.addNode("LR", 6, 2);

    cout << binaryTree.getHeight() << endl;
    cout << binaryTree.preOrder() << endl;
    cout << binaryTree.inOrder() << endl;
    cout << binaryTree.postOrder() << endl;
}
