#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
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

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *odd = head, *even = head->next;
        ListNode *evenHead = even;

        while (odd != NULL && even != NULL) {
            if (odd->next != NULL) {
                odd->next = odd->next->next;
            }

            if (even->next != NULL) {
                even->next = even->next->next;
            }

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif