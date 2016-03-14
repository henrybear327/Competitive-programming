#include <bits/stdc++.h>

using namespace std;

int n, k;
int cal(int v)
{
    int ans = v, k1 = k;
    while(v / k1 > 0) {
	ans += v / k1;
	k1 *= k;
    }
    
    return ans;
}

int main()
{
    scanf("%d %d", &n, &k);
    
    int l = 1, r = n;
    while(r > l) {
	int mid = (l + r) / 2, val = cal(mid);
	
	if(val >= n)  // >= is ok according to the statement, so let's keep this mid
	    r = mid;	
	else 
	    l = mid + 1; // mid is not enough for this interval, so let's try (mid + 1)
    }
    
    printf("%d\n", r); 

    return 0;
}

