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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // mid is SLOW pointer
        ListNode* otherHalf = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* t1 = head;
        ListNode* t2 = otherHalf;
        while (t1 && t2) {
            ListNode* t3 = t1->next;
            t1->next = t2;
            t1 = t3;
            ListNode* t4 = t2->next;
            t2->next = t3;
            t2 = t4;
        }
    }
};
