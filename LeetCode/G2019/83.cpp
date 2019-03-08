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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *h = head;
        while (head != NULL && head->next != NULL) {
            if (head->val == head->next->val) {
                ListNode *nxt = head->next;
                head->next = head->next->next;
                delete nxt;
            } else {
                head = head->next;
            }
        }
        return h;
    }
};
