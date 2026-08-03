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
        ListNode* curr = head;
        int len = 0;
        while (curr) {
            len++;
            curr = curr->next;
        }
        int removeIndex = len - n;
        if (removeIndex == 0) {
            return head->next;
        }

        curr = head;
        for (int i = 0; i < len; i++) {
            if (i + 1 == removeIndex) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }

        return head;
    }
};