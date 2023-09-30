#pragma once
#include <string>
#include <fstream>
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
	bool deleteData(Day end);
	void deleteOneData(Day end, string name);
};