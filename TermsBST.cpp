#include "TermsBST.h"
#include "TermsListNode.h"
#include <iostream>
using namespace std;

TermsBST::TermsBST() : root(nullptr) {

}
TermsBST::~TermsBST() {
	while (root) {
		deleteOneData(root->getEnd(), root->getName());
	}
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
	

	printData(node->getLeft());
	flog.open("log.txt", ios::app);
	flog << node->getName() << "/" << node->getAge() << "/" << node->getStart().year << "-";
	if (node->getStart().month < 10) flog << 0;
	flog << node->getStart().month << "-";
	if (node->getStart().day < 10) flog << 0;
	flog << node->getStart().day << "/" << node->getEnd().year << "-";
	if (node->getEnd().month < 10) flog << 0;
	flog << node->getEnd().month << "-";
	if (node->getEnd().day < 10) flog << 0;
	flog << node->getEnd().day << "\n";
	flog.close();
	printData(node->getRight());

	
	return;
}

// delete
bool TermsBST::deleteData(Day end, TermsBSTNode* node) {
	if (node == NULL) return false;
	if (node->compare(end) == -1) {
		if (node == root) root = node->getRight();
		deleteData(end, node->getLeft());
		deleteData(end, node->getRight());
		list->getNBST()->deleteOneData(node->getName());
		deleteOneData(end, node->getName());
		
		return true;
	}
	else {
		deleteData(end, node->getLeft());
		return false;
	}

}

void TermsBST::deleteOneData(Day end, string name) {
	if (root == NULL) return;
	list->minus_num();
	TermsBSTNode* now = root;

	if (root->getName() == name) {
		int childnum = 0;
		if (root->getLeft() != NULL) childnum++;
		if (root->getRight() != NULL) childnum++;

		if (childnum == 0) {
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
			TermsBSTNode* prev = root;
			now = prev->getRight();
			bool flag = false;
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
				flag = true;
			}

			root->setName(now->getName());
			root->setAge(now->getAge());
			root->setStart(now->getStart());
			root->setEnd(now->getEnd());

			if (flag) prev->setLeft(now->getRight());
			else prev->setRight(now->getRight());
			
			delete now;
		}
	}
	else {
		TermsBSTNode* prev = now;
		bool way = false;
		while (1) {
			if (now == NULL) {
				list->plus_num();
				return;
			}
			if (now->getName() == name) break;
			
			if (now->compare(end) == -1) {
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
			if (!way) prev->setLeft(NULL);
			else prev->setRight(NULL);
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
			bool flag = false;
			prev = now;
			now = now->getRight();
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
				flag = true;
			}

			del->setName(now->getName());
			del->setAge(now->getAge());
			del->setStart(now->getStart());
			del->setEnd(now->getEnd());

			if (flag) prev->setLeft(now->getRight());
			else prev->setRight(now->getRight());

			delete now;
		}
	}
	return;
}