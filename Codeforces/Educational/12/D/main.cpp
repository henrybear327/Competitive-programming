#include <bits/stdc++.h>

using namespace std;

set<int> p;
void gen()
{
    bool isp[2000100];
    for(int i = 0; i < 2000100; i++)
	isp[i] = true;
    isp[0] = isp[1] = false;
    for(int i = 2; i < 2000100; i++) {
	if(isp[i] == true) {
	    for(int j = 2; i * j < 2000100; j++)
		isp[i * j] = false;
	}
    }

    for(int i = 2; i < 2000100; i++)
	if(isp[i] == true)
	    p.insert(i);
}

int main()
{
    int n;
    scanf("%d", &n);

    gen();

    vector<int> one, odd, even;
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);

	if(tmp == 1)
	    one.push_back(1);
	else if(tmp % 2 == 0)
	    even.push_back(tmp);
	else
	    odd.push_back(tmp);
    }

    if((int)one.size() > 0) {
	for(auto i : even) {
	    if(p.find(i + 1) != p.end()) {
		printf("%d\n", (int)one.size() + 1);
		for(int j = 0; j < (int)one.size(); j++)
		    printf("1 ");
		printf("%d\n", i);
		return 0;
	    }
	}

	vector<int> ans;
	for(auto i : odd) {
	    if((int)ans.size() != 0)
		break;
	    for(auto j : even) {
		if((int)ans.size() != 0)
		    break;
		if(p.find(i + j) != p.end()) {
		    ans.push_back(i);
		    ans.push_back(j);
		}
	    }
	}

	if(one.size() > ans.size()) {
	    printf("%d\n", (int)one.size());
	    for(int i = 0; i < (int)one.size(); i++)
		printf("1 ");
	} else {
	    printf("%d\n", (int)ans.size());
	    for(int i = 0; i < (int)ans.size(); i++)
		printf("%d ", ans[i]);
	}
	return 0;
    } else {
	if((int)odd.size() == 0) {
	    printf("1\n%d\n", even[0]);
	    return 0;
	} else if(even.size() == 0) {
	    printf("1\n%d\n", odd[0]);
	    return 0;
	}
	for(auto i : odd) {
	    for(auto j : even) {
		int sum = i + j;

		if(p.find(sum) != p.end()) {
		    printf("2\n%d %d\n", i, j);
		    return 0;
		}
	    }
	}

	printf("1\n%d\n", even[0]);
    }

    return 0;
}
