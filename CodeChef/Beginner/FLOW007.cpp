#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
	char inp[100];
	scanf("%s", inp);
	
	int len = strlen(inp);
	reverse(inp, inp + len);

	printf("%d\n", atoi(inp)); // leading zero, oops for %s!
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
