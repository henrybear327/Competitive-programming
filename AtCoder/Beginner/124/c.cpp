#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    // the key: think about the end result
	// it's either 010101... or 10101010...
    char inp[100010];
    scanf("%s", inp);
    int ans = INT_MAX, n = strlen(inp);
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (inp[i] == '0' && i % 2 == 1)
            cnt++;
        else if (inp[i] == '1' && i % 2 == 0)
            cnt++;

        if (inp[i] == '0' && i % 2 == 0)
            cnt2++;
        else if (inp[i] == '1' && i % 2 == 1)
            cnt2++;
    }

    ans = min(cnt, cnt2);

    printf("%d\n", ans);

    return 0;
}
