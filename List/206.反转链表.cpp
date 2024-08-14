/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /**
         * 时间复杂度: O(n)
         * 空间复杂度: O(1)
         */
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* next = cur->next;
        cur->next = pre;
        return reverse(cur, next);
    }

    ListNode* recursionReverseList(ListNode* head) {
        /**
         * 时间复杂度: O(n), 要递归处理链表的每个节点
         * 空间复杂度: O(n), 递归调用了 n 层栈空间
         */
        return reverse(nullptr, head);
    }

    ListNode* recursionReverseList(ListNode* head) {
        /**
         * 时间复杂度: O(n)
         * 空间复杂度: O(n)
         */
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* last = recursionReverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};