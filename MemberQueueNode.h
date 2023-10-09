#pragma once
#include <string>
using namespace std;

class MemberQueueNode {
private:
	string name;		//Member variable
	int age;
	string date;
	char type;

public:
	MemberQueueNode() {}
	~MemberQueueNode() {}

	void DataPush(string name, int age, string date, char type) {	//Push Data
		this->name = name;
		this->age = age;
		this->date = date;
		this->type = type;
	}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	string getDate() {
		return date;
	}

	char getType() {
		return type;
	}

};