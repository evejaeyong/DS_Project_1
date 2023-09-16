#pragma once
#include <string>
#include "TermsBSTNode.h"
using namespace std;

struct Day{
	int year;
	int month;
	int day;
};

class TermsBST {
private:
	TermsBSTNode* root;

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();

	// insert
	void push(string name, int age, string date, char type);
	// print
	// delete
};