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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return NULL;

        if (head->val == val) {
            ListNode *nxt = head->next;
            delete head;
            return removeElements(nxt, val);
        } else {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};
