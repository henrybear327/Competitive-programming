#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    return 0;
}
();

class Solution
{
private:
    unordered_map<string, string> encoding, decoding;
    string generate()
    {
        string res = "";
        for (int i = 0; i < 6; i++) {
            // 0-9 a-z A-z
            // 10+26+26 = 62
            int r = rand() % 62;

            if (r < 10) {
                res += (r + '0');
            } else if (r < 36) {
                res += (r - 10 + 'a');
            } else {
                res += (r - 36 + 'A');
            }

            return res;
        }
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        if (encoding.find(longUrl) != encoding.end())
            return encoding[longUrl];

        string res = "";
        do {
            res = generate();
        } while (decoding.find(res) != decoding.end());

        encoding[longUrl] = res;
        decoding[res] = longUrl;

        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        if (decoding.find(shortUrl) == decoding.end())
            return "";
        return decoding[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

#ifdef LOCAL
int main()
{
    return 0;
}
#endif