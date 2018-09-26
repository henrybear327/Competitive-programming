#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

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
public:
	int numComponents(ListNode *head, vector<int> &G)
	{
		unordered_set<int> s;
		for (auto i : G)
			s.insert(i);

		int cc = 0;
		bool active = false;
		while (head != NULL) {
			if (s.count(head->val) > 0) {
				active = true;
			} else {
				if (active) {
					active = false;
					cc++;
				}
			}
			head = head->next;
		}

		if (active)
			cc++;

		return cc;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif