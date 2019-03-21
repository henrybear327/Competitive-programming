class Solution
{
private:
    int diff(string &a, string &b)
    {
        int ans = 0;
        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i])
                ans++;
        return ans;
    }

public:
    // BFS
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        int e = -1;
        for (int i = 0; i < n; i++)
            if (wordList[i] == endWord) {
                e = i;
                break;
            }
        if (e == -1)
            return 0;

        queue<int> q;
        int seen[n];
        memset(seen, -1, sizeof(seen));
        for (int i = 0; i < n; i++) {
            if (seen[i] == -1 && diff(beginWord, wordList[i]) <= 1) {
                seen[i] = 2;
                q.push(i);
            }
        }
        while (q.size() > 0) {
            int cur = q.front();
            q.pop();

            if (wordList[cur] == endWord)
                return seen[cur];

            for (int i = 0; i < n; i++) {
                if (seen[i] == -1 && diff(wordList[i], wordList[cur]) <= 1) {
                    seen[i] = seen[cur] + 1;
                    q.push(i);
                }
            }
        }

        return 0;
    }
};
