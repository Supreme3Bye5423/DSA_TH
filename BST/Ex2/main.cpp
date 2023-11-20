#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class BSTNode {
public:
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode() {
        this->left = this->right = nullptr;
    }
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    static void deleteTree(BSTNode*root){
        if(root == nullptr)return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }

    static BSTNode*makeTree(BSTNode*root, int val){
        if(root == nullptr){
            root = new BSTNode(val);
        }
        else{
            if(val > root->val){
                root->right = makeTree(root->right, val);
            }
            else{
                root->left = makeTree(root->left, val);
            }
        }
        return root;
    }

    static BSTNode*createBSTree(int arr[], int n){
        BSTNode*temp = nullptr,*root;
        root = makeTree(temp,arr[0]);
        for(int i = 1; i < n; i++){
            makeTree(root,arr[i]);
        }
        return root;
    }
};

void inOrder(BSTNode*root, queue<int>&Q){
    if(root == nullptr)return;
    inOrder(root->left, Q);
    Q.push(root->val);
    inOrder(root->right, Q);
}

int kthSmallest(BSTNode* root, int k) {
    // STUDENT ANSWER
    queue<int>Q;
    inOrder(root,Q);
    for(int i = 0; i < k - 1; i++){
        Q.pop();
    }
    return Q.front();
}

int main() {
    int arr[] = {6, 9, 2, 13, 0, 20};
    int k = 2;
    BSTNode* root = BSTNode::createBSTree(arr, sizeof(arr)/sizeof(int));
    cout << kthSmallest(root, k);
    BSTNode::deleteTree(root);
}
