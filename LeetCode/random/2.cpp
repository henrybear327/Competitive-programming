/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *tail = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int v1 = l1 == NULL ? 0 : l1->val;
            int v2 = l2 == NULL ? 0 : l2->val;

            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;

            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *newNode = new ListNode(sum);
            if (tail == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        if (carry == 1)
            tail->next = new ListNode(1), tail = tail->next;

        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *head = l1, *cur = l1;
        while (l1 != NULL || l2 != NULL || carry > 0) {
            int val = carry;
            carry = 0;
            if (l1 != NULL) {
                val += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                val += l2->val;
                l2 = l2->next;
            }

            carry = val / 10;
            val %= 10;

            cur->val = val;
            if (cur->next == NULL && (l1 != NULL || l2 != NULL || carry > 0)) {
                cur->next = new ListNode();
            }
            cur = cur->next;
        }

        return head;
    }
};
