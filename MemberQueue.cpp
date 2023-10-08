#include "MemberQueue.h"
#include <stdlib.h>

MemberQueue::MemberQueue() {   
    first = 0;  
    rear = 0;   //Initialize variables
}
MemberQueue::~MemberQueue() {
    //Empty because there are no variables to deallocate
}

bool MemberQueue::empty() {
    if (first == rear) return 1;    //if first & rear are the same, empty
    else return 0;
}
bool MemberQueue::full() {
    if (rear - first == 100) return 1;  //if rear - first == 100, full
    else return 0;
}
void MemberQueue::push(string name, int age, string date, char type) {
    if (full()) exit(-1);               //if full, program exit
    else data[rear++ % 100].DataPush(name, age, date, type);    //if not full, push data
}
MemberQueueNode MemberQueue::pop() {
    if (empty()) exit(-1);              //if empty, program exit
    else return data[first++ % 100];    //if not empty, pop data
}
MemberQueueNode MemberQueue::front() {
    return data[first % 100];           //return front data
}