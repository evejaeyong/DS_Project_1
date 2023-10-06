#pragma once
#include <string>
using namespace std;

struct Day {
	int year;
	int month;
	int day;
};

class TermsBSTNode {
private:
	string name;
	int age;
	Day start;
	Day end;

	TermsBSTNode* left;
	TermsBSTNode* right;


public:
	TermsBSTNode() {}
	~TermsBSTNode() {}

	TermsBSTNode* getLeft() { return left; }
	TermsBSTNode* getRight() { return right; }

	void setLeft(TermsBSTNode* left) { this->left = left; }
	void setRight(TermsBSTNode* right) { this->right = right; }

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setAge(int age) {
		this->age = age;
	}

	void setDay(string date, char type) {
		start.year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
		start.month = (date[5] - '0') * 10 + (date[6] - '0');
		start.day = (date[8] - '0') * 10 + (date[9] - '0');

		if (type - 'A' == 0) {
			end.year = start.year;
			end.month = start.month + 6;
			end.day = start.day;

			if (end.month > 12) {
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

	int getAge() {
		return age;
	}

	Day getStart() {
		return start;
	}

	Day getEnd() {
		return end;
	}

	int compare(Day end) {
		if (this->end.year > end.year) return 1;
		else if (this->end.year < end.year) return -1;
		else if (this->end.month > end.month) return 1;
		else if (this->end.month < end.month) return -1;
		else if (this->end.day > end.day) return 1;
		else if (this->end.day < end.day) return -1;
		else return 0;
	}

	void setStart(Day start) {
		this->start = start;
		return;
	}

	void setEnd(Day end) {
		this->end = end;
		return;
	}
};
