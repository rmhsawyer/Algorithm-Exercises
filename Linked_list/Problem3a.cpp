#include "ListNode.h"

int main() {

	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(4);
	// ListNode* n4 = new ListNode(3);

	n1->next = n2;
	n2->next = n3;
	// n3->next = n4;
	printList(n1);

	ListNode* sorted = insertionSortList(n1);
	printList(sorted);

	return 0;

}