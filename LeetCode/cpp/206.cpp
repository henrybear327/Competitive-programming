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
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // A->B->C->D->NULL
    // ListNode *reverseList(ListNode *head)
    // {
    //     if (head == NULL || head->next == NULL)
    //         return head;
    //     auto tmp = reverseList(head->next);
    //     // A<-B<-C<-D
    //     head->next->next = head;
    //     head->next = NULL;

    //     return tmp;
    // }

    // A->B->C->D->NULL
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        auto cur = head;
        while (cur != NULL) {
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }
};

int main()
{
    return 0;
}