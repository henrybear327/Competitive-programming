// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int __initialSetup = []()
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *cur = NULL;

        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int v1 = 0, v2 = 0;
            if (l1) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                v2 = l2->val;
                l2 = l2->next;
            }

            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *newNode = new ListNode(sum);
            if (head == NULL) {
                head = cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }
        }

        if (carry) {
            ListNode *newNode = new ListNode(carry);
            cur->next = newNode;
            cur = newNode;
        }

        return head;
    }
};

int main()
{
    return 0;
}