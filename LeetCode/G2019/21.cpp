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
    ListNode *connect(ListNode *&root, ListNode *&cur, ListNode *newNode)
    {
        if (root == NULL)
            root = cur = newNode;
        else
            cur->next = newNode;

        cur = newNode;
        ListNode *l = newNode->next;
        newNode->next = NULL;

        return l;
    }

public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = NULL, *cur = ans;

        auto i = l1, j = l2;
        while (i != NULL && j != NULL) {
            if (i->val < j->val)
                i = connect(ans, cur, i);
            else
                j = connect(ans, cur, j);
        }

        while (i != NULL)
            i = connect(ans, cur, i);
        while (j != NULL)
            j = connect(ans, cur, j);

        return ans;
    }
};