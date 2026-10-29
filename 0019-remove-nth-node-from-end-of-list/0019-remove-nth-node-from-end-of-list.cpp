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
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the last node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the nth node from the end
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return dummy.next;
    }
};