#include "MemberQueue.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

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
    data[rear++ % 100].DataPush(name, age, date, type);     //push data
}
MemberQueueNode MemberQueue::pop() {
    return data[first++ % 100];                             //pop data
}
MemberQueueNode MemberQueue::front() {
    return data[first % 100];           //return front data
}