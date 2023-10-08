#include "NameBST.h"
#include "TermsList.h"
#include <iostream>
#include <fstream>
using namespace std;

NameBST::NameBST() : root(nullptr) {

}
NameBST::~NameBST() {
	while (root) {		//Memory deallocation
		deleteOneData(root->getName());
	}
}

NameBSTNode* NameBST::getRoot() {	//return root function
	return root;
}

void NameBST::setList(TermsLIST* list) {	//Set TermsList as Member Variables
	this->list = list;
}

// insert
void NameBST::insertData(MemberQueueNode add) {
	NameBSTNode* newNode = new NameBSTNode;		//node Memory allocation
	newNode->setName(add.getName());
	newNode->setAge(add.getAge());
	newNode->setType(add.getType());
	newNode->setDay(add.getDate());

	if (root == NULL) {		//if Tree doesn't have data
		root = newNode;
		return;
	}
	NameBSTNode* a = root;	//get root
	while (1) {
		if (a->getName().compare(newNode->getName()) < 0) {	//string compare to see which way node is moving
			if (a->getRight() == NULL) {	//Until the child node is NULL move inside the tree
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
	NameBSTNode* a = root;	//get root

	while (1) {
		if (a == NULL) break;
		if (name.compare(a->getName()) == 0) {	//if name is same
			return a;							//return node
		}
		else if (name.compare(a->getName()) < 0) {	//When it's low in alphabetical order
			a = a->getLeft();
		}
		else a = a->getRight();						//When it's high in alphabetical order

	}
	return NULL;									//When data is not found
}

// print

void NameBST::printData(NameBSTNode* node) {
	ofstream flog;
	if (node == NULL) return;						//if node is empty
	
	printData(node->getLeft());						//inorder traverse, left->root->right
	flog.open("log.txt", ios::app);					//Open log file in overwrite format
	flog << node->getName() << "/" << node->getAge() << "/" << node->getStart().year << "-";
	if (node->getStart().month < 10) flog << 0;
	flog << node->getStart().month << "-";
	if (node->getStart().day < 10) flog << 0;
	flog << node->getStart().day << "/" << node->getEnd().year << "-";
	if (node->getEnd().month < 10) flog << 0;
	flog << node->getEnd().month << "-";
	if (node->getEnd().day < 10) flog << 0;
	flog << node->getEnd().day << "\n";
	flog.close();									//close log file
	printData(node->getRight());
	
	return;
}

// delete
bool NameBST::deleteData(string name) {
	if (root == NULL) return 0;						//if data doesn't exist
	NameBSTNode* now = root;

	if (root->getName() == name) {					//if root == Data to be deleted
		int childnum = 0;
		if (root->getLeft() != NULL) childnum++;
		if (root->getRight() != NULL) childnum++;

		if (childnum == 0) {						//Number of child nodes 0
			this->list->DeleteOneData(now->getEnd(), now->getName());	//TermsLIST data delete
			delete now;
			root = NULL;
		}
		else if (childnum == 1) {					//Number of child nodes 1
			if (root->getLeft() != NULL) {
				root = now->getLeft();
			}
			else {
				root = now->getRight();
			}
			this->list->DeleteOneData(now->getEnd(), now->getName());	//TermsLIST data delete
			delete now;
		}
		else {										//Number of child nodes 2
			NameBSTNode* prev = root;
			now = prev->getRight();
			bool flag = false;
			while (now->getLeft() != NULL) {
				now = now->getLeft();
				prev = prev->getLeft();
				flag = true;
			}

			root->setName(now->getName());			//move data
			root->setAge(now->getAge());
			root->setType(now->getType());
			root->setStart(now->getStart());
			root->setEnd(now->getEnd());

			
			if (flag) prev->setLeft(now->getRight());
			else prev->setRight(now->getRight());
			
			this->list->DeleteOneData(now->getEnd(), now->getName());	//TermsLIST data delete
			delete now;
		}
	}
	else {
		NameBSTNode* prev = now;
		bool way = false;
		while (1) {
			if (now == NULL) return 0;				//if data doesn't exist
			if (now->getName() == name) break;		//find data
			if (now->getName().compare(name) < 0) {	//Binary Search
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

		if (childnum == 0) {						//Number of child nodes 0
			this->list->DeleteOneData(now->getEnd(), now->getName());	//TermsLIST data delete
			if (!way) prev->setLeft(NULL);
			else prev->setRight(NULL);
			delete now;
		}
		else if (childnum == 1) {					//Number of child nodes 1
			if (now->getLeft() != NULL) {
				if (way) prev->setRight(now->getLeft());
				else prev->setLeft(now->getLeft());
			}
			else {
				if (way) prev->setRight(now->getRight());
				else prev->setLeft(now->getRight());
			}
			this->list->DeleteOneData(now->getEnd(), now->getName());	//TermsLIST data delete
			delete now;
		}
		else {										//Number of child nodes 2
			NameBSTNode* del = now;
			this->list->DeleteOneData(now->getEnd(), now->getName());	//TermsLIST data delete
			bool flag = false;
			prev = now;
			now = now->getRight();
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
				flag = true;
			}

			del->setName(now->getName());		//move data
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
	if (root == NULL) return;				//if data doesn't exist
	NameBSTNode* now = root;

	if (root->getName() == name) {			//if root == Data to be deleted
		int childnum = 0;
		if (root->getLeft() != NULL) childnum++;
		if (root->getRight() != NULL) childnum++;

		if (childnum == 0) {				//Number of child nodes 0
			delete now;
			root = NULL;
		}
		else if (childnum == 1) {			//Number of child nodes 1
			if (root->getLeft() != NULL) {
				root = now->getLeft();
			}
			else {
				root = now->getRight();
			}
			delete now;
		}
		else {								//Number of child nodes 2
			NameBSTNode* prev = root;
			now = prev->getRight();
			bool flag = false;
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
				flag = true;
			}

			root->setName(now->getName());	//move data
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
			if (now == NULL) return;				//can't find data
			if (now->getName() == name) break;		//find data
			if (now->getName().compare(name) < 0) {	//binary search
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

		if (childnum == 0) {					//Number of child nodes 0
			if (!way) prev->setLeft(NULL);
			else prev->setRight(NULL);
			delete now;
		}
		else if (childnum == 1) {				//Number of child nodes 1
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
		else {									//Number of child nodes 2
			NameBSTNode* del = now;
			bool flag = false;
			prev = now;
			now = now->getRight();
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
				flag = true;
			}

			del->setName(now->getName());		//move data
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