#include <bits/stdc++.h>
using namespace std;

const int N = 8;

class SolutionWA
{
private:
    bool check(vector<int> &nums, int len)
    {
        int zero = 0, one = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0)
                zero++;
            else
                one++;
        }

        if (zero == one)
            return true;

        for (int i = len; i < (int)nums.size(); i++) {
            if (nums[i] == 0)
                zero++;
            else
                one++;

            if (nums[i - len] == 0)
                zero--;
            else
                one--;

            if (zero == one)
                return true;
        }

        return false;
    }

public:
    int findMaxLength(vector<int> &nums)
    {
        int l = 0, r = nums.size() / 2 + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            // printf("%d: %d %d %d\n", nums.size(), l, mid, r);

            if (check(nums, mid * 2))
                l = mid;
            else
                r = mid;
        }

        return l * 2;
    }
};

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int arr[2 * nums.size() + 1];
        fill(arr, arr + 2 * nums.size() + 1, -2);
        arr[nums.size()] = -1;
        int maxlen = 0, count = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            count = count + (nums[i] == 0 ? -1 : 1);
            if (arr[count + nums.size()] >= -1) {
                maxlen = max(maxlen, i - arr[count + nums.size()]);
            } else {
                arr[count + nums.size()] = i;
            }
        }
        return maxlen;
    }
};

int main()
{
    auto my = SolutionWA();
    auto ans = Solution();

    while (true) {
        vector<int> inp;
        for (int i = 0; i < N; i++) {
            inp.push_back(rand() % 2);
        }

        for (int i = 0; i < N; i++)
            printf("%d%c", inp[i], i == N - 1 ? '\n' : ' ');
        if (my.findMaxLength(inp) != ans.findMaxLength(inp)) {
            printf("WA\n");
            return 0;
        } else {
            printf("ok\n");
        }
    }

    return 0;
}
