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
    void reorderList(ListNode* head) {
        // Use slow and fast pointer technique to fetch the middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // e.g.e    2 -> 4 -> 8 -> 10 -> null
        //                    *           *
        //  slow would be at 8

        // e.g.e    2 -> 4 -> 8 -> 10 -> 12 -> null
        //                    *           *
        //  slow would be at 8, again

        ListNode* cur = slow;
        ListNode* prev = nullptr;
        while (cur)
        {
            // Save next
            ListNode* next = cur->next;

            // Reverse next pointer
            cur->next = prev;

            // Update previous
            prev = cur;

            // Set cur to our saved next node
            cur = next;
        }

        // e.g.e 2 -> 4 -> 8 -> 10 -> null
        // e.g.e    2 -> 4 -> 8     null <- 8 <- 10


        // e.g.e    2 -> 4 -> 8 -> 10 -> 12 -> null
        //                    *           *
        //  slow would be at 8, again

    
        ListNode* l1 = head;
        ListNode* l2 = prev;
        
        cout << "Printing the contents of the left list (l1) \n";
        while (l1)
        {
            cout << " " << l1->val << " ";
            l1 = l1->next;
        }
        cout << "\n";

        cout << "Printing the contents of the right list (l2) \n";
        while (l2)
        {
            cout << " " << l2->val << " ";
            l2 = l2->next;
        }
        cout << "\n";

        l1 = head;
        l2 = prev;
        ListNode* back = nullptr;
        while (l1 && l2 && l1 != l2)
        {
            // Set the back's next pointer to whatever is in l1
            ListNode* oldRightNext;
            if (back)
            {
                oldRightNext = back->next;
                back->next = l1;
            }


            // Save left's old next node
            ListNode* oldLeftNext = l1->next;

            // Set left side to the right
            l1->next = l2;

            // Save back
            back = l2;

            // Increment right side by one
            l2 = l2->next;

            // Update l1
            l1 = oldLeftNext;

        }

    
    }
};

