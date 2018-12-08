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
    // two pointers works because if there is an intersection, they will be
    // walking through the same length
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *origA = headA, *origB = headB;
        int cnt = 0;
        while (headA != headB) {
            headA = headA->next;
            if (headA == NULL) {
                headA = origB;
                cnt++;
            }
            headB = headB->next;
            if (headB == NULL) {
                headB = origA;
                cnt++;
            }

            if (cnt > 2)
                return NULL;
        }

        return headA;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
