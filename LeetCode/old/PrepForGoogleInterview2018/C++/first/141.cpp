// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // hash table
        // unordered_set<ListNode *> seen;
        // for (ListNode *it = head; it != NULL; it = it->next) {
        //     if (seen.find(it) != seen.end())
        //         return true;
        //     seen.insert(it);
        // }

        // return false;

        if (head == NULL)
            return false;

        ListNode *fast = head->next, *slow = head;
        while (fast != NULL && slow != NULL) {
            if (fast == slow)
                return true;
            slow = slow->next;

            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        }

        return false;
    }
};

int main()
{
    return 0;
}