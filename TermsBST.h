#pragma once
#include <string>
#include "TermsBSTNode.h"

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
	void push(std::string name, int age, std::string date);
	// print
	// delete
};