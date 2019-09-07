/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *tail = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            int v1 = l1 == NULL ? 0 : l1->val;
            int v2 = l2 == NULL ? 0 : l2->val;
            
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
            
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            if(tail == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        if(carry == 1)
            tail->next = new ListNode(1), tail = tail->next;
        
        return head;
    }
};
