#pragma once
#include <fstream>
#include "TermsBSTNode.h"
using namespace std;

class TermsListNode;

class TermsBST {
private:
	ofstream flog;
	TermsListNode* list;
	TermsBSTNode* root;

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();
	void setRoot(TermsBSTNode* root);
	void setList(TermsListNode* list);
	bool compare_date(TermsBSTNode* a, TermsBSTNode* b);

	// insert
	void push(string name, int age, string date);
	// print
	void printData(TermsBSTNode* node);
	// delete
	bool deleteData(Day end, TermsBSTNode* node);	//Delete all nodes that date earlier than received
	void deleteOneData(Day end, string name);		//Delete Only One Data
};