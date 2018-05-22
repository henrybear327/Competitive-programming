// pigenhole
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

char inp[100010];
int n;

int main()
{
    scanf("%s", inp);

    n = strlen(inp);
    int lastSeen[26] = {0};
	memset(lastSeen, -1, sizeof(lastSeen));
    int mx[26];
    memset(mx, -1, sizeof(mx));
    // abced
    for (int i = 0; i < n; i++) {
        int diff = i - lastSeen[inp[i] - 'a'];
        mx[inp[i] - 'a'] = max(mx[inp[i] - 'a'], diff);
        lastSeen[inp[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        if (mx[i] != -1)
            mx[i] = max(n - lastSeen[i], mx[i]);
	}
	
    int ans = INT_MAX;
    for (int i = 0; i < 26; i++)
        if (mx[i] != -1)
            ans = min(ans, mx[i]);
    printf("%d\n", ans);

    return 0;
}
