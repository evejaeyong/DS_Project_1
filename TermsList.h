#pragma once
#include "TermsListNode.h"
#include "MemberQueue.h"
#include "TermsBST.h"

class TermsLIST {
private:
	TermsListNode* head;
	TermsListNode* tail;

public:
	TermsLIST();
	~TermsLIST();

	TermsListNode* getHead();
	
	// insert
	void insertData(MemberQueueNode push);
	// search
	TermsListNode* searchData(char type);
	// delete
};
