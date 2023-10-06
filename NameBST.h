#pragma once
#include <fstream>
#include "NameBSTNode.h"
#include "MemberQueueNode.h"
class TermsLIST;


class NameBST {
private:
	TermsLIST* list;
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
	void deleteOneData(string name);
};