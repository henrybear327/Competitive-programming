#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
	int n;
	scanf("%d", &n);

	int inp[n];
	for(int i = 0; i < n; i++)
	    scanf("%d", &inp[i]);
	
	while(n > 1) {
	    sort(inp, inp + n);
	    bool repeat = false;
	    for(int i = 0; i < n - 1; i++) {
		if(inp[i] == inp[i + 1])
		    repeat = true;
	    }

	    int idx = 0;
	    int tmp[n];
	    
	    if(repeat == true) {
		for(int i = 0; i < n; i++) {
		    if(i + 1 < n && inp[i] == inp[i + 1]) { // has same value
			tmp[idx++] = inp[i] + 1; // merge, value + 1. (5, 5) -> 6
			i++;
		    } else // not same
			tmp[idx++] = inp[i];
		}
	    } else {
		inp[0] = inp[n - 1] + 1;
		break;
	    }
	    
	    n = idx;

	    for(int i = 0; i < n; i++) {
		// printf("%d ", tmp[i]);
		inp[i] = tmp[i];
	    }
	    // printf("\n");
	}

	printf("%d\n", inp[0]);
    }

    return 0;
}
