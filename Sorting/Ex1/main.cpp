#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// You must use the nodes in the original list and must not modify ListNode's val attribute.
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    if(!a)return b;
    if(!b)return a;
    ListNode*result = nullptr;
    if(a->val<=b->val){
        result = a;
        result->next = mergeLists(a->next, b);
    }
    else{
        result = b;
        result->next = mergeLists(a, b->next);
    }
    return result;
}

// Sort and unsorted list given its head pointer

int size(ListNode*head){
    if(head == nullptr)return 0;
    else return 1 + size(head->next);
}

ListNode* findAt(ListNode* head, int index) {
    if (index == 0) return head;
    return findAt(head->next, index - 1);
}

ListNode* mergeSortList(ListNode*head) {
    if(!head || !head->next)return head;

    int Mid = size(head)/2;
    ListNode*midNode = findAt(head,Mid);
    ListNode*beforemidNode = findAt(head, Mid - 1);
    beforemidNode->next = nullptr;
    ListNode*left = head;
    ListNode*right = midNode;

    left = mergeSortList(left);
    right = mergeSortList(right);
    return mergeLists(left,right);
}

ListNode*init(int arr[], int size, unordered_map<ListNode*,int>nodeAddr){
    ListNode*head = new ListNode(arr[0]);
    nodeAddr[head] = 0;
    ListNode*run = head;
    for(int i = 1; i < size; i++){
        ListNode*temp = new ListNode(arr[i]);
        nodeAddr[temp] = i;
        run->next = temp;
        run = temp;
        temp = nullptr;
    }
    return head;
}

void printList(ListNode*head, unordered_map<ListNode*,int>nodeAddr){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {6,2,1,4,3,5,8,9,7,15,0};
    unordered_map<ListNode*, int> nodeAddr;
    ListNode* head = init(arr1, sizeof(arr1) / 4, nodeAddr);
    head = mergeSortList(head);
    printList(head,nodeAddr);
}
