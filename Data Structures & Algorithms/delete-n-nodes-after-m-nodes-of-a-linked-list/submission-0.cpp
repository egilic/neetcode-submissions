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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while (cur) {
            int mCt = 0;
            int nCt = 0;

            while (cur && mCt++ < m) {
                prev = cur;
                cur = cur->next;
            }
            // *** 'cur' points to the element we need to remove
            // *** 'prev' holds the last valid element

            while (cur && nCt++ < n) {
                cur = cur->next;
            }
            // *** 'cur' now points to the next valid element
            prev->next = cur;
        }
        return head;
    }
};
