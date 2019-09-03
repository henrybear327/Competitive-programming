class Solution
{
private:
    typedef pair<int, int> ii;
    vector<ii> inp;
    vector<int> ans;
    void mergeSort(int l, int r)   // [l, r)
    {
        if (l + 1 == r)
            return;
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid, r);

        int tmp = r - 1;
        for (int i = mid - 1; i >= l; i--) {
            // cout << tmp << endl;
            while (tmp >= mid && inp[tmp].first >= inp[i].first)
                tmp--;
            ans[inp[i].second] += (tmp - mid + 1);

            // cout << inp[i].second << " " << tmp << " " << mid << endl;
        }

        inplace_merge(inp.begin() + l, inp.begin() + mid, inp.begin() + r);
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        if (nums.size() == 0)
            return vector<int>();

        ans = vector<int>(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
            inp.push_back(ii(nums[i], i));
        mergeSort(0, inp.size());
        return ans;
    }
};
