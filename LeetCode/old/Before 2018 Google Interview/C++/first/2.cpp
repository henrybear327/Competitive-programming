#include <cstdio>
#include <cstdlib>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
    ListNode *createNode(int _val)
    {
        ListNode *res = (ListNode *)malloc(sizeof(ListNode));

        res->val = _val;
        res->next = NULL;
        return res;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int sum = 0;
        ListNode *res = NULL, *cur = NULL;

        while (l1 != NULL || l2 != NULL ||
               carry != 0) { // WA: don't forget the carry
            int v1 = 0, v2 = 0;
            if (l1 == NULL)
                v1 = 0;
            else {
                v1 = l1->val;
                l1 = l1->next;
            }

            if (l2 == NULL)
                v2 = 0;
            else {
                v2 = l2->val;
                l2 = l2->next;
            }

            sum = carry + v1 + v2;
            carry = sum / 10;
            sum %= 10;

            if (res == NULL) {
                res = createNode(sum);
                cur = res;
            } else {
                ListNode *tmp = createNode(sum);
                cur->next = tmp;
                cur = tmp;
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}