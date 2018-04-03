#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 **/
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a nested
    // list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested
    // list The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger> &getList();
};
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// we might have list-in-list
class NestedIterator
{
private:
    // the iterator runs through the vector
    // for every position, it's a NestedInteger object
    // so you can call the method 
    stack<vector<NestedInteger>::iterator> s; // pos
    stack<vector<NestedInteger>::iterator> se;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        if ((int)nestedList.size() > 0) {
            s.push(nestedList.begin());
            se.push(nestedList.end());
        }
    }

    int next()
    {
        int ret = s.top()->getInteger();
        s.top()++;
        return ret;
    }

    bool hasNext()
    {
        // set s.top() to the next answer position
        while (s.size() > 0) {
            if (s.top() == se.top()) {
                s.pop();
                se.pop();
            } else {
                if (s.top()->isInteger() == false) {
                    auto it = s.top();
                    s.top()++;

                    s.push(it->getList().begin());
                    se.push(it->getList().end());
                } else {
                    return true;
                }
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

#ifdef LOCAL
int main()
{
    return 0;
}
#endif