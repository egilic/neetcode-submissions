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
    bool isPalindrome(ListNode* head) {
        stack<int> q;
        ListNode* it = head;
        while (it != nullptr) {
            q.push(it->val);
            it = it->next;
        }

        while (head && !q.empty()) {
            auto node = q.top(); q.pop();

            if (node != head->val) {
                cout << "case 1\n";
                return false;
            } 
            head = head->next;
        }

        if (!q.empty()) {
            cout << "case 2\n";
            return false;
        }

        if (head) {
            cout << "the value is " << head->val << " \n";
            cout << "case 3\n";
            return false;
        }

        return true;
    }
};