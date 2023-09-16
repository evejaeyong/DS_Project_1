#pragma once
#include "TermsListNode.h"
#include "TermsBST.h"

class TermsLIST {
private:
	char type;
	int member_num;
	TermsBST* BST;
	
	TermsListNode* head;
	

public:
	TermsLIST();
	~TermsLIST();

	TermsListNode* getHead();
	char getType();
	
	// insert
	
	// search
	// delete
};
