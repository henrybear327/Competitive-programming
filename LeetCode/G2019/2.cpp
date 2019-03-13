/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *tail = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int v1 = 0, v2 = 0;
            if (l1 != NULL) {
                v1 = l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                v2 = l2->val;
                l2 = l2->next;
            }

            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum %= 10;
            if (head == NULL) {
                head = tail = new ListNode(sum);
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
        }

        if (carry == 1)
            tail->next = new ListNode(carry), tail = tail->next;

        return head;
    }
};
