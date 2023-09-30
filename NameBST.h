#pragma once
#include "NameBSTNode.h"
#include "TermsList.h"
#include "MemberQueueNode.h"
#include <fstream>

class NameBST {
private:
	TermsLIST* list;
	ofstream flog;
	NameBSTNode* root;

public:
	NameBST();
	~NameBST();

	void setList(TermsLIST* list);
	NameBSTNode* getRoot();

	// insert
	void insertData(MemberQueueNode add);
	// search
	NameBSTNode* searchData(string name);
	// print
	void printData(NameBSTNode* node);
	// delete
	bool deleteData(string name);
};