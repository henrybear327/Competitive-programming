// :%s/^ \*//g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
private:
    ListNode *go(ListNode *head, ListNode *prev)
    {
        if (head == NULL)
            return prev;

        ListNode *nxt = head->next;
        head->next = prev;

        return go(nxt, head);
    }

public:
    // iterative
    ListNode *reverseList1(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *nxt = head->next;
            head->next = prev;
            prev = head;
            if (nxt == NULL)
                break;
            head = nxt;
        }
        return head;
    }

    // recursive
    ListNode *reverseList(ListNode *head)
    {
        return go(head, NULL);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
