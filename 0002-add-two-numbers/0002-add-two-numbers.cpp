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
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;

        while (l1 || l2 || carry != 0) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            int v = v1 + v2 + carry;
            carry = v / 10;
            v = v % 10;

            cur->next = new ListNode(v);
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};