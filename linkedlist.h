//
// Created by zhangjiayuan on 23-4-25.
//

#ifndef BOOSTGEOMETRY_LINKEDLIST_H
#define BOOSTGEOMETRY_LINKEDLIST_H
#include "Util.h"

void linkedlist_test();

struct LinkedNode {
    LinkedNode* next;
    double val;
};

class LinkedList {
public:
    // dummy 1 2 3 4 5
    LinkedNode* removeNthBehind(int n) {
        auto dummyHead = new LinkedNode();
        dummyHead->next = _head;
        auto slow = dummyHead;
        auto fast = dummyHead;
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }

    // cur -> 1 -> 2 -> 3 -> 4
    LinkedNode* exchange() {
        auto dummyHead = new LinkedNode();
        dummyHead->next = _head;
        auto cur = dummyHead;
        while (cur != nullptr && cur->next != nullptr) {
            auto tmp = cur->next;
            auto tmp2 = cur->next->next;

            cur->next = tmp2;
            tmp->next = tmp2->next;
            tmp2->next = tmp;
            cur = cur->next->next;
        }
        return dummyHead->next;
    }

    LinkedNode* detectCycle(LinkedNode* head) {
        if (head == nullptr) return nullptr;
        LinkedNode* fast = head;
        LinkedNode* slow = head;
        while (fast != nullptr || fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                LinkedNode* index1 = fast;
                LinkedNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }

    void removeVal(int val) {
        if (_head == nullptr) return;
        while (_head != nullptr && _head->val == val) {
            auto tmp = _head;
            _head = _head->next;
            delete(tmp);
        }

        auto tmp = _head->next;
        auto prev = _head;
        while (tmp != nullptr) {
            if (tmp->val == val) {
                auto tmp2 = tmp;
                prev->next = tmp->next;
                tmp = tmp->next;
                delete tmp2;
            } else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
    }

    void addAtHead(int val) {
        if (_head == nullptr) {
            _head = new LinkedNode();
            _head->val = val;
            _head->next = nullptr;
            ++_count;
            return;
        }

        auto tmp = new LinkedNode();
        tmp->next = _head;
        tmp->val = val;
        _head = tmp;
        ++_count;
    }

    void addAtTail(int val) {
        if (_head == nullptr) {
            _head = new LinkedNode();
            _head->val = val;
            _head->next = nullptr;
            ++_count;
            return;
        }

        auto tmp = new LinkedNode();
        tmp->val = val;
        tmp->next = nullptr;
        auto itr = _head;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = tmp;
        ++_count;
    }

    void addAtIndex(int index) {
        auto tmp = _head;
    }

    void deleteAtIndex(int index);

    LinkedNode* get(int index) {
        if (_head == nullptr) return nullptr;
        if (index >= _count) return nullptr;
        auto tmp = _head;
        while (index != 0) {
            tmp = tmp->next;
            --index;
        }
        return tmp;
    }

    void Reverse() {
        if (_head->next == nullptr) return;
        LinkedNode* tmp = nullptr;
        LinkedNode* tmp_next = _head;
        while (tmp_next != nullptr) {
            auto tmp_save = tmp_next->next;
            tmp_next->next = tmp;
            tmp = tmp_next;
            tmp_next = tmp_save;
        }
        _head = tmp;
    }

    /// lc 92
    // Input: head = [1,2,3,4,5], left = 2, right = 4
    // Output: [1,4,3,2,5]
    LinkedNode* Reverse2(int left, int right) {
        auto dummyHead = new LinkedNode();
        dummyHead->next = _head;
        auto tmpVal = left;

        auto tmp = _head;
        auto prev = dummyHead;
        while (tmpVal != 1) {
            tmp = tmp->next;
            prev = prev->next;
            --tmpVal;
        }

        prev->next = nullptr;

        LinkedNode* tmp_next = tmp->next;
        for (int i = 0; i < right - left; ++i) {
            auto tmp_save = tmp_next->next;
            tmp_next->next = tmp;
            tmp = tmp_next;
            tmp_next = tmp_save;
        }

        prev->next = tmp;
        for (int i = 0; i < right - left; ++i) {
            tmp = tmp->next;
        }

        tmp->next = tmp_next;
        return dummyHead->next;
    }

    /// lc 86
    //  Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    //  You should preserve the original relative order of the nodes in each of the two partitions.
    //  Input: head = [1,4,3,2,5,2], x = 3
    //  Output: [1,2,2,4,3,5]
    LinkedNode* partition(LinkedNode* head, int x) {
        LinkedNode* slow = new LinkedNode();
        LinkedNode* fast = new LinkedNode();
        LinkedNode* slowDummy = slow;
        LinkedNode* fastDummy = fast;
        auto tmp = head;
        while (tmp != nullptr) {
            if (tmp->val < x) {
                slow->next = tmp;
                slow = slow->next;
            } else {
                fast->next = tmp;
                fast = fast->next;
            }
            tmp = tmp->next;
        }
        slow->next = fastDummy->next;
        fast->next = nullptr;
        return slowDummy->next;
    }

    /// 234
    // 234.回文链表
    //请判断一个链表是否为回文链表。
    //
    //示例 1:
    //
    //    输入: 1->2
    //    输出: false
    //
    //示例 2:
    //
    //    输入: 1->2->2->1
    //    输出: true
    //
    bool ans234(LinkedNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        auto slow = head;
        auto fast = head;
        auto pre = head;
        auto dummy = head;
        while (fast != nullptr) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        pre->next = nullptr;

        LinkedNode* tmp_next = slow->next;
        while (tmp_next != nullptr) {
            auto tmp_save = tmp_next->next;
            tmp_next->next = slow;
            slow = tmp_next;
            tmp_next = tmp_save;
        }

        while (dummy != nullptr && slow != nullptr) {
            if (dummy->val != slow->val) {
                return false;
            }
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }

    /// 143
    // L0->L1->...->Ln
    // L0->Ln->L1->Ln-1...
    // 1->2->3->4
    void ans143(LinkedNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        auto slow = head;
        auto fast = head;
        auto pre = head;

        while (fast != nullptr) {
            if (fast->next == nullptr) {
                fast = fast->next;
            } else {
                fast = fast->next->next;
            }
            pre = slow;
            slow = slow->next;
        }

        pre->next = nullptr;

        LinkedNode* prev = nullptr;
        while (slow != nullptr) {
            auto next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        auto tmp = head;
        while (prev != nullptr) {
            auto l1_next = tmp->next;
            auto l2_next = prev->next;
            tmp->next = prev;
            prev->next = l1_next;
            tmp = l1_next;
            prev = l2_next;
        }
    }

    // 148
    // Input: head = [4,2,1,3]
    // Output: [1,2,3,4]
    void sortList(LinkedNode* head) {

    }

    // 25
    //  Input: head = [1,2,3,4,5], k = 2
    //  Output: [2,1,4,3,5]

    //  Input: head = [1,2,3,4,5], k = 3
    //  Output: [3,2,1,4,5]

    //  Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
    //  k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
    //  You may not alter the values in the list's nodes, only nodes themselves may be changed.

    LinkedNode* ReverseTmp(LinkedNode* head, int k) {
        LinkedNode* prev = nullptr;
        LinkedNode* tmp = head;
        LinkedNode* next;
        int count = 0;
        while (tmp != nullptr) {
            next = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = next;
            ++count;
            if (count == k) {
                break;
            }
        }
        return next;
    }

    void reverseNodesinK(LinkedNode* head, int k) {
        auto length = 0;
        auto tmp = head;
        LinkedNode* dummyHead;
        while (tmp != nullptr) {
            if (length == (k - 1)) dummyHead = tmp;
            tmp = tmp->next;
            length++;
        }

        tmp = head;
        while (length >= k) {
            auto next = ReverseTmp(tmp, k);
            length -= k;
            if (length >= k) {
                int j = 1;
                auto tmp2 = next;
                while (j != k) {
                    tmp2 = tmp2->next;
                    ++j;
                }
                tmp->next = tmp2;
                tmp = next;
            } else {
                tmp->next = next;
            }
        }
        int jj = 0;
    }

    // swapNodes in pair
    // 24
    // Input: head = [1,2,3,4]
    // Output: [2,1,4,3]
    LinkedNode* swapNodePair(LinkedNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        LinkedNode* dummyHead = new LinkedNode();
        dummyHead->next = head;
        LinkedNode* prev = dummyHead;
        LinkedNode* curNode = head;

        while (curNode != nullptr && curNode->next != nullptr) {
            prev->next = curNode->next;
            auto tmp = curNode->next->next;
            curNode->next->next = curNode;
            curNode->next = tmp;
            prev = curNode;
            curNode = tmp;
        }

        return dummyHead->next;
    }

    // Rotate List
    // 61
    // Input: head = [1,2,3,4,5], k = 2
    // Output: [4,5,1,2,3]

    LinkedNode* rotateRight(LinkedNode* head, int k) {
        if (head == nullptr) return nullptr;
        int length = 0;
        auto tmp = head;
        while (tmp != nullptr) {
            tmp = tmp->next;
            ++length;
        }

        while (k >= length) {
            k -= length;
        }

        if (k == 0) return head;

        LinkedNode* dummyHead = new LinkedNode();
        dummyHead->next = head;
        auto slow = dummyHead;
        auto fast = dummyHead;
        for (int i = 0; i <= k; ++i) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        delete dummyHead;

        auto curNode = slow->next;
        auto prevStart = head;
        slow->next = nullptr;
        head = curNode;
        while (curNode->next != nullptr) {
            curNode = curNode->next;
        }
        curNode->next = prevStart;
        return head;
    }

//private:
    LinkedNode* _head = nullptr;
    size_t _count = 0;
};

#endif //BOOSTGEOMETRY_LINKEDLIST_H
