#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    int case_cnt = 1;
    while(ncase--) {
	printf("Case #%d: ", case_cnt++);
	char inp[1000];
	scanf("%s", inp);
	
	// check if the - if present in the front
	int i = 0, ans = 0;
	if(inp[0] == '-') {
	    for(i = 0; inp[i] != '\0'; i++) {
		if(inp[i] == '-') {
		    continue;
		} else {
		    break;
		}
	    }
	    ans++;
	}

	for(; inp[i] != '\0'; i++) {
	    if(inp[i] == '+') {
		continue;
	    } else {
		while(inp[i + 1] != '\0' && inp[i + 1] == '-')
		    i++;
		ans += 2;
	    }
	}

	printf("%d\n", ans);
    }

    return 0;
}
