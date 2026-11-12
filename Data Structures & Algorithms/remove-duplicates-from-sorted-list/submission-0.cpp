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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        unordered_set<int> vals;
        while (cur) {
            if (vals.contains(cur->val)) {
                ListNode* next = cur->next;
                prev->next = next;
                cur = next;
            } else {
                vals.insert(cur->val);
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
