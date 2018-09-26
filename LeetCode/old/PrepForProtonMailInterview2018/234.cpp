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
    bool isPalindrome(ListNode *head)
    {
        deque<int> deq;
        while (head != NULL) {
            deq.push_back(head->val);
            head = head->next;
        }

        while (deq.size() > 0) {
            if (deq.front() != deq.back())
                return false;
            deq.pop_front();
            if (deq.size() > 0)
                deq.pop_back();
        }

        return true;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
