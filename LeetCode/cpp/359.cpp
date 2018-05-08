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

// handle special cases first
// [], "", ...
// range of input?

class Logger
{
private:
    map<string, int> nxt;

public:
    /** Initialize your data structure here. */
    Logger()
    {
        nxt.clear();
    }

    /** Returns true if the message should be printed in the given timestamp,
       otherwise returns false. If this method returns false, the message will not
       be printed. The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message)
    {
        if (nxt.find(message) != nxt.end()) {
            if (timestamp >= nxt[message]) {
                nxt[message] = timestamp + 10;
                return true;
            } else {
                return false;
            }
        }
        nxt[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */

#ifdef LOCAL
int main()
{
    return 0;
}
#endif