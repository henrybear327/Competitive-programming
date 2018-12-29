#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    
    ii inp[111];
    for(int i = 0; i < n; i++) {
	int num;
	scanf("%d", &num);

	inp[i] = ii(num, i + 1);
    }

    sort(inp, inp + n );
    
    for(int i = 0; i < n / 2; i++) {
	printf("%d %d\n", inp[i].second, inp[n - 1 - i].second);
    }
	
    return 0;
}
