#pragma once
#include <string>
#include "TermsListNode.h"
#include "NameBST.h"
#include "MemberQueue.h"
#include "TermsBST.h"
using namespace std;

class TermsLIST {
private:
	NameBST* BST;

	TermsListNode* head;
	TermsListNode* tail;

public:
	TermsLIST();
	~TermsLIST();

	TermsListNode* getHead();
	void setBST(NameBST* BST);
	
	// insert
	void insertData(MemberQueueNode push);
	// search
	TermsListNode* searchData(char type);
	// delete
	bool DeleteData(Day end, bool flag);
};
