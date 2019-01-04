#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

char inp[100100];

int n;
map< char, int > cnt;
bool check(int len)
{
    map< char, int > cur;
    for(int i = 0; i < len; i++)
	cur[inp[i]]++;

    if(cnt.size() == cur.size())
	return true;
    
    for(int i = 1; i + len - 1 < n; i++) {
	cur[inp[i - 1]]--;
	if(cur[inp[i - 1]] == 0)
	    cur.erase(inp[i - 1]);

	cur[inp[i + len - 1]]++;

	if(cnt.size() == cur.size())
	    return true;
    }

    return false;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", inp);
    
    for(int i = 0; i < n; i++) {
	cnt[inp[i]]++;
    }
    
    int l = 0, r = n + 1;
    while(r - l > 1) {
	int mid = (l + r) / 2;
	if(check(mid))
	    r = mid;
	else
	    l = mid;
    }

    printf("%d\n", r);

    return 0;
}
