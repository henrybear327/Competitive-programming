// :%s/^ \* //g
#ifdef LOCAL
#include <iostream>
#include <vector>
using namespace std;

// define data structures here
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() == 1) {
            return true;
        }
        
        bool asc = true;
        for(int i = 1; i < (int)A.size(); i++) 
            if(A[i] < A[i - 1]) 
                asc = false;

        bool dec = true;
        for(int i = 1; i < (int)A.size(); i++) 
            if(A[i] > A[i - 1]) 
                dec = false;

        return asc || dec;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
