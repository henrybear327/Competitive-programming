/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) // WTF?
                pq.push(lists[i]);
        }

        ListNode *head = NULL, *tail = NULL;
        while (pq.size() > 0) {
            ListNode *top = pq.top();
            pq.pop();

            ListNode *next = top->next;
            top->next = NULL;
            if (head == NULL)
                head = tail = top;
            else
                tail->next = top, tail = tail->next;

            if (next != NULL)
                pq.push(next);
        }

        return head;
    }
};