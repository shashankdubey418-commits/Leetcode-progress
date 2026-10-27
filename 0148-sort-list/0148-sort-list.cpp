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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        // Merge the sorted halves
        return merge(left, right);
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }

            temp = temp->next;
        }

        if (a != nullptr)
            temp->next = a;
        else
            temp->next = b;

        return dummy.next;
    }
};