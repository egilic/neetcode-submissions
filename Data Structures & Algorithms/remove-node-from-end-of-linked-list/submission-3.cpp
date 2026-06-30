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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Calculate size
        ListNode* tmp = head;
        int size = 0;
        while (tmp)
        {
            size++;
            tmp = tmp->next;
        }

        ListNode* prev = nullptr;
        tmp = head;
        int index = size - n; // 0-indexed 
        for (int i = 0; i < index + 1; ++i)
        {
            // Save the next element
            ListNode* next = tmp->next;

            if (i == index)
            {
                if (!prev)
                {
                    // If no prev just return next
                    return next;
                }
                // We are at the last element that must be removed
                prev->next = next;
                return head;
            }
            // Update previous
            prev = tmp;
            // Update tmp
            tmp = next;
        }

        return nullptr;
    }
};
