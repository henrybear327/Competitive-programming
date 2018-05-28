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
public:
    int evalRPN(vector<string> &tokens)
    {
        if (tokens.size() == 0)
            return 0;

        stack<string> s;
        for (auto i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                string second = s.top();
                s.pop();
                string first = s.top();
                s.pop();

                int num = 0;
                if (i == "+")
                    num = stoi(first) + stoi(second);
                else if (i == "-")
                    num = stoi(first) - stoi(second);
                else if (i == "*")
                    num = stoi(first) * stoi(second);
                else
                    num = stoi(first) / stoi(second);

                s.push(to_string(num));
            } else {
                s.push(i);
            }
        }

        return stoi(s.top());
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif