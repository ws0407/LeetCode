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

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;

        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode *del = cur->next;
                cur->next = cur->next->next;
                delete del;
            } else {
                cur = cur->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};