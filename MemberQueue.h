#pragma once
#include "MemberQueueNode.h"

class MemberQueue {
private:
	MemberQueueNode data[100];	//Declare the class to implement the queue as an array
	int first;
	int rear;

public:
	MemberQueue();
	~MemberQueue();

	bool empty();
	bool full();
	void push(string name, int age, string date, char type);
	MemberQueueNode pop();
	MemberQueueNode front();
};

