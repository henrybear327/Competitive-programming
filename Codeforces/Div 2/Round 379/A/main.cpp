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
	
	int a = 0, b = 0;
	for(int i = 0; i < n; i++)
		if(inp[i] == 'A')
			a++;
		else
			b++;
	
	if(a > b)
		printf("Anton\n");
	else if(b > a)
		printf("Danik\n");
	else
		printf("Friendship\n");
	
    return 0;
}
