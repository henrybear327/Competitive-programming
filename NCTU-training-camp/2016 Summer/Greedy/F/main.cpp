#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define N (int)(1e5 + 10)
int main()
{
    char inp1[N], inp2[N];

    scanf("%s %s", inp1, inp2);
    
    int len2 = strlen(inp2);
    sort(inp2, inp2 + len2);
    reverse(inp2, inp2 + len2);
    
    int idx = 0, len1 = strlen(inp1);
    for(int i = 0; i < len1 && idx < len2; i++) {
	int cur = inp1[i] - '0';
	int cand = inp2[idx] - '0';

	if(cand > cur) {
	    inp1[i] = inp2[idx++];
	}
    }

    printf("%s\n", inp1);

    return 0;
}
