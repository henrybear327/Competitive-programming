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

class Solution
{
private:
    ListNode *hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && slow) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (fast == slow)
                return slow;
        }

        return NULL;
    }

public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *meeting = hasCycle(head);
        if (meeting == NULL)
            return NULL;

        ListNode *s = head;
        while (s != meeting) {
            s = s->next;
            meeting = meeting->next;
        }
        return meeting;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif