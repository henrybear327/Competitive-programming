#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    map<string, int> m;
    for(int i = 0; i < n; i++) {
	char inp[1000];
	scanf("%s", inp);

	string name = inp;

	m[name] = i;
    }
    
    map<int, string> ans;
    for(auto i : m)
	ans.insert(make_pair(i.second, i.first));
    for(auto i = ans.rbegin(); i != ans.rend(); i++)
	printf("%s\n", i->second.c_str());

    return 0;
}
