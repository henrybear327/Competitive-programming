#include <bits/stdc++.h>

using namespace std;

int main()
{   
    char inp[200010];
    fgets(inp, 200010, stdin);

    int len = strlen(inp);
    for(int i = 1; i < len; i++) {
	if(inp[i] == inp[i - 1]) {
	    if(i + 1 < len) {
		for(int j = 0; j < 26; j++) {
		    int cand = (inp[i] - 'a' + j) % 26;
		    if((cand + 'a' != inp[i + 1]) && (cand + 'a' != inp[i])) {
			inp[i] = cand + 'a';
			break;
		    }
		}
	    } else {
		inp[i] = ((inp[i] - 'a' + 1) % 26) + 'a';
	    }
	}
    }

    printf("%s", inp);

    return 0;
}
