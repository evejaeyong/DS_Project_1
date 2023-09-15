#include "MemberQueue.h"
#include <stdlib.h>

MemberQueue::MemberQueue() {
    first = 0;
    rear = 0;
}
MemberQueue::~MemberQueue() {
	
}

bool MemberQueue::empty() {
    if(first == rear) return 1;
    else return 0;
}
bool MemberQueue::full() {
    if(rear - first == 99) return 1;
    else return 0;
}
void MemberQueue::push(string name, int age, string date, char type) {
	if(full()) exit;    //풀인경우 나중에 예외처리 해야 할 듯
    else data[rear % 100].DataPush(name, age, date, type);
    rear++;
}
MemberQueueNode MemberQueue::pop() {
    if(empty()) exit;   //엠티인경우 나중에 예외처리 해야 할 듯
    return data[first++];
}
MemberQueueNode MemberQueue::front() {
    return data[first];
}