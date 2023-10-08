#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MemberQueue.h"
#include "TermsList.h"
#include "TermsBST.h"
#include "NameBST.h"

using namespace std;

class Manager {
private:
	MemberQueue* queue;		//Declare three data structures as member variables
	TermsLIST* list;
	NameBST* BST;

	ifstream fcmd;
	ofstream flog;

public:
	Manager();
	~Manager();

	void run(const char* command);

	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);

	// LOAD
	void LoadData();
	// ADD
	void AddData();
	// QPOP
	void PopData();
	// SEARCH
	void SearchData();
	// PRINT
	void PrintData();
	// DELETE
	void DeleteData();
};
