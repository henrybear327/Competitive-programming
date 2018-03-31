// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

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
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 2 pointers
        // What an observation

        ListNode *prev = NULL, *slow = head, *fast = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast != NULL) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if (prev == NULL) {
            // remove head
            head = head->next;
        } else {
            prev->next = slow->next;
        }
        free(slow);

        return head;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif