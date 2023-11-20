#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
    //Helping functions
    int getBalance(Node*subroot){
        if(!subroot) return 0;
        return getHeightRec(subroot->pLeft)- getHeightRec(subroot->pRight);
    }
    Node*recursiveInsertion(Node*root, T value){
        if(!root){
            Node*newNode = new Node(value);
            newNode->balance = BalanceValue(getBalance(newNode));
            return newNode;
        }
        if(value < root->data){
            root->pLeft = recursiveInsertion(root->pLeft,value);
            root->balance = BalanceValue(getBalance(root));
        }
        else{
            root->pRight = recursiveInsertion(root->pRight,value);
            root->balance = BalanceValue(getBalance(root));
        }

        if(BalanceValue(root->balance) > 1 && root->pLeft->data > value){
            return rotateRight(root);
        }
        else if(BalanceValue(root->balance) > 1 && root->pLeft->data < value){
            root->pLeft = rotateLeft(root->pLeft);
            return rotateRight(root);
        }
        else if(BalanceValue(root->balance) < -1 && root->pRight->data < value){
            return rotateLeft(root);
        }
        else if(BalanceValue(root->balance) < -1 && root->pRight->data > value){
            root->pRight = rotateRight(root->pRight);
            return rotateLeft(root);
        }
        return root;
    }

    void insert(const T &value){
        //TODO
        root = recursiveInsertion(root,value);

    }
    Node* rotateLeft(Node* subroot)
    {
        //TODO: Rotate and return new root after rotate
        Node*rightSucc = subroot->pRight;
        Node*leftRightSucc = rightSucc->pLeft;

        subroot->pRight = leftRightSucc;
        rightSucc->pLeft = subroot;

        return rightSucc;
    };
    Node* rotateRight(Node* subroot)
    {
        //TODO: Rotate and return new root after rotate
        Node*leftSucc = subroot->pLeft;
        Node*rightLeftSucc = leftSucc->pRight;

        subroot->pLeft = rightLeftSucc;
        leftSucc->pRight = subroot;

        return leftSucc;
    };

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};

int main() {
    AVLTree<int> avl;
    for (int i = 0; i >= -10; i--){
        avl.insert(i);
    }
    avl.printTreeStructure();
}
