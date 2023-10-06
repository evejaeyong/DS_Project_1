#include "NameBST.h"
#include "TermsList.h"
#include <iostream>
#include <fstream>
using namespace std;

NameBST::NameBST() : root(nullptr) {

}
NameBST::~NameBST() {

}

NameBSTNode* NameBST::getRoot() {
	return root;
}

void NameBST::setList(TermsLIST* list) {
	this->list = list;
}

// insert
void NameBST::insertData(MemberQueueNode add) {
	NameBSTNode* newNode = new NameBSTNode;
	newNode->setName(add.getName());
	newNode->setAge(add.getAge());
	newNode->setType(add.getType());
	newNode->setDay(add.getDate());

	if (root == NULL) {
		root = newNode;
		return;
	}
	NameBSTNode* a = root;
	while (1) {
		if (a->getName().compare(newNode->getName()) < 0) {
			if (a->getRight() == NULL) {
				a->setRight(newNode);
				break;
			}
			else a = a->getRight();
		}
		else {
			if (a->getLeft() == NULL) {
				a->setLeft(newNode);
				break;
			}
			else a = a->getLeft();
		}
	}
}
// search
NameBSTNode* NameBST::searchData(string name) {
	NameBSTNode* a = root;

	while (1) {
		if (a == NULL) break;
		if (name.compare(a->getName()) == 0) {
			return a;
		}
		else if (name.compare(a->getName()) < 0) {
			a = a->getLeft();
		}
		else a = a->getRight();

	}
	return NULL;
}

// print

void NameBST::printData(NameBSTNode* node) {
	ofstream flog;
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
bool NameBST::deleteData(string name) {
	if (root == NULL) return 0;
	NameBSTNode* now = root;

	if (root->getName() == name) {
		int childnum = 0;
		if (root->getLeft() != NULL) childnum++;
		if (root->getRight() != NULL) childnum++;

		if (childnum == 0) {
			this->list->DeleteOneData(now->getEnd(), now->getName());
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
			this->list->DeleteOneData(now->getEnd(), now->getName());
			delete now;
		}
		else {
			NameBSTNode* prev = root->getRight();
			now = prev;
			bool flag = false;
			while (now->getLeft() != NULL) {
				now = now->getLeft();
				prev = prev->getLeft();
				flag = true;
			}

			root->setName(now->getName());
			root->setAge(now->getAge());
			root->setType(now->getType());
			root->setStart(now->getStart());
			root->setEnd(now->getEnd());

			
			if (flag) prev->setLeft(now->getRight());
			else prev->setRight(now->getRight());
			
			this->list->DeleteOneData(now->getEnd(), now->getName());
			delete now;
		}
	}
	else {
		NameBSTNode* prev = now;
		bool way = false;
		while (1) {
			if (now == NULL) return 0;
			if (now->getName() == name) break;
			if (now->getName().compare(name) < 0) {
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
			this->list->DeleteOneData(now->getEnd(), now->getName());
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
			this->list->DeleteOneData(now->getEnd(), now->getName());
			delete now;
		}
		else {
			NameBSTNode* del = now;
			this->list->DeleteOneData(now->getEnd(), now->getName());
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
			del->setType(now->getType());
			del->setStart(now->getStart());
			del->setEnd(now->getEnd());

			if (flag) prev->setLeft(now->getRight());
			else prev->setRight(now->getRight());
			
			delete now;
		}

	}
	return 1;
}

void NameBST::deleteOneData(string name) {
	if (root == NULL) return;
	NameBSTNode* now = root;

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
			NameBSTNode* prev = root->getRight();
			now = prev;
			bool flag = false;
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
				flag = true;
			}

			root->setName(now->getName());
			root->setAge(now->getAge());
			root->setType(now->getType());
			root->setStart(now->getStart());
			root->setEnd(now->getEnd());


			if (flag) prev->setLeft(now->getRight());
			else prev->setRight(now->getRight());

			delete now;
		}
	}
	else {
		NameBSTNode* prev = now;
		bool way = false;
		while (1) {
			if (now == NULL) return;
			if (now->getName() == name) break;
			if (now->getName().compare(name) < 0) {
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
			NameBSTNode* del = now;
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
			del->setType(now->getType());
			del->setStart(now->getStart());
			del->setEnd(now->getEnd());

			if (flag) prev->setLeft(now->getRight());
			else prev->setRight(now->getRight());

			delete now;
		}

	}
	return;
}