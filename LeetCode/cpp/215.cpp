// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    srand(time(NULL));
    return 0;
}
();

class Solution
{
private:
    bool greater(int inc, int a, int b)
    {
        if (inc > 0)
            return a > b;
        return a < b;
    }

    int quicksort(vector<int> &nums, int k, int l, int r)
    {
        int pivot = l + rand() % (r - l);
        int cand = r - 1;
        swap(nums[pivot], nums[l]);
        pivot = l; // WTF...

        int inc = 1;
        // pivot --- cand
        while (pivot != cand) {
            if (greater(inc, nums[pivot], nums[cand])) {
                swap(nums[pivot], nums[cand]);
                swap(pivot, cand);
                inc = inc > 0 ? -1 : 1;
            }

            pivot += inc;
        }

        if ((int)nums.size() - k == pivot)
            return nums[pivot];
        else if ((int)nums.size() - k < pivot)
            return quicksort(nums, k, l, pivot);
        return quicksort(nums, k, pivot + 1, r);
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quicksort(nums, k, 0, nums.size());
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif