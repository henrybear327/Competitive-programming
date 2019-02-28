// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
#endif

/*
[1,1]
[2,2]
[1,2]
[2,3]
[2]
[1,3]
[1,2,5]
[2,4]
*/

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
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int totalA = 0, totalB = 0;
        for (auto &i : A)
            totalA += i;
        for (auto &i : B)
            totalB += i;

        int even = (totalA + totalB) / 2;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (auto &i : A) {
            int lookup = even - (totalA - i);
            auto it = binary_search(B.begin(), B.end(), lookup);
            if (it == false)
                continue;

            return vector<int> {i, lookup};
        }

        return vector<int> {};
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
