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
    bool isPalindrome(ListNode *head)
    {
        int sz = 0;
        ListNode *root = head;
        while (head != NULL)
            sz++, head = head->next;

        if (sz <= 0)
            return true;

        // find spilt point
        head = root;
        ListNode *mid = root;
        bool isOdd = sz % 2;
        sz /= 2;
        while (sz--)
            mid = mid->next;

        // reverse
        ListNode *prev = NULL;
        while (head) {
            ListNode *nxt = head->next;
            head->next = prev;
            prev = head;
            if (nxt == mid)
                break;
            head = nxt;
        }

        if (isOdd)
            mid = mid->next;

        // compare
        while (head != NULL && mid != NULL) {
            if (head->val != mid->val)
                return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
};
