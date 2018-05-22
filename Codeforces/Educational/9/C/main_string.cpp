#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b)
{
    return (a + b) < (b + a);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<string> inp;
    for(int i = 0; i < n; i++) {
	char tmp[100];
	scanf("%s", tmp);
	inp.push_back(tmp);
    }

    sort(inp.begin(), inp.end(), cmp);

    for(int i = 0; i < n; i++)
	printf("%s", inp[i].c_str());
    printf("\n");

    return 0;
}
