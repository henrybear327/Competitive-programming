#include <bits/stdc++.h>

using namespace std;

int main()
{
	char inp[100100];
	scanf("%s", inp);
	
	int len = strlen(inp);
	bool hasChange = false;
	for(int i = 0; i < len; i++) {
		if(hasChange == false && inp[i] == 'a') 
			continue;
		else if(hasChange == true && inp[i] == 'a')
			break;
		hasChange = true;
		inp[i]--;
	}

	if(hasChange == false) {
		inp[len - 1] = 'z';
	}
	printf("%s", inp);

	return 0;
}
