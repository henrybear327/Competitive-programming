#include <bits/stdc++.h>

using namespace std;

int main()
{
	char inp[111111];
	scanf("%s", inp);

	int cnt[26] = {0};
	
	int len = strlen(inp);
	for(int i = 0; i < len; i++) 
		cnt[inp[i] - 'a']++;
	
	int pos = -1;
	for(int i = 0; i < 26; i++)
		if(cnt[i] == 0) {
			pos = i;
			break;
		}
	
	if(pos == -1)
		printf("None\n");
	else
		printf("%c\n", pos + 'a');

	return 0;
}
