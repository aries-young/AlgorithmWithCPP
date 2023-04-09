#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersect(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr || head2 == nullptr) return nullptr;

    ListNode* loop1 = detectCycle(head1);
    ListNode* loop2 = detectCycle(head2);
    // 都无环，采用无环相交方法
    if (loop1 == nullptr && loop2 == nullptr) return noLoop(head1, head2);

    // 仅有一个链表带环，不可能相交
    if ((loop1 == nullptr && loop2 != nullptr) || 
        (loop1 != nullptr && loop2 == nullptr)) return nullptr;

    // 都有环，采用有环相交方法
    if (loop1 != nullptr && loop2 != nullptr) return ;

}

// 环入口检测
ListNode* detectCycle(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* intersect = getIntersect(head);
    if (intersect == nullptr) return nullptr;
    ListNode* ptr1 = head;
    ListNode* ptr2 = intersect;
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}

// 获取环中的相遇点
ListNode* getIntersect(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return fast;
    }
    return nullptr;
}

// 相交链表
ListNode *noLoop(ListNode *headA, ListNode *headB) {
    ListNode* ha = headA;
    ListNode* hb = headB;
    while (ha != hb) {
        ha = ha == nullptr ? headB : ha->next;
        hb = hb == nullptr ? headA : hb->next;
    }
    return ha;
}

ListNode* bothLoop(ListNode* head1, ListNode* loop1, ListNode* head2, ListNode* loop2) {
    ListNode* cur1 = nullptr;
    ListNode* cur2 = nullptr;

    if (loop1 == loop2) { // 入环结点相同
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while (cur1 != loop1) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2) {
            n--;
            cur2 = cur2->next;
        }
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while (n != 0) {
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    else { // 入环结点不同
        cur1 = loop1->next;
        while (cur1 != loop1) {
            if (cur1 == loop2) return loop1;
            cur1 = cur1->next;
        }
        return nullptr;
    }
}

int main()
{
}
