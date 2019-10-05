class Solution
{
public:
    // O(n log n)
    //     vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    //         sort(arr.begin(), arr.end());
    //         vector<vector<int>> ans;
    //         int mn = INT_MAX;
    //         for(int i = 1; i < arr.size(); i++)
    //             mn = min(mn, abs(arr[i] - arr[i - 1]));

    //         for(int i = 1; i < arr.size(); i++) {
    //             if(abs(arr[i] - arr[i - 1]) == mn) {
    //                 ans.push_back(vector<int>{arr[i - 1], arr[i]});
    //             }
    //         }

    //         return ans;
    //     }

    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        bool val[2 * 1000000 + 1] = {false};
        for (auto i : arr)
            val[i + 1000000] = true;

        int mn = INT_MAX;
        for (int l = 0; l < 2 * 1000000 + 1; l++) {
            if (val[l]) {
                int r = l + 1;
                while (r < 2 * 1000000 + 1 && val[r] == false)
                    r++;
                if (r < 2 * 1000000 + 1 && val[r]) {
                    mn = min(mn, r - l + 1);
                }

                l = r - 1;
            }
        }

        vector<vector<int>> ans;
        for (int l = 0; l < 2 * 1000000 + 1; l++) {
            if (val[l]) {
                int r = l + 1;
                while (r < 2 * 1000000 + 1 && val[r] == false)
                    r++;
                if (r < 2 * 1000000 + 1 && val[r] && r - l + 1 == mn) {
                    ans.push_back(vector<int> {l - 1000000, r - 1000000});
                }

                l = r - 1;
            }
        }

        return ans;
    }
};
