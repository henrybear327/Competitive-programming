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
class Solution
{
private:
    int ok(vector<int> &data, int start)
    {
        int len = 0;
        if (data[start] > 255) {
            // cout << "byte error" << endl;
            return -1;
        }

        // get length
        if (((data[start] >> 7) & 1) == 0) {
            len = 1;
        } else if ((data[start] >> 5) == 0b110) {
            len = 2;
        } else if ((data[start] >> 4) == 0b1110) {
            len = 3;
        } else if ((data[start] >> 3) == 0b11110) {
            len = 4;
        } else {
            // cout << "length error" << endl;
            return -1;
        }

        for (int i = 1; i < len; i++) {
            if (data[start + i] > 255) {
                // cout << "byte error" << endl;
                return -1;
            }
            if ((data[start + i] >> 6) != 0b10) { // not starting with 10
                // cout << "not starting with 10 error: " << i << " "
                // << (data[start + i] >> 6) << " " << data[start + i] << endl;
                return -1;
            }
        }

        return len;
    }

public:
    bool validUtf8(vector<int> &data)
    {
        for (int i = 0; i < (int)data.size();) {
            int ret = ok(data, i);
            if (ret == -1)
                return false;
            i += ret;
        }
        return true;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
