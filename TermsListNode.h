#pragma once
#include "MemberQueue.h"

class TermsListNode {
private:
	char type;
	int member_num;
	TermsBSTNode* BST_Parent;
	TermsListNode* next;

public:
	TermsListNode() {}
	~TermsListNode() {}

	TermsListNode* getNext() { 
		return next;
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