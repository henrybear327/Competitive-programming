#include <bits/stdc++.h>

using namespace std;

/*
int bsearch(int l, int r, int key, int inp[])
{
    int cand = l;
    int step = (r - l) / 2;

    while(step > 0) {
	if(cand + step < r) {
	    if(inp[cand + step] == key)
		return cand + step;
	    else if(inp[cand + step] < key)
		cand += step;
	    else
		step /= 2;
	} else
	    step /= 2;
    }
    return inp[cand] == key ? cand : -1;
}
*/

int bsearch(int l, int r, int key, int inp[]) 
{
    // upper_bound of this kind can replace binary search
    int cand = l;
    int step = (r - l) / 2;

    while(step > 0) {
	if(cand + step < r && inp[cand + step] <= key) 
	    cand += step;
	else
	    step /= 2;
    }

    return inp[cand] == key ? cand : -1;
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
	int inp[n];
	for(int i = 0; i < n; i++)
	    scanf("%d", &inp[i]);

	int sum;
	scanf("%d", &sum);

	sort(inp, inp + n);

	int a = -10000000, b = 10000000;
	for(int i = 0; i < n; i++) {
	    int diff = sum - inp[i];
	    int pos = bsearch(i + 1, n, diff, inp);
	    //printf("%d %d %d\n", inp[i], diff, pos);
	    if(pos != -1) {
		if(b - a > max(diff, inp[i]) - min(diff, inp[i])) {
		    a = min(inp[i], diff);
		    b = max(inp[i], diff);
		}
	    }
	}   

	printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }	

    return 0;
}
