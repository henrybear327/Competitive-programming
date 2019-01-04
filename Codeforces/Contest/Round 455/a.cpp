#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    string inp1, inp2;
    cin >> inp1 >>  inp2;

    vector<string> cand;
    int l1 = inp1.length();
    int l2 = inp2.length();
    for(int i = 1; i <= l1; i++) {
        for(int j = 1; j <= l2; j++) {
            cand.push_back(inp1.substr(0, i) + inp2.substr(0, j));
        }
    }

    sort(cand.begin(), cand.end());
    cout << cand[0] << endl;
	
    return 0;
}
