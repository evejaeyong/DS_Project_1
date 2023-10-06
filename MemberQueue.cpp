#include "MemberQueue.h"
#include <stdlib.h>

MemberQueue::MemberQueue() {
    first = 0;
    rear = 0;
}
MemberQueue::~MemberQueue() {

}

bool MemberQueue::empty() {
    if (first == rear) return 1;
    else return 0;
}
bool MemberQueue::full() {
    if (rear - first == 100) return 1;
    else return 0;
}
void MemberQueue::push(string name, int age, string date, char type) {
    if (full()) exit(-1);
    else data[rear++ % 100].DataPush(name, age, date, type);
}
MemberQueueNode MemberQueue::pop() {
    if (empty()) exit(-1);  
    else return data[first++ % 100];
}
MemberQueueNode MemberQueue::front() {
    return data[first % 100];
}