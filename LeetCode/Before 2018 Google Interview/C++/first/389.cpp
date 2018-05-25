#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> scnt;
        for(auto i : s)
        	scnt[i]++;
        for(auto i : t) {
        	if(scnt[i] > 0)
        		scnt[i]--;
        	else
        		return i;
        }

        return ' ';
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif