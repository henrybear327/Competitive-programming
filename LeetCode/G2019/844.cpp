class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        string s, t;
        for (auto i : S) {
            if (i == '#') {
                if (s.size() > 0)
                    s.pop_back();
            } else
                s.push_back(i);
        }

        for (auto i : T) {
            if (i == '#') {
                if (t.size() > 0)
                    t.pop_back();
            } else
                t.push_back(i);
        }

        return s == t;
    }
};