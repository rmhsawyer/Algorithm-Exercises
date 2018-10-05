#include "ListNode.h"

int main() {

	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(4);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(1);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;

	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(7);
	ListNode* n7 = new ListNode(6);
	ListNode* n8 = new ListNode(8);

	n5->next = n6;
	n6->next = n7;
	n7->next = n8;

	if (detectCycle(n1)) {
		cout << "The first linked list contains a cycle. ";
		cout << "The cycle starts at the node with value " << findCycleStart(n1)->val << endl;
	} else {
		cout << "The first linked list does not contain any cycle." << endl;
	}

	if (detectCycle(n5)) {
		cout << "The second linked list contains a cycle. ";
		// cout << "The cycle starts at the node with value " << findCycleStart(n5)->val << endl;
	} else {
		cout << "The second linked list does not contain any cycle." << endl;
	}

	return 0;

}
