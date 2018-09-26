#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
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
    bool isVowel(char c)
    {
        if ('A' <= c && c <= 'Z')
            c = c - 'A' + 'a';
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string reverseVowels(string s)
    {
        int i = 0, j = (int)s.length() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i]))
                i++;
            while (i < j && !isVowel(s[j]))
                j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif