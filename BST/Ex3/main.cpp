#include <iostream>

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

int singleChild(BSTNode* root) {
    // STUDENT ANSWER
    if(!root)return 0;
    if(!root->left && root->right)return 1 + singleChild(root->right);
    else if (!root->right && root->left)return 1 + singleChild(root->left);
    else if (root->left&& root->right)return singleChild(root->right) + singleChild(root->left);
    else return 0;
}

int main() {
    int arr[] = {};
    BSTNode* root = BSTNode::createBSTree(arr, sizeof(arr)/sizeof(int));
    cout << singleChild(root);
    BSTNode::deleteTree(root);
}
