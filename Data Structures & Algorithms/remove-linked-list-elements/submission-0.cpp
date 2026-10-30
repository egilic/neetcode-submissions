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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;

        while (cur && cur->val == val) {
            cur = cur->next;
        }

        if (!cur) { return nullptr; }

        // Now we now cur starts off at a value that is not a removed one
        ListNode* r = cur;

        ListNode* prev = cur;
        cur = cur->next;

        while (cur) {
            if (cur->val == val) {
                ListNode* next = cur->next;
                prev->next = next;
                cur = next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        return r;
    }
};