#include "TermsList.h"

TermsLIST::TermsLIST() : head(NULL) {
}

TermsLIST::~TermsLIST() {
	TermsListNode* a = head;
	while (a) {					//Memory deallocation
		TermsListNode* b = a;
		a = a->getNext();
		delete b;
	}
}

TermsListNode* TermsLIST::getHead() {	//return head function
	return head;
}

void TermsLIST::setBST(NameBST* BST) {	//Setting BST function
	this->BST = BST;
}

// insert
void TermsLIST::insertData(MemberQueueNode add) {
	char temp = add.getType();
	if (head == NULL) {								//if TermsListNode doesn't exist
		TermsListNode* newNode = new TermsListNode;	//Memory allocation
		newNode->setType(temp);
		newNode->plus_num();						//member_num + 1
		newNode->setNBST(this->BST);
		newNode->getBST()->setList(newNode);
		newNode->getBST()->push(add.getName(), add.getAge(), add.getDate());	//BST insert
		head = newNode;
		tail = newNode;
		return;
	}
	else {
		TermsListNode* a = head;
		bool flag = false;
		while (a != NULL) {
			if (a->getType() == temp) {					//if TermsListNode exist
				a->plus_num();
				a->getBST()->push(add.getName(), add.getAge(), add.getDate());	//BST insert
				flag = true;
				break;
			}
			a = a->getNext();
		}
		
		if (!flag) {									//if TermsListNode doesn't exist
			TermsListNode* newNode = new TermsListNode;	//Memory allocation
			newNode->setType(temp);
			newNode->plus_num();						//member_num + 1
			newNode->getBST()->setList(newNode);
			newNode->setNBST(this->BST);
			newNode->getBST()->push(add.getName(), add.getAge(), add.getDate());	//BST insert
			tail->setNext(newNode);
			tail = newNode;
		}
	}
}
// search

TermsListNode* TermsLIST::searchData(char type) {
	TermsListNode* a = head;
	while (1) {
		if (a == NULL) break;				//Data doesn't exist
		else if (a->getType() == type) {	//If the type matches
			return a;
		}
		else {
			a = a->getNext();				//Search Next Node
		}
	}

	return NULL;
}

// delete
bool TermsLIST::DeleteData(Day end) {
	TermsListNode* list = head;
	bool check, res = false;
	while (list != NULL) {
		TermsBST* BST = list->getBST();		//Get TermsBST
		check = BST->deleteData(end, list->getBST()->getRoot());	//Delete Node
		if (check) {						//if delete success
			res = true;
			if (list->isEmpty()) {			//if TermsListNode member_num == 0
				if (list == head) {
					head = list->getNext();
					delete list;
					break;
				}
				else {
					TermsListNode* prev = head;
					TermsListNode* del = list;
					while (prev->getNext() != list) {
						prev = prev->getNext();
					}
					prev->setNext(list->getNext());

					if (list == tail) prev = tail;
					delete del;					//Memory Deallocation
					list = prev;
				}
				
			}
		}
		list = list->getNext();				//Next Node Search
		
	}
	return res;
}

void TermsLIST::DeleteOneData(Day end, string name) {
	TermsListNode* list = head;
	while (list != NULL) {
		TermsBST* BST = list->getBST();		//Get TermsBST
		BST->deleteOneData(end, name);		//Delete data
		if (list->isEmpty()) {				//if TermsListNode member_num == 0
			if (list == head) {
					head = list->getNext();
					delete list;
					break;
				}
			else {
				TermsListNode* prev = head;
				TermsListNode* del = list;
				while (prev->getNext() != list) {
					prev = prev->getNext();
				}
				prev->setNext(list->getNext());

				if (list == tail) prev = tail;
				delete del;					//Memory Deallocation
				list = prev;
			}
		}
		list = list->getNext();				//Search Next Node
	}
	return;
}