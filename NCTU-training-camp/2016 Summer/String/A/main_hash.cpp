#include <bits/stdc++.h>

using namespace std;

#define N 1000100
#define B 137
#define M 1000000007

typedef long long ll;

char inp[N];
int len;
ll p[N], h[N];

void init()
{
    // build polynomial table and hash value
    p[0] = 1;
    for(int i = 1; i <= len; i++) {
	h[i] = (h[i - 1] * B % M + inp[i - 1]) % M;
	p[i] = p[i - 1] * B % M;
    }
}

ll get_hash(int l, int r)
{
    return ((h[r + 1] - (h[l] * p[r - l + 1])) % M + M) % M;
}

bool check(int x)
{
    for(int i = 1; i + x - 1 < len - 1; i++) {
	if(get_hash(0, x - 1) == get_hash(i, i + x - 1))
	    return true;
    }	
    return false;
}   

int main()
{
    scanf("%s", inp);
    len = strlen(inp);
    
    init();
    
    // get possible length
    vector<int> s;
    s.push_back(0);
    for(int i = 1; i <= len - 2; i++) {
	if(get_hash(0, i - 1) == get_hash(len - i, len - 1)) {
	    s.push_back(i);
	}
    }
    
    // binary search
    int l = 0, r = s.size();
    while(r - l > 1) { //[l, r)
	int mid = l + (r - l) / 2;

	if(check(s[mid]) == true) 
	    l = mid;
	else
	    r = mid;
    }
    
    if(s[l] == 0)
	printf("Just a legend\n");
    else
	for(int i = 0; i < s[l]; i++)
	    printf("%c", inp[i]);

    return 0;
}
