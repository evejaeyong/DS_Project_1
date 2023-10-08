#include "TermsBST.h"
#include "TermsListNode.h"
#include <iostream>
using namespace std;

TermsBST::TermsBST() : root(nullptr) {

}
TermsBST::~TermsBST() {
	while (root) {			//Memory deallocation
		deleteOneData(root->getEnd(), root->getName());
	}
}

void TermsBST::setRoot(TermsBSTNode* root) {	//Setting Root function
	this->root = root;
}

void TermsBST::setList(TermsListNode* list) {	//Setting TermsListNode function
	this->list = list;
}

TermsBSTNode* TermsBST::getRoot() {		//return root function
	return root;
}

bool TermsBST::compare_date(TermsBSTNode* a, TermsBSTNode* b) {	//compare End date
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
void TermsBST::push(string name, int age, string date) {	//Data insert
	TermsBSTNode* newNode = new TermsBSTNode;		//node Memory allocation
	newNode->setAge(age);
	newNode->setDay(date, list->getType());
	newNode->setName(name);

	if (root == nullptr) {							//if data doesn't exist
		root = newNode;
		return;
	}

	TermsBSTNode* compare = root;					//get root
	while (1) {
		if (compare_date(compare, newNode)) {		//End date compare to see which way node is moving
			if (compare->getRight() == NULL) {		//Until the child node is NULL move inside the tree
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
	if (node == NULL) return;			//if node is empty

	printData(node->getLeft());			//inorder traverse, left->root->right
	flog.open("log.txt", ios::app);		//Open log file in overwrite format
	flog << node->getName() << "/" << node->getAge() << "/" << node->getStart().year << "-";
	if (node->getStart().month < 10) flog << 0;
	flog << node->getStart().month << "-";
	if (node->getStart().day < 10) flog << 0;
	flog << node->getStart().day << "/" << node->getEnd().year << "-";
	if (node->getEnd().month < 10) flog << 0;
	flog << node->getEnd().month << "-";
	if (node->getEnd().day < 10) flog << 0;
	flog << node->getEnd().day << "\n";
	flog.close();						//close log file
	printData(node->getRight());

	
	return;
}

// delete
bool TermsBST::deleteData(Day end, TermsBSTNode* node) {
	if (node == NULL) return false;
	if (node->compare(end) == -1) {
		deleteData(end, node->getLeft());		//postorder traverse, left->right->root
		deleteData(end, node->getRight());
		list->getNBST()->deleteOneData(node->getName());	//NameBST delete
		deleteOneData(node->getEnd(), node->getName());		//TermsBST delete
		
		return true;							//Check if deletion has progressed
	}
	else {
		deleteData(end, node->getLeft());
		return false;
	}

}

void TermsBST::deleteOneData(Day end, string name) {
	if (root == NULL) return;		//if data doesn't exist
	list->minus_num();
	TermsBSTNode* now = root;

	if (root->getName() == name) {	//if root == Data to be deleted
		int childnum = 0;
		if (root->getLeft() != NULL) childnum++;
		if (root->getRight() != NULL) childnum++;

		if (childnum == 0) {		//Number of child nodes 0
			delete now;
			root = NULL;
		}
		else if (childnum == 1) {	//Number of child nodes 1
			if (root->getLeft() != NULL) {
				root = now->getLeft();
			}
			else {
				root = now->getRight();
			}
			delete now;
		}
		else {						//Number of child nodes 2
			TermsBSTNode* prev = root;
			now = prev->getRight();
			bool flag = false;
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
				flag = true;
			}

			root->setName(now->getName());	//move data
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
			if (now == NULL) {					//if data doesn't exist
				list->plus_num();				//Restoring data because deletion has not progressed
				return;
			}
			if (now->getName() == name) break;	//find data
			
			if (now->compare(end) == 1) {		//Binary Search
				prev = now;
				now = now->getLeft();
				way = false;
			}
			else {
				prev = now;
				now = now->getRight();
				way = true;
			}
		}
		int childnum = 0;
		if (now->getLeft() != NULL) childnum++;
		if (now->getRight() != NULL) childnum++;

		if (childnum == 0) {				//Number of child nodes 0
			if (!way) prev->setLeft(NULL);
			else prev->setRight(NULL);
			delete now;
		}
		else if (childnum == 1) {			//Number of child nodes 1
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
		else {								//Number of child nodes 2
			TermsBSTNode* del = now;
			bool flag = false;
			prev = now;
			now = now->getRight();
			while (now->getLeft() != NULL) {
				prev = now;
				now = now->getLeft();
				flag = true;
			}

			del->setName(now->getName());	//move data
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