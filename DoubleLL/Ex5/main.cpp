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
    int i = 1;
    ListNode*run = head;
    stack<ListNode*>stack;
    ListNode*first;
    ListNode*last;
    ListNode*front;
    ListNode*back;
    while(run != nullptr)
    {
        if (i == a){
            front = run->left;
            first = run;
        }
        if (i == b){
            back = run->right;
            last = run;
            break;
        }
        i++;
        run = run->right;
    }
    if (front != nullptr) front->right = nullptr;
    if (back != nullptr) back->left = nullptr;
    run = first;
    ListNode*temp,*stop = last->right;
    while(run != stop)
    {
        temp = run;
        run = run->right;
        temp->right = temp->left = nullptr;
        stack.push(temp);
    }
    run = front;
    for(i = a; i <= b;i++)
    {
        temp = stack.top();
        stack.pop();
        if (run != nullptr)run->right = temp;
        temp->left = run;
        if (run != nullptr)run = run->right;
        else run = temp, head = run;
    }
    run->right = back;
    if (back != nullptr)back->left = run;
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
    delete head;
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
