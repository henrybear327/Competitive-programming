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
private:
    void traverse(ListNode *prev, ListNode *cur, ListNode **head)
    {
        if (cur == NULL) {
            *head = prev;
            return;
        }
        traverse(cur, cur->next, head);
        cur->next = prev;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        traverse(NULL, head, &head);
        return head;
    }
};
