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
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *tail = NULL; // tail man!

        while (l1 != NULL || l2 != NULL) {
            ListNode *cur = NULL;
            bool stop = false;
            if (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    cur = l1;
                    l1 = l1->next;
                } else {
                    cur = l2;
                    l2 = l2->next;
                }
            } else if (l1 != NULL) {
                cur = l1;
                stop = true;
            } else { // l2 != NULL
                cur = l2;
                stop = true;
            }

            if (head == NULL)
                head = tail = cur;
            else {
                tail->next = cur;
                tail = cur;
            }

            if (stop) // shortcut
                break;
        }
        return head;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
