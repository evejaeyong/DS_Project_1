#include "MemberQueue.h"

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
    if(rear == 9) return 1;
    else return 0;
}
void MemberQueue::push(string name, int age, string date, char type) {
	if(full()) {
        std::cout << "Fuck you";
        exit;
    }
    else data[rear++].DataPush(name, age, date, type); 
}
MemberQueueNode MemberQueue::pop() {
    if(empty()) exit;
    return data[first++];
}
MemberQueueNode MemberQueue::front() {
    return data[first];
}