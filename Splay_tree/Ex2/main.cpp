#include <iostream>

using namespace std;

class SplayTree {
    struct Node {
        int val;
        Node* pLeft;
        Node* pRight;
        Node* pParent;
        Node(int val = 0, Node* l = nullptr, Node* r = nullptr, Node* par = nullptr) : val(val), pLeft(l), pRight(r), pParent(par) { }
    };
    Node* root;

    // print the tree structure for local testing
    void printBinaryTree(string prefix, const Node* root, bool isLeft, bool hasRightSibling) {
        if (!root && isLeft && hasRightSibling) {
            cout << prefix << "|--\n";
        }
        if (!root) return;
        cout << prefix;
        if (isLeft && hasRightSibling)
            cout << "|--";
        else
            cout << "L__";
        cout << root->val << '\n';
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pLeft, true, root->pRight);
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pRight, false, root->pRight);
    }

    void printPreorder(Node* p) {
        if (!p) {
            return;
        }
        cout << p->val << ' ';
        printPreorder(p->pLeft);
        printPreorder(p->pRight);
    }
public:
    SplayTree() {
        root = nullptr;
    }
    ~SplayTree() {
        // Ignore deleting all nodes in the tree
    }

    void printBinaryTree() {
        printBinaryTree("", root, false, false);
    }

    void printPreorder() {
        printPreorder(root);
        cout << "\n";
    }

    Node*rightRotate(Node*x){
        Node*y = x->pLeft;
        x->pLeft = y->pRight;
        y->pRight = x;
        return y;
    }

    Node*leftRotate(Node*x){
        Node*y = x->pRight;
        x->pRight = y->pLeft;
        y->pLeft = x;
        return y;
    }

    void zig(Node*x){
        Node*p = x->pParent;
        if(p->pLeft == x){
            Node*B = x->pRight;

            x->pParent = nullptr;
            x->pRight = p;

            p->pParent = x;
            p->pLeft = B;

            if(B) B->pParent = p;
        }
        else{
            Node*B = x->pLeft;

            x->pParent = nullptr;
            x->pLeft = p;

            p->pParent = x;
            p->pRight = B;

            if(B) B->pParent = p;
        }
    }

    void zig_zig(Node*x){
        Node *p = x -> pParent;
        Node *g = p -> pParent;
        if (p -> pLeft == x)
        {
            Node *B = x -> pRight;
            Node *C = p -> pRight;

            x -> pParent = g -> pParent;
            x -> pRight = p;

            p -> pParent = x;
            p -> pLeft = B;
            p -> pRight = g;

            g -> pParent = p;
            g -> pLeft = C;


            if (x -> pParent != nullptr)
            {
                if (x -> pParent -> pLeft == g) x -> pParent -> pLeft = x;
                else x -> pParent -> pRight = x;
            }

            if (B != NULL) B -> pParent = p;

            if (C != NULL) C -> pParent = g;
        }
        else
        {
            Node *B = p -> pLeft;
            Node *C = x -> pLeft;

            x -> pParent = g -> pParent;
            x -> pLeft = p;

            p -> pParent = x;
            p -> pLeft = g;
            p -> pRight = C;

            g -> pParent = p;
            g -> pRight = B;

            if (x -> pParent != NULL)
            {
                if (x -> pParent -> pLeft == g) x -> pParent -> pLeft = x;
                else x -> pParent -> pRight = x;
            }

            if (B != NULL) B -> pParent = g;

            if (C != NULL) C -> pParent = p;
        }
    }

    void zig_zag(Node *x)
    {
        Node *p = x -> pParent;
        Node *g = p -> pParent;
        if (p -> pRight == x)
        {
            Node *B = x -> pLeft;
            Node *C = x -> pRight;

            x -> pParent = g -> pParent;
            x -> pLeft = p;
            x -> pRight = g;

            p -> pParent = x;
            p -> pRight = B;

            g -> pParent = x;
            g -> pLeft = C;

            if (x -> pParent != NULL)
            {
                if (x -> pParent -> pLeft == g) x -> pParent -> pLeft = x;
                else x -> pParent -> pRight = x;
            }

            if (B != NULL) B -> pParent = p;

            if (C != NULL) C -> pParent = g;
        }
        else
        {
            Node *B = x -> pLeft;
            Node *C = x -> pRight;

            x -> pParent = g -> pParent;
            x -> pLeft = g;
            x -> pRight = p;

            p -> pParent = x;
            p -> pLeft = C;

            g -> pParent = x;
            g -> pRight = B;

            if (x -> pParent != NULL)
            {
                if (x -> pParent -> pLeft == g) x -> pParent -> pLeft = x;
                else x -> pParent -> pRight = x;
            }

            if (B != NULL) B -> pParent = g;

            if (C != NULL) C -> pParent = p;
        }
    }

    void splay(Node *x)
    {
        while (x -> pParent != NULL)
        {
            Node *p = x -> pParent;
            Node *g = p -> pParent;
            if (g == NULL) zig(x);
            else if (g -> pLeft == p && p -> pLeft == x) zig_zig(x);
            else if (g -> pRight == p && p -> pRight == x) zig_zig(x);
            else zig_zag(x);
        }
        this -> root = x;
    }

    void insert(int val) {
        // To Do
        if (root == NULL)
        {
            root = new Node(val);
            return;
        }
        Node *curr = this -> root;
        while (curr != NULL)
        {
            if (val < curr->val)
            {
                if (curr -> pLeft == NULL)
                {
                    Node *newNode = new Node(val);
                    curr -> pLeft = newNode;
                    newNode -> pParent = curr;
                    splay(newNode);
                    return;
                }
                else curr = curr -> pLeft;
            }
            else if (val >= curr -> val)
            {
                if (curr -> pRight == NULL)
                {
                    Node *newNode = new Node(val);
                    curr -> pRight = newNode;
                    newNode -> pParent = curr;
                    splay(newNode);
                    return;
                }
                else curr = curr -> pRight;
            }
        }
    }

    bool search(int x){
        //TODO
        Node *ret = NULL;
        Node *curr = this -> root;
        Node *prev = NULL;
        while (curr != NULL)
        {
            prev = curr;
            if (x < curr -> val) curr = curr -> pLeft;
            else if (x > curr -> val) curr = curr -> pRight;
            else
            {
                ret = curr;
                break;
            }
        }
        if (ret != NULL){
            splay(ret);
            return true;
        }
        else if (prev != NULL){
            splay(prev);
            return false;
        }
    }
};

int main() {
    SplayTree tree;
    int query;
    cin >> query;
    for(int i = 0; i < query; i++) {
        string op;
        int val;
        cin >> op >> val;
        if (op == "insert")
            tree.insert(val);
        else if (op == "search")
            cout << (tree.search(val) ? "found" : "not found") << '\n';
        else if (op == "print")
            tree.printPreorder();
    }
    tree.printBinaryTree();
}
