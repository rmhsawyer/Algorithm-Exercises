#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
    ListNode* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}

//Ref: https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/
ListNode* insertionSortList(ListNode* head) {
    ListNode* current = head;
    ListNode* sortlist = NULL;
    if(current->next == NULL)
        return head;
    while(current != NULL){
        ListNode* next = current->next;
        ListNode* current1;
        if(sortlist == NULL || sortlist->val >= current->val)
        {
            current->next = sortlist;
            sortlist = current;
            printList(sortlist);
        }
        else
        {
            current1 = sortlist;
            while(current1->next != NULL && current1->next->val < current->val)
            {
                current1 = current1->next;
            }
            current->next = current1->next;
            current1->next = current;
        }
        current = next;

    }
    /* 

        Your implementation goes here. 
        It should return a pointer to the head of the sorted linked list.
    */
    return sortlist; // modify the return value appropriately in your implementation
}

bool detectCycle(ListNode* head) {
    ListNode* temp1 = head->next;
    ListNode* temp2 = head->next->next;
    if(head == NULL || temp1 == NULL){
        return false;
    }
    while(temp1->next != temp2 ->next){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        if(temp1 == NULL || temp2 == NULL)
            return false;
    }  
    /* 
        Your implementation goes here. 
        It should return true if a cycle exists and false otherwise.
    */
    return true; // modify the return value appropriately in your implementation
}

// Ref: https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
ListNode* findCycleStart(ListNode* head) {

    ListNode* temp1 = head->next;
    ListNode* temp2 = head->next->next;

    while(temp1->next != temp2 ->next){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        
    }
    temp1= head;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    /* 
        Your implementation goes here. 
        It should return a pointer to the node where the cycle starts. If there is no cycle, return NULL.
    */
    return temp1; // modify the return value appropriately in your implementation
}

