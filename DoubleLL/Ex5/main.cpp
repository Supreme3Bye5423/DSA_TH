#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* reverse(ListNode* head, int a, int b) {
    //TODO:
    if (a==b)return head;
    ListNode*aNode;
    ListNode*bNode;
    int i = 1;
    ListNode*run = head;
    while(run != nullptr)
    {
        if(i == a)
        {
            aNode = run;
        }
        else if (i == b)
        {
            bNode = run;
        }
        run = run->right;
        i++;
    }
    if (a == 1 && b == i - 1)
    {
        ListNode*Ra = aNode->right,*Lb = bNode->left;
        Ra->left = bNode;
        Lb->right = aNode;
        aNode->right = nullptr;aNode->left = Lb;
        bNode->right = Ra; bNode->left = nullptr;
        head = bNode;
    }
    else
    {
        if (a != 1 && b != i - 1)
        {
            ListNode*temp;
            temp = aNode->right;
            aNode->right = bNode->right;
            bNode->right = temp;
            if(aNode->right != nullptr)aNode->right->left = aNode;
            if(bNode->right != nullptr)bNode->right->left = bNode;

            temp = aNode->left;
            aNode->left = bNode->left;
            bNode->left = temp;
            if(aNode->left != nullptr)aNode->left->right = aNode;
            if(bNode->left != nullptr)bNode->left->right = bNode;
        }
        else if (a == 1)
        {
            ListNode*Ra = aNode->right, *Rb = bNode->right, *Lb = bNode->left;
            Ra->left = bNode;
            Lb->right = Rb->left = aNode;
            aNode->right = Rb;aNode->left = Lb;
            bNode->right = Ra; bNode->left = nullptr;
            head = bNode;
        }
        else if (b == i - 1)
        {
            ListNode*Ra = aNode->right, *La = aNode->left,*Lb = bNode->left;
            La->right = Ra->left = bNode;
            Lb->right = aNode;
            aNode->right = nullptr;aNode->left = Lb;
            bNode->right = Ra; bNode->left = La;
        }
    }
    return head;
}

ListNode*init(int*list, int size)
{
    ListNode*head = new ListNode(list[0]);
    ListNode*run = head;
    for(int i = 1; i < size; i++)
    {
        ListNode*temp = new ListNode(list[i]);
        run->right = temp;
        temp->left = run;
        run = temp;
        temp = nullptr;
    }
    return head;
}

void printList(ListNode*print)
{
    ListNode*run = print;
    while(run!= nullptr)
    {
        cout << run->val << " ";
        run = run->right;
    }
    cout << endl;
}

void freeMem(ListNode*head)
{
    head = nullptr;
}

int main() {
    int size;
    cin >> size;
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    ListNode* head = init(list, size);
    ListNode* reversed = reverse(head, a, b);
    printList(reversed);
    freeMem(head);
    delete[] list;
    return 0;
}
