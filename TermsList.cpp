#include "TermsList.h"

TermsLIST::TermsLIST(): head(nullptr) {
}
TermsLIST::~TermsLIST() {
}

TermsListNode* TermsLIST::getHead() {
	return head;
}

// insert
void TermsLIST::insertData(MemberQueueNode* add) {
	char temp = add->getType();
	if (head == NULL) {
		TermsListNode* newNode = new TermsListNode;
		newNode->setType(temp);
		newNode->plus_num();
		newNode->getBST()->push(add->getName(), add->getAge(), add->getDate());
		head = newNode;
		tail = newNode;
		return;
	}
	else {
		TermsListNode* a = head;
		bool flag = false;
		while (a != NULL) {
			if (a->getType() == temp) {
				a->plus_num();
				a->getBST()->push(add->getName(), add->getAge(), add->getDate());
				flag = true;
			}
		}

		if (!flag) {
			TermsListNode* newNode = new TermsListNode;
			newNode->setType(temp);
			newNode->plus_num();
			newNode->getBST()->push(add->getName(), add->getAge(), add->getDate());
			tail->setNext(newNode);
			tail = newNode;
		}
	}
	

}


// search

TermsListNode* TermsLIST::searchData(string name) {
	
}
// delete