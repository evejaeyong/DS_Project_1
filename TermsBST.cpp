#include "TermsBST.h"
using namespace std;

TermsBST::TermsBST() : root(nullptr) {

}
TermsBST::~TermsBST() {

}

void TermsBST::setList(TermsLIST* list) {
	this->list = list;
}

TermsBSTNode* TermsBST::getRoot() {
	return root;
}

bool TermsBST::compare_date(TermsBSTNode* a, TermsBSTNode* b) {
	//b가 더 크면 1 이여야 함
	Day a_day = a->getEndDay();
	Day b_day = b->getEndDay();
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