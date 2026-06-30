/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> ogPointerToNew;
        Node* dummy = new Node(0);
        Node* tmp = head;

        // Find the size
        int size = 0;
        while (tmp)
        {
            tmp = tmp->next;
            size++;
        }

        // Create new linked list without random pointers for now
        Node* old = head;
        tmp = dummy;
        for (int i = 0; i < size; ++i)
        {

            tmp->next = new Node(old->val);
            tmp = tmp->next;
            ogPointerToNew[old] = tmp;
            old = old->next;
        }
        tmp->next = nullptr;

        // Loop through and set the random pointers
        tmp = dummy->next; 
        old = head;
        for (int i = 0; i < size; ++i)
        {
            if (old->random)
            {
                Node* newRandom = ogPointerToNew[old->random];
                tmp->random = newRandom;
            }
            else
            {
                tmp->random = nullptr;
            }

            // Increment pointers
            old = old->next;
            tmp = tmp->next;
        }
        return dummy->next;
    }
};
