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
    srand(time(NULL));
    return 0;
}
();

class Solution
{
private:
    int getLength(ListNode *head)
    {
        int cnt = 0;
        while (head != NULL) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }

    void push(ListNode *&head, ListNode *&cur, ListNode *node)
    {
        if (head == NULL) {
            head = cur = node;
        } else {
            cur->next = node;
            cur = node;
        }
    }

    ListNode *myqsort(ListNode *head)
    {
        if (head == NULL)
            return head;

        int len = getLength(head);
        if (len == 1)
            return head;
        int pivot = rand() % len;

        // get pivot node
        ListNode *pivot_node = head;
        ListNode *prev = NULL;
        for (int i = 0; i < pivot; i++) {
            prev = pivot_node;
            pivot_node = pivot_node->next;
        }

        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = pivot_node->next;
        }
        pivot_node->next = NULL;

        // get left, right
        // fix TLE: extent pivot_node list! (WOW, what a test case!)
        ListNode *left = NULL, *right = NULL;
        ListNode *lcur = NULL, *rcur = NULL, *pcur = pivot_node;
        while (head != NULL) {
            if (head->val < pivot_node->val) {
                push(left, lcur, head);
            } else if (head->val > pivot_node->val) {
                push(right, rcur, head);
            } else {
                push(pivot_node, pcur, head);
            }
            head = head->next;
        }
        if (lcur)
            lcur->next = NULL;
        if (rcur)
            rcur->next = NULL;
        pcur->next = NULL;

        left = myqsort(left);
        right = myqsort(right);

        if (left != NULL) {
            head = left;
            while (left->next != NULL)
                left = left->next;
            left->next = pivot_node;
        } else
            head = pivot_node;

        pcur->next = right;

        return head;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        return myqsort(head);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif