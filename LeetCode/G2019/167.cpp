class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int lookFor = target - numbers[i];

            // lowerbound

            // auto lb = lower_bound(numbers.begin() + i + 1, numbers.end(), lookFor);
            // if(lb != numbers.end() && *lb == lookFor) {
            //     ans = vector<int>{i + 1, lb - numbers.begin() + 1};
            //     break;
            // }

            int l = i, r = n; //(l, r)
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (numbers[mid] < lookFor)
                    l = mid;
                else
                    r = mid;
            }

            if (r < n && numbers[r] == lookFor) {
                ans = vector<int> {i + 1, r + 1};
                break;
            }
        }
        return ans;
    }
};