class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> s;
        for (auto i : str) {
            if (i == '(' || i == '[' || i == '{')
                s.push(i);
            else {
                if (s.size() <= 0)
                    return false;
                if (i == ')' && s.top() != '(')
                    return false;
                if (i == ']' && s.top() != '[')
                    return false;
                if (i == '}' && s.top() != '{')
                    return false;
                s.pop();
            }
        }

        return s.size() == 0;
    }
};
