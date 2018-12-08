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

class Solution
{
public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B)
    {
        vector<int> ans;
        for (auto i : A) {
            for (int j = 0; j < (int)B.size(); j++) {
                if (B[j] >= 0 && i == B[j]) {
                    ans.push_back(j);
                    B[j] = -B[j];
                    break;
                }
            }
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif