class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        vector<char> s;
        s.reserve(S.size());
        for (auto i : S)
            if (i != '-')
                s.push_back(('a' <= i && i <= 'z') ? i - 'a' + 'A' : i);

        string ans;
        int cnt = 0;
        while (s.size() > 0) {
            if (cnt > 0 && cnt % K == 0)
                ans += '-';
            ans += s.back();
            s.pop_back();
            cnt++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 12321
        // 1221
        if (x < 0)
            return false;
        if (x < 10)
            return true;

        int left = x, right = 0;
        while (left / 10 > 0) { // 0 won't come in!!!!
            int cur = left % 10;

            if (left / 10 == right)
                return true;
            if (left / 10 == right * 10 + cur)
                return true;

            if (right == 0 && cur == 0) // 10000 special case, trailing 0 -> false
                return false;
            right *= 10;
            right += cur;
            left /= 10;
        }

        return false;
    }
};
