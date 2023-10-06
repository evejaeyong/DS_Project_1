#pragma once
#include "Manager.h"
#include "TermsListNode.h"
#include "MemberQueueNode.h"
using namespace std;

class NameBST;

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
	bool DeleteData(Day end);
	void DeleteOneData(Day end, string name);
};
