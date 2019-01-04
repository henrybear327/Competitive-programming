#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const char* size[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int main()
{
	int cnt[6];
	for(int i = 0; i < 6; i++)
		scanf("%d", &cnt[i]);
	
	int n;
	scanf("%d", &n);
	int one[6] = {0};
	pair<int, ii> two[6];
	for(int i = 0; i < n; i++) {
		char inp[1000];
		scanf("%s", inp);
		
		int len = strlen(inp);
		bool isTypeOne = true;
		for(int j = 0; j < len; j++)
			if(inp[j] == ',')
				isTypeOne = false;

		if(isTypeOne == true) {
			
		}
	}

    return 0;
}
