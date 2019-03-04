class Solution
{
public:
    int nextGreaterElement(int n)
    {
        vector<char> inp;
        while (n > 0) {
            inp.push_back((n % 10) - '0');
            n /= 10;
        }
        reverse(inp.begin(), inp.end());

        if (next_permutation(inp.begin(), inp.end()) == false)
            return -1;
        else {
            long long ans = 0;
            for (auto i : inp)
                ans *= 10, ans += i + '0';
            return ans > INT_MAX ? -1 : (int)ans;
        }
    }
};
