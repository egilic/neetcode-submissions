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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left >= right) { return head; } // no need to do anything

        // Let's save the left piece of the LL (before the ones being swapped; if applicable)
        ListNode* cur = head;
        ListNode* endOfLeft = nullptr;
        int count = 1;
        while (count < left) 
        { 
            endOfLeft = cur;
            cur = cur->next; 
            ++count;
        }

        // Fetch the right piece of the LL (after the ones being swapped; if applicable)
        count = 1;
        ListNode* startOfRight = head;
        while (count <= right)
        {
            startOfRight = startOfRight->next;
            ++count;
        }

        ListNode* prev = nullptr;
        ListNode* first = nullptr;
        while (cur && left <= right)
        {
            // save the first one to later use
            if (!prev) first = cur;

            // fetch next
            ListNode* next = cur->next;

            // set next node to the previous one
            cur->next = prev;

            // update prev and current
            prev = cur;
            cur = next;
            ++left;
        }

        if (endOfLeft) endOfLeft->next = prev;
        if (startOfRight && first) first->next = startOfRight;

        if (endOfLeft) return head;
        else return prev; 
    }
};