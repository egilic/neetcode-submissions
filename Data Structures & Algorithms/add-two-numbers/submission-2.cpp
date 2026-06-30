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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* dummyRet = dummy;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            if (sum > 9)
            {
                cout << "Greater: sum is " << sum << endl;
                dummy->next = new ListNode(sum % 10);
                dummy = dummy->next;
                carry = 1;
            }
            else
            {
                cout << "Less: sum is " << sum << endl;
                dummy->next = new ListNode(sum);
                dummy = dummy->next;
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            int sum = l1->val + carry;
            dummy->next = new ListNode(sum % 10);
            dummy = dummy->next;
            if (sum > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            l1 = l1->next;
        }
        while (l2)
        {
            int sum = l2->val + carry;
            dummy->next = new ListNode(sum % 10);
            dummy = dummy->next;
            if (sum > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            l2 = l2->next;
        }
        if (carry != 0)
        {
            dummy->next = new ListNode(carry);
        }

        return dummyRet->next;
    }
};
