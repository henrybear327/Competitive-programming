#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);

	char inp[n + 10];
	scanf("%s", inp);
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(inp[i] == '<')
			cnt++;
		else
			break;
	}	

	for(int i = n - 1; i >= 0; i--) {
		if(inp[i] == '>')
			cnt++;
		else
			break;
	}
	printf("%d\n", cnt);
	
    return 0;
}
