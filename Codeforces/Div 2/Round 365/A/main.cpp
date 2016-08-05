#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	int m = 0, c = 0;
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if(a > b)
			m++;
		if(b > a)
			c++;
	}

	if(m > c)
		printf("Mishka\n");
	else if(c > m)
		printf("Chris\n");
	else
		printf("Friendship is magic!^^\n");
	
    return 0;
}
