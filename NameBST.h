#pragma once
#include "NameBSTNode.h"
#include "MemberQueueNode.h"

class NameBST {
private:

	NameBSTNode* root;

public:
	NameBST();
	~NameBST();

	NameBSTNode* getRoot();

	// insert
	void insertData(MemberQueueNode* add);
	// search
	NameBSTNode* searchData(string name);
	// print
	void print();
	void printData(NameBSTNode* node);
	// delete
	bool deleteData(string name);
};