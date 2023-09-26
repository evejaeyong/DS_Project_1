#pragma once
#include "MemberQueue.h"

class TermsListNode {
private:
	char type;
	int member_num;
	TermsBST* BST;
	TermsListNode* next;

public:
	TermsListNode() {
		TermsBST* newNode = new TermsBST;
		BST = newNode;
	}
	~TermsListNode() {
		delete BST;
	}

	TermsListNode* getNext() { 
		return next;
	}

	TermsBST* getBST() {
		return BST;
	}

	void PushBST(string name, int age, string date) {
		BST->push(name, age, date);
	}

	void setNext(TermsListNode* next) { 
		this->next = next;
	}

	char getType() {
		return type;
	}

	void setType(char type) {
		this->type = type;
	}

	void plus_num() {
		member_num++;
	}

	void minus_num() {
		member_num--;
	}

	bool isEmpty(){
		if(member_num == 0) return 1;
		else return 0;
	}
	
};