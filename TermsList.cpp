#include "TermsList.h"

TermsLIST::TermsLIST(): head(nullptr) {
}
TermsLIST::~TermsLIST() {
}

TermsListNode* TermsLIST::getHead() {
	return head;
}

void TermsLIST::setBST(NameBST* BST) {
	this->BST = BST;
}

// insert
void TermsLIST::insertData(MemberQueueNode add) {
	char temp = add.getType();
	if (head == NULL) {
		TermsListNode* newNode = new TermsListNode;
		newNode->setType(temp);
		newNode->plus_num();
		newNode->getBST()->push(add.getName(), add.getAge(), add.getDate());
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
				a->getBST()->push(add.getName(), add.getAge(), add.getDate());
				flag = true;
			}
		}

		if (!flag) {
			TermsListNode* newNode = new TermsListNode;
			newNode->setType(temp);
			newNode->plus_num();
			newNode->getBST()->push(add.getName(), add.getAge(), add.getDate());
			tail->setNext(newNode);
			tail = newNode;
		}
	}
}
// search

TermsListNode* TermsLIST::searchData(char type) {
	TermsListNode* a = head;
	while (1) {
		if (a == NULL) break;
		else if (a->getType() == type) {
			return a;
		}
		else {
			a = a->getNext();
		}
	}

	return NULL;
}

// delete
bool TermsLIST::DeleteData(Day end, bool flag) {
	//이거 플래그를 사용해도 문제점이 있음
	//end 시점이 똑같은 경우가 지워짐 어케해결할까?
	if (flag) {

	}

	else {
		
	}


}
