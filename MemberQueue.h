#pragma once
#include "MemberQueueNode.h"

class MemberQueue {
private:
	MemberQueueNode data[100];
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
