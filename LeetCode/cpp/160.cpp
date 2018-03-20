// https://leetcode.com/problems/intersection-of-two-linked-lists/solution/
// Two pointers technique is awesome!
// Start 2 pointers, one at A head and one at B head.
// When A ptr runs to the end of the list, send it back to B head.
// Same principle applies to the other pointer.
// If the pointers meet, that very node will be the intersecting node
// (guaranteed to finish in 2 iters)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // unordered_set<ListNode *> seen;
        // while (headA != NULL) {
        //     seen.insert(headA);
        //     headA = headA->next;
        // }

        // while (headB != NULL) {
        //     if (seen.find(headB) != seen.end())
        //         return headB;
        //     headB = headB->next;
        // }

        // return NULL;

        if (headA == NULL || headB == NULL)
            return NULL;

        int iters = 0;
        ListNode *origA = headA, *origB = headB;
        while (iters <= 2) {
            if (headA == headB)
                return headA;

            if (headA->next == NULL) {
                headA = origB;
                iters++;
            } else
                headA = headA->next;
            if (headB->next == NULL) {
                headB = origA;
                iters++;
            } else
                headB = headB->next;
        }

        return NULL;
    }
};

int main()
{
    return 0;
}