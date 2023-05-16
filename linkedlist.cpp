//
// Created by zhangjiayuan on 23-4-25.
//

#include "linkedlist.h"

void linkedlist_test () {
    LinkedList l;
    l.addAtHead(2);
    l.addAtHead(1);
    l.addAtTail(3);
    l.addAtTail(4);
    l.addAtTail(5);
    l.removeNthBehind(2);
    int jj = 0;

    LinkedList l1;
    l1.addAtHead(1);
    l1.addAtTail(2);
    l1.addAtTail(3);
    l1.addAtTail(4);
    l1.addAtTail(5);
    l1.ans143(l1._head);
    int ll = 0;
}


