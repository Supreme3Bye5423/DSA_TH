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
    static BTNode* createTree(int arr[], int size, int value[]) {
        if (size <= 0)
        {
            return nullptr;
        }

        BTNode* nodes = new BTNode[size];

        for (int i = 0; i < size; i++)
        {
            nodes[i] = BTNode(value[i]);
        }

        BTNode* root = nullptr;

        for (int i = 0; i < size; i++) {
            if (arr[i] == -1) {
                root = &nodes[i];  // Found the root
            } else {
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
};
int sumUntil(BTNode*root, int val){
    if(root == nullptr)return 0;
    val = (val*10 + root->val)%27022001;
    if(root->left == nullptr && root->right == nullptr)return val;
    else return (sumUntil(root->left,val) + sumUntil(root->right, val))%27022001;
}
int sumDigitPath(BTNode* root) {
    return sumUntil(root,0);
}

int main() {
    int arr[] = {-1,0,0,2,2};
    int value[] = {3,5,2,1,4};
    BTNode* root = BTNode::createTree(arr,sizeof(arr)/sizeof(int),value);
    cout << sumDigitPath(root);
}
