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
class ZigzagIterator
{
private:
    vector<int> data1, data2;
    int who;
    vector<int>::iterator it1, it2;

public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2)
    {
        data1 = v1;
        data2 = v2;
        it1 = data1.begin();
        it2 = data2.begin();
        who = it1 != data1.end() ? 0 : 1;
    }

    int next()
    {
        int ret = -1;
        if (who == 0) {
            ret = *it1;
            it1++;
            if (it2 != data2.end())
                who = 1;
        } else {
            ret = *it2;
            it2++;
            if (it1 != data1.end())
                who = 0;
        }
        return ret;
    }

    bool hasNext()
    {
        if (it1 != data1.end() || it2 != data2.end())
            return true;
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
