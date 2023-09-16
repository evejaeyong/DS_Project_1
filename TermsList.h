#pragma once
#include "TermsListNode.h"
#include "TermsBST.h"

class TermsLIST {
private:
	char type;
	int member_num;
	TermsBSTNode* root;
	
	TermsListNode* head;
	

public:
	TermsLIST();
	~TermsLIST();

	TermsListNode* getHead();

	// insert
	// search
	// delete
};
