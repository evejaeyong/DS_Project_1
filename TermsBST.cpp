#include "TermsBST.h"
using namespace std;

TermsBST::TermsBST() : root(nullptr) {

}
TermsBST::~TermsBST() {

}


TermsBSTNode* TermsBST::getRoot() {
	return root;
}


// insert
void TermsBST::push(string name, int age, string date) {
	TermsBSTNode* newNode = new TermsBSTNode;
	newNode->setAge(age);
	newNode->setDay(date);
	newNode->setName(name);

	if (root == nullptr) {
		
		
	}
}
// print

// delete