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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *cur = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry > 0) {
            int num1 = l1 != NULL ? l1->val : 0;
            int num2 = l2 != NULL ? l2->val : 0;

            int num = num1 + num2 + carry;
            carry = num >= 10;
            num %= 10;

            if (head == NULL) {
                head = cur = new ListNode(num);
            } else {
                auto tmp = new ListNode(num);
                cur->next = tmp;
                cur = tmp;
            }

            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }

        return head;
    }
};
