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
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* newList = new ListNode(-1);
        ListNode* p3 = newList;
        int carry = 0;
        while (p1 && p2) {
            int a = p1->val;
            int b = p2->val;
            int newNum = (a+b+carry)%10;
            carry = (a+b+carry)/10;
            p3->next = new ListNode(newNum);
            p3 = p3->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            p3->next = new ListNode((p1->val+carry)%10);
            carry = (p1->val+carry)/10;
            p3 = p3->next;
            p1 = p1->next;
        }
        while (p2) {
            p3->next = new ListNode((p2->val+carry)%10);
            carry = (p2->val+carry)/10;
            p3 = p3->next;
            p2 = p2->next;
        }
        if (carry != 0) {
            p3->next = new ListNode(carry);
        }
        return newList->next;
    }
};
