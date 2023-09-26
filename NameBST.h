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
	// print
	// delete
};