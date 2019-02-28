static int desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
();

/*
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> cnt;

        for(auto &i : emails) {
            {
                // deal with +
                auto plus = i.find("+");
                auto mouse = i.find("@");
                if(plus != string::npos && plus < mouse)
                    i.erase(plus, mouse - plus);
            }

            {
                // deal with .
                auto dot = i.find(".");
                auto mouse = i.find("@");
                while(dot != std::string::npos && dot < mouse) {
                    i.erase(dot, 1);
                    dot = i.find(".");
                }
            }

            cnt.insert(i);
        }

        return cnt.size();
    }
};
*/

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> cnt;

        for (auto &i : emails) {
            // filter by + first
            for (int j = 0; j < i.length(); j++) {
                if (i[j] == '@') // don't touch domain name
                    break;

                if (i[j] == '+') {
                    // get rid of things between the first + and @
                    // find @
                    for (int k = j + 1; k < i.length(); k++) {
                        if (i[k] == '@') {
                            i = i.substr(0, j) + i.substr(k);
                            break;
                        }
                    }
                    break;
                }
            }

            // cout << i << endl;
            // filter by .
            string tmp;
            for (int j = 0; j < i.length(); j++) {
                if (i[j] == '@') { // don't touch string after @
                    tmp += i.substr(j);
                    break;
                }

                if (i[j] == '.')
                    continue;
                tmp += i[j];
            }

            i = tmp;
            // cout << tmp << endl;

            cnt.insert(i);
        }

        return cnt.size();
    }
};
