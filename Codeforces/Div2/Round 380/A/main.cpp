#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);

	char inp[1000];
	scanf("%s", inp);
	
	for(int i = 0; i < n;) {
		if(i <= n - 3 && strncmp(inp + i, "ogo", 3) == 0) {
			i += 3;
			while(i <= n - 2 && strncmp(inp + i, "go", 2) == 0)
				i += 2;
			printf("***");
		}  else {
			printf("%c", inp[i]);
			i++;
		}
	}
	printf("\n");
	
    return 0;
}
