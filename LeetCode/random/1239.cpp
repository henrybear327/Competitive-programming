class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        vector<int> mask;
        mask.reserve(arr.size());
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (const auto &j : arr[i]) {
                int code = j - 'a';
                if (tmp & (1 << code)) {
                    // e.g. uau -> skip
                    tmp = 0;
                    break;
                } else {
                    tmp |= (1 << code);
                }
            }

            if (tmp > 0)
                mask.push_back(tmp);
        }

        int ans = 0;
        n = mask.size();
        for (int i = 0; i < (1 << n); i++) {
            int tmp = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    cnt += __builtin_popcount(mask[j]);
                    tmp |= mask[j];

                    if (__builtin_popcount(tmp) != cnt) {
                        break;
                    }
                }
            }

            if (__builtin_popcount(tmp) == cnt) {
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
