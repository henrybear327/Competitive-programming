#include <bits/stdc++.h>

using namespace std;

int main()
{
    string inp;
    cin >> inp;

    long long ans = 0;
    map<char, long long> cnt;
    for(int i = 0; i < (int)inp.length(); i++)
	cnt[inp[i]]++;

    for(auto i : cnt) {
	ans += i.second * i.second;
    }

    cout << ans << endl;

    return 0;
}
