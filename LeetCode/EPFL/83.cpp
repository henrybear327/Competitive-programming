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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* prev = cur;
            cur = cur->next;
            while(cur != NULL) {
                if(cur->val == prev->val) {
                    prev->next = cur->next;
                    // free the node
                } else {
                    break;
                }
                cur = cur->next;
            }
        }

        return head;
    }
};
