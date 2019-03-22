struct Data {
    int who;
    int freq;

    bool operator<(const Data &others) const
    {
        return freq < others.freq;
    }
};

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int cnt[26] = {0};
        for (auto i : tasks) {
            cnt[i - 'A']++;
        }

        priority_queue<Data> pq;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                pq.push({i, cnt[i]});
            }
        }

        int time = 0;
        int r = 0;
        while (pq.size() > 0) {
            // cout << pq.size() << endl;
            vector<int> cand;
            time = (n + 1) * r;
            for (int i = 0; pq.size() > 0 && i <= n; i++) {
                Data cur = pq.top();
                pq.pop();

                cnt[cur.who]--;
                if (cnt[cur.who] > 0)
                    cand.push_back(cur.who);
                time++;
            }

            for (auto i : cand)
                pq.push({i, cnt[i]});
            r++;
        }
        return time;
    }
};
