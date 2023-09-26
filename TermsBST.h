#pragma once
#include <string>
#include "TermsBSTNode.h"
#include "TermsList.h"
using namespace std;

struct Day{
	int year;
	int month;
	int day;
};

class TermsBST {
private:
	TermsListNode* list;
	TermsBSTNode* root;

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();
	void setList(TermsListNode* list);
	bool compare_date(TermsBSTNode* a, TermsBSTNode* b);

	// insert
	void push(string name, int age, string date);
	// print
	// delete
};