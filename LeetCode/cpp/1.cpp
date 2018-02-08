#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++)
            for (int j = i + 1; j < (int)nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);

                    return res;
                }
            }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> inp = {2, 7, 11, 15};
    auto res = s.twoSum(inp, 9);
    printf("%d %d\n", res[0], res[1]);

    return 0;
}