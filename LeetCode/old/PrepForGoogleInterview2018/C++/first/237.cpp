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
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // 1 2 3 4 5
        // 1 2 4 5
        // ListNode *prev = node;
        // ListNode *nxt = node->next;
        // while (nxt != NULL) {
        //     prev->val = nxt->val;
        //     if (nxt->next == NULL) {
        //         prev->next = NULL;
        //         free(nxt);
        //         break;
        //     }
        //     prev = nxt;
        //     nxt = nxt->next;
        // }

        // bullshit solution...
        *node = *node->next;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif