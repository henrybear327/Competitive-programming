#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	// (()())
	// 122333
	// 333221
	// 121210
	// ((()))
	// 123210
	// (?(?))
	// 123210
	// (??(??
	int n;
	scanf("%d", &n);
	if(n % 2 == 1) {
		printf(":(\n");
		return 0;
	}

	char inp[n + 3];
	scanf("%s", inp);
	int l = 0, r = 0;
	for(int i = 0; i < n; i++)
		if(inp[i] == '(')
			l++;
		else if(inp[i] == ')')
			r++;

	int sum = 0;
	bool ok = true;
	char ans[n + 3] = {'\0'};
	for(int i = 0; i < n - 1; i++) {
		if(inp[i] != '?') {
			sum += inp[i] == '(' ? 1 : -1;
			ans[i] = inp[i];
			if(sum <= 0) {
				ok = false;
				goto done;
			}
		} else {
			int canL = n / 2 - l;
			int canR = n / 2 - r;
			if(sum == 1) {
				if(canL == 0) {
					ok = false;
					goto done;
				}
				sum += 1;
				ans[i] = '(';
				l++;
			} else {
				if(canL > 0) {
					sum += 1;
					l++;
					ans[i] = '(';
				} else if (canR > 0){
					sum -= 1;
					r++;
					ans[i] = ')';
				} else {
					ok = false;
					goto done;
				}
			}
		}

		// printf("%d %d %d %d %c\n", i, sum, l, r, ans[i]);
	}

	ans[n - 1] = ')';
	if(inp[n - 1] == '?') {
		if(sum != 1 || l != n / 2 || r != (n / 2 - 1))
			ok = false;
	} else {
		if(sum != 1 || l != n / 2 || r != n / 2)
			ok = false;
	}
done:
	if(ok)
		printf("%s\n", ans);
	else
		printf(":(\n");
	return 0;
}
