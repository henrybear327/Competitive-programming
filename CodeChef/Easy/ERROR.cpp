#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
	char inp[111111];
	scanf("%s", inp);
	
	int len = strlen(inp);
	bool ok = false;
	for(int i = 0; i < len; i++) {
		if(strncmp(inp + i, "101", 3) == 0)
			ok = true;
		if(strncmp(inp + i, "010", 3) == 0)
			ok = true;
	}

	printf("%s\n", ok ? "Good" : "Bad");
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
