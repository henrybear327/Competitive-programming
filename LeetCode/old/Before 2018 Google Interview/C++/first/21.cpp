// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // no need to new object, it is slow
        ListNode *res = NULL, *cur = NULL;

        while (l1 != NULL || l2 != NULL) {
            int num = INT_MAX;
            int who = -1;
            if (l1 != NULL) {
                num = l1->val;
                who = 1;
            }
            if (l2 != NULL) {
                if (num > l2->val) {
                    who = 2;
                    num = l2->val;
                }
            }

            if (who == 1) {
                if (cur)
                    cur->next = l1;
                else
                    res = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                if (cur)
                    cur->next = l2;
                else
                    res = l2;
                cur = l2;
                l2 = l2->next;
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}