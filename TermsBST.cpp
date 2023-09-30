#include "TermsBST.h"
#include <iostream>
using namespace std;

TermsBST::TermsBST() : root(nullptr) {

}
TermsBST::~TermsBST() {

}

void TermsBST::setRoot(TermsBSTNode* root) {
	this->root = root;
}

void TermsBST::setList(TermsListNode* list) {
	this->list = list;
}

TermsBSTNode* TermsBST::getRoot() {
	return root;
}

bool TermsBST::compare_date(TermsBSTNode* a, TermsBSTNode* b) {
	Day a_day = a->getEnd();
	Day b_day = b->getEnd();
	
	if (a_day.year > b_day.year) return 0;
	else if (a_day.year < b_day.year) return 1;
	else if (a_day.month > b_day.month) return 0;
	else if (a_day.month < b_day.month) return 1;
	else if (a_day.day > b_day.day) return 0;
	else if (a_day.day < b_day.day) return 1;
	else return 0;
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
void TermsBST::printData(TermsBSTNode* node) {
	if (node == NULL) return;
	flog.open("log.txt", ios::app);

	printData(node->getLeft());
	flog << node->getName() << "/" << node->getAge() << "/" << node->getStart().year << "-" << node->getStart().month << "-" << node->getStart().day << "/"
			<< node->getEnd().year << "-" << node->getEnd().month << "-" << node->getEnd().day << "\n";
	printData(node->getRight());

	flog.close();
	return;
}

// delete
bool TermsBST::deleteData(Day end) {

}

void TermsBST::deleteOneData(Day end, string name) {
	if (root == NULL) return;
	TermsBSTNode* now = root;

	if (root->getName() == name) {
		int childnum = 0;
		if(root->getLeft() != NULL) childnum++;
		if(root->getRight() != NULL) childnum++;

		if(childnum == 0) {
			delete now;
			root = NULL;
		}
		else if (childnum == 1) {
			if (root->getLeft() != NULL) {
				root = now->getLeft();
			}
			else {
				root = now->getRight();
			}
			delete now;
		}
		else {
			TermsBSTNode* prev = root->getRight();
			now = prev;
			while (now->getLeft() != NULL) {
				now = now->getLeft();
				prev = prev->getLeft();
			}

			root->setName(now->getName());
			root->setAge(now->getAge());
			root->setStart(now->getStart());
			root->setEnd(now->getEnd());

			if (now->getRight() != NULL) {
				prev->setLeft(now->getRight());
			}
			delete now;
		}
	}
	else {
		TermsBSTNode* prev = now;
		bool way = false;
		while (now->getName() != name) {
			if (now == NULL) return;
			if (now->compare(end) == 1) {
				prev = now;
				now = now->getRight();
				way = true;
			}
			else {
				prev = now;
				now = now->getLeft();
				way = false;
			}
		}
		int childnum = 0;
		if (now->getLeft() != NULL) childnum++;
		if (now->getRight() != NULL) childnum++;

		if (childnum == 0) {
			delete now;
		}
		else if (childnum == 1) {
			if (now->getLeft() != NULL) {
				if (way) prev->setRight(now->getLeft());
				else prev->setLeft(now->getLeft());
			}
			else {
				if (way) prev->setRight(now->getRight());
				else prev->setLeft(now->getRight());
			}
			delete now;
		}
		else {
			TermsBSTNode* del = now;
			
			now = now->getRight();
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
			}

			del->setName(now->getName());
			del->setAge(now->getAge());
			del->setStart(now->getStart());
			del->setEnd(now->getEnd());

			if (now->getRight() != NULL) {
				prev->setLeft(now->getRight());
			}
			
			delete now;
		}

	}
}