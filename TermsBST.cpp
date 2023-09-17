#include "TermsBST.h"
using namespace std;

TermsBST::TermsBST() : root(nullptr) {

}
TermsBST::~TermsBST() {

}

void TermsBST::setList(TermsListNode* list) {
	this->list = list;
}

TermsBSTNode* TermsBST::getRoot() {
	return root;
}

bool TermsBST::compare_date(TermsBSTNode* a, TermsBSTNode* b) {
	Day a_day = a->getEndDay();
	Day b_day = b->getEndDay();
	
	if (a_day.year > b_day.year) {
		return 0;
	}
	else if (a_day.year < b_day.year) {
		return 1;
	}
	else if (a_day.month > b_day.month) {
		return 0;
	}
	else if (a_day.month < b_day.month) {
		return 1;
	}
	else if (a_day.day > b_day.day) {
		return 0;
	}
	else if (a_day.day < b_day.day) {
		return 1;
	}
}

// insert
void TermsBST::push(string name, int age, string date) {
	TermsBSTNode* newNode = new TermsBSTNode;
	newNode->setAge(age);
	newNode->setDay(date, list->getType());
	newNode->setName(name);

	if (root == nullptr) {
		root = newNode;
		return;
	}

	TermsBSTNode* compare = root;
	while (1) {
		if (compare_date(compare, newNode)) {
			if (compare->getRight() == NULL) {
				compare->setRight(newNode);
				break;
			}
			else compare = compare->getRight();
		}
		else {
			if (compare->getLeft() == NULL) {
				compare->setLeft(newNode);
				break;
			}
			else compare = compare->getLeft();
		}
	}
}
// print

// delete