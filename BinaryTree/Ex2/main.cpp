#include <iostream>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

class BTNode {
public:
    int val;
    BTNode *left;
    BTNode *right;
    BTNode() {
        this->left = this->right = NULL;
    }
    BTNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
    BTNode(int val, BTNode*& left, BTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    static BTNode*createTree(int arr[], int size){
        if(size <= 0)return nullptr;
        BTNode*nodes = new BTNode[size];
        for(int i = 0; i < size; i++){
            nodes[i] = BTNode(i);
        }
        BTNode*root = nullptr;
        for(int i = 0; i < size; i++){
            if(arr[i] == -1){
                root = &nodes[i];
            }
            else{
                if (arr[i] >= 0 && arr[i] < size) {
                    if (!nodes[arr[i]].left) {
                        nodes[arr[i]].left = &nodes[i];
                    } else {
                        nodes[arr[i]].right = &nodes[i];
                    }
                } else {

                }
            }
        }
        return root;
    }

    int lowestAncestor(BTNode* root, int a, int b){
        if(root == nullptr)return 0;
        if(root->val == a || root->val == b)return root->val;
        int left_lowest = lowestAncestor(root->left, a,b);
        int right_lowest = lowestAncestor(root->right,a,b);
        if(left_lowest&&right_lowest){
            return root->val;
        }
        return (left_lowest!=0?left_lowest:right_lowest);
    }
};

int main() {
    int arr[] = {-1,0,0,2,2,3,3};
    int size = sizeof(arr)/sizeof(int);
    BTNode* root = BTNode::createTree(arr, size);
    cout << root->lowestAncestor(root,5,4);
}
