#include "TermsList.h"

TermsLIST::TermsLIST(): head(nullptr) {
	BST = new TermsBST;
	BST->setList(this);
}
TermsLIST::~TermsLIST() {
	delete BST;
}

TermsListNode* TermsLIST::getHead() {
	return head;
}

char TermsLIST::getType() {
	return type;
}

// insert

// search

// delete