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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *root = NULL, *tail = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int val = 0;
            if (l1 != NULL) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                val += l2->val;
                l2 = l2->next;
            }

            val += carry;
            carry = val / 10;
            val %= 10;
            if (root == NULL)
                root = tail = new ListNode(val);
            else {
                ListNode *newNode = new ListNode(val);
                tail->next = newNode;
                tail = newNode;
            }
        }

        if (carry >= 1) {
            ListNode *newNode = new ListNode(carry);
            tail->next = newNode;
            tail = newNode;
        }

        return root;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
