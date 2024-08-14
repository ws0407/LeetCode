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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* back = dummy;
        ListNode* front = dummy;
        while (n--)
        {
            front = front->next;
        }
        while (front->next != nullptr)
        {
            front = front->next;
            back = back->next;
        }
        ListNode *tmp = back->next;
        back->next = back->next->next;
        delete tmp;
        tmp = nullptr;
        return dummy->next;
    }
};