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

// use fast/slow pointers to find the mid point
// reverse the part after mid
// perform cmp
// What a solution!
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> s;
        while (head != NULL) {
            s.push(head->val);
            head = head->next;
        }

        if (s.size() <= 1)
            return true;

        stack<int> ss;
        int sz = s.size();
        while ((int)s.size() > sz / 2) {
            ss.push(s.top());
            s.pop();
        }
        if (s.size() != ss.size())
            ss.pop();

        while (s.size() > 0 && ss.size() > 0) {
            if (s.top() != ss.top())
                return false;
            s.pop();
            ss.pop();
        }
        return true;
    }
};

int main()
{
    return 0;
}