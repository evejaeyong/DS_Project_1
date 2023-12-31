#pragma once
#include <string>
#include "TermsBSTNode.h"
using namespace std;

class NameBSTNode {
private:
	string name;
	int age;
	Day start;
	Day end;
	char type;

	NameBSTNode* left;
	NameBSTNode* right;

public:
	NameBSTNode() {
		left = NULL;
		right = NULL;
	}
	~NameBSTNode() {}

	NameBSTNode* getLeft() { return left; }
	NameBSTNode* getRight() { return right; }

	void setLeft(NameBSTNode* left) { this->left = left; }
	void setRight(NameBSTNode* right) { this->right = right; }

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return age;
	}

	void setType(char type) {
		this->type = type;
	}

	void setDay(string date) {
		start.year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
		start.month = (date[5] - '0') * 10 + (date[6] - '0');
		start.day = (date[8] - '0') * 10 + (date[9] - '0');		//String to int, Parsing year, month, day

		if (type - 'A' == 0) {		//Check the type and set End Date
			end.year = start.year;
			end.month = start.month + 6;
			end.day = start.day;

			if (end.month > 12) {	//Raise the year when it's pass December
				end.year++;
				end.month -= 12;
			}
		}
		else if (type - 'A' == 1) {
			end.year = start.year + 1;
			end.month = start.month;
			end.day = start.day;
		}
		else if (type - 'A' == 2) {
			end.year = start.year + 2;
			end.month = start.month;
			end.day = start.day;
		}
		else if (type - 'A' == 3) {
			end.year = start.year + 3;
			end.month = start.month;
			end.day = start.day;
		}
	}

	Day getStart() {
		return start;
	}

	Day getEnd() {
		return end;
	}

	char getType() {
		return type;
	}

	void setStart(Day start) {
		this->start = start;
	}

	void setEnd(Day end) {
		this->end = end;
	}
};