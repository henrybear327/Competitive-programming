// :%s/^ \* //g
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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        if (slow == NULL)
            return false;

        while (slow != NULL && fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;

            if (slow != NULL && slow == fast)
                return true;
        }

        return false;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
