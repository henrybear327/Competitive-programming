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
private:
    void connect(ListNode *&head, ListNode *&cur, ListNode *node)
    {
        if (head == NULL) {
            head = cur = node;
        } else {
            cur->next = node;
            cur = cur->next;
        }
    }

    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *head = NULL, *cur = NULL;
        while (a != NULL || b != NULL) {
            if (a != NULL && b != NULL) {
                if (a->val < b->val) {
                    connect(head, cur, a);
                    a = a->next;
                } else {
                    connect(head, cur, b);
                    b = b->next;
                }
            } else if (a != NULL) { // a not NULL b NULL
                connect(head, cur, a);
                a = a->next;
            } else { // a NULL b not NULL
                connect(head, cur, b);
                b = b->next;
            }
        }

        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 0 1 2 3 4 5 6 7
        // 0-7 1-6 2-5 3-4
        // 0-3 1-2
        // 0-1

        // 0 1 2 3 4 5 6
        // 0-6 1-5 2-4 3
        // 0-3 1-2
        // 0-1

        int sz = lists.size();
        while (sz > 1) {
            int j = sz - 1;
            for (int i = 0; i < sz / 2; i++) {
                // sz = 8, 0-7, 8/2=4
                // sz = 7, 0-6, 7/2=3
                // sz = 6, 0-5, 6/2=3

                lists[i] = merge(lists[i], lists[j]);
                j--;
            }

            if (sz % 2 == 1)
                sz = sz / 2 + 1;
            else
                sz = sz / 2;
        }

        return sz > 0 ? lists[0] : NULL;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif