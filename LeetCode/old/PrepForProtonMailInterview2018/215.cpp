// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
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

class Solution
{
private:
    int kthElement(vector<int> &nums, int l, int r, int k) // [l, r)
    {
        if (l == r)
            return -1;

        // random pivot
        int pivot = l + rand() % (r - l);
        swap(nums[r - 1], nums[pivot]);

        pivot = r - 1;
        int candidate = l;
        // move small elements to front
        for (int i = l; i < r - 1; i++) {
            if (nums[i] <= nums[pivot]) {
                swap(nums[i], nums[candidate]);
                candidate++;
            }
        }

        swap(nums[candidate], nums[pivot]);
        pivot = candidate;

        if (pivot == k)
            return nums[pivot];
        else if (pivot < k)
            return kthElement(nums, pivot + 1, r, k);
        else
            return kthElement(nums, l, pivot, k);
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return kthElement(nums, 0, nums.size(), nums.size() - k);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
