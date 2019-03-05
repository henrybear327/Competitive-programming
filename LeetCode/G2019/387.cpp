class Solution
{
public:
    int firstUniqChar(string s)
    {
        int cnt[26] = {0};
        int firstOcc[26];
        memset(firstOcc, -1, sizeof(firstOcc));
        for (int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            if (firstOcc[c] == -1)
                firstOcc[c] = i;

            cnt[c]++;
            if (cnt[c] > 1)
                firstOcc[c] = -2;
        }

        int ans = -1, mn = INT_MAX;
        for (int i = 0; i < 26; i++)
            if (firstOcc[i] >= 0 && firstOcc[i] < mn) {
                mn = firstOcc[i];
                ans = firstOcc[i];
            }

        return ans;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int cnt[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            cnt[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (cnt[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};