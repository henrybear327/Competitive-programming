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
        ListNode* prev = NULL, *orig = l1;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            if(l1 != NULL && l2 != NULL) {
                l1->val = carry + l1->val + l2->val;
                carry = l1->val / 10;
                l1->val %= 10;

                prev = l1;
                l1 = l1->next;
                l2 = l2->next;
            } else if(l1 != NULL) {
                if(carry == 0) {
                    // done
                    break;
                } else {
                    l1->val += carry;
                    carry = l1->val / 10;
                    l1->val %= 10;

                    prev = l1;
                    l1 = l1->next;
                }
            } else {
                // l2 != NULL
                prev->next = l2;
                if(carry == 0) {
                    // done
                    break;
                } else {
                    l2->val += carry;
                    carry = l2->val / 10;
                    l2->val %= 10;

                    prev = l2;
                    l2 = l2->next;
                }
            }
        }

        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }
        
        return orig;
    }
};
