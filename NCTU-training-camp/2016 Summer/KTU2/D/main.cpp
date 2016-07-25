#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    ii inp[n];

    ll sum = 0, one = 0;
    for(int i = 0; i < n; i++) {
	int num;
	scanf("%d", &num);
	inp[i] = ii(num, i + 1);
	sum += num;
	if(num == 1)
	    one++;
    }

    if(sum % 2 != 0 || one == n) {
	printf("-1\n");
	return 0;
    }

    sort(inp, inp + n);
    
    deque< ii > d;
    for(int i = 0; i < n; i++)
	d.push_back(inp[i]);

    int internal = n - one;
    while(internal > 1) {
	ii node = d.back();
	d.pop_back();

	for(int i = 0; i < node.first - 1; i++) {
	    ii cur = d.front();
	    d.pop_front();
	    printf("%d %d\n", cur.second, node.second);
	}
	d.push_front(ii(1, node.second));
	internal--;
    }
    
    ii node = d.back();
    d.pop_back();
    while(d.size() > 0) {
	printf("%d %d\n", node.second, d.front().second);
	d.pop_front();
    }

    return 0;
}
