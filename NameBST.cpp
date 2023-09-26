#include "NameBST.h"
#include <iostream>
using namespace std;

NameBST::NameBST() : root(nullptr) {

}
NameBST::~NameBST() {

}

NameBSTNode* NameBST::getRoot() {
	return root;
}

// insert
void NameBST::insertData(MemberQueueNode* add) {
	NameBSTNode* newNode = new NameBSTNode;
	newNode->setName(add->getName());
	newNode->setAge(add->getAge());
	newNode->setType(add->getType());
	newNode->setDay(add->getDate());

	if (root = NULL) {
		root = newNode;
		return;
	}
	NameBSTNode* a = root;
	while(1) {
		if (a->getName().compare(newNode->getName()) < 0) {
			if (a->getRight() == NULL) {
				a->setRight(newNode);
				break;
			}
			else a = a->getRight();
		}
		else {
			if(a->getLeft() == NULL) {
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

	while(1) {
		if (a == NULL) break;
		if (name.compare(a->getName()) == 0) {
			return a;
		}
		else if (name.compare(a->getName()) > 0) {
			a = a->getLeft();
		}
		else a = a->getRight();

	}
	return NULL;
}

// print
void NameBST::print() {
	if(root == NULL) {
		cout << "===== ERROR =====\n";
		cout << "500\n";
		cout << "==============\n";
	}

	else {
		cout << "===== PRINT =====\n";
		cout << "Name_BST\n";
		printData(root);
		cout << "==============\n";
	}
	return;
}

void NameBST::printData(NameBSTNode* node) {
	if (node == NULL) return;

	printData(node->getLeft());
	cout << node->getName() << "/" << node->getAge() << "/" << node->getStart().year << "-" << node->getStart().month << "-" << node->getStart().day << "/"
			<< node->getEnd().year << "-" << node->getEnd().month << "-" << node->getEnd().day << "\n";	//cout으로 하면 안됨, 파일로 옮길 방법 찾기
	printData(node->getRight());

	return;
}

// delete
bool NameBST::deleteData(string name) {
	if (root == NULL) return 0;
	NameBSTNode* now = root;

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
			NameBSTNode* prev = root->getRight();
			now = prev;
			while (now->getLeft() != NULL) {
				now = now->getLeft();
				prev = prev->getLeft();
			}

			root->setName(now->getName());
			root->setAge(now->getAge());
			root->setType(now->getType());
			root->setStart(now->getStart());
			root->setEnd(now->getEnd());

			if (now->getRight() != NULL) {
				prev->setLeft(now->getRight());
			}
			delete now;
		}
	}
	else {
		NameBSTNode* prev = now;
		bool way = false;
		while (now->getName() != name) {
			if (now == NULL) return 0;
			if(now->getName().compare(name) > 0) {
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
			NameBSTNode* del = now;

			now = now->getRight();
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
			}

			del->setName(now->getName());
			del->setAge(now->getAge());
			del->setType(now->getType());
			del->setStart(now->getStart());
			del->setEnd(now->getEnd());

			if (now->getRight() != NULL) {
				prev->setLeft(now->getRight());
			}
			delete now;
		}

	}
	return 1;
}