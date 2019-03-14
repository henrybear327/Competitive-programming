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
    ListNode *dfs(ListNode *prev, ListNode *cur)
    {
        if (cur == NULL)
            return NULL;

        if (cur->next == NULL) {
            cur->next = prev;
            return cur;
        }

        ListNode *ret = dfs(cur, cur->next);
        cur->next = prev;
        return ret;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        // recursive
        return dfs(NULL, head);

        //         // iterative
        //         ListNode* prev = NULL;
        //         while(head != NULL) {
        //             ListNode* next = head->next;
        //             head->next = prev;
        //             prev = head;

        //             if(next == NULL) // lol
        //                 break;
        //             head = next;
        //         }

        //         return head;
    }
};
