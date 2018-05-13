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
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?

class Solution
{
private:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *cur = head->next, *prev = head;
		while (cur != NULL) {
			ListNode *curNext = cur->next;
			cur->next = prev;
			prev = cur;
			cur = curNext;
		}
		head->next = NULL;

		return prev;
	}

public:
	ListNode *plusOne(ListNode *head)
	{
		if (head == NULL)
			return head;

		// reverse
		head = reverseList(head);

		head->val += 1;
		for (auto cur = head; cur != NULL; cur = cur->next) {
			if (cur->val >= 10) {
				if (cur->next == NULL) {
					cur->next = new ListNode(0);
				}
				cur->next->val += 1;
				cur->val %= 10;
			}
		}

		head = reverseList(head);

		return head;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif