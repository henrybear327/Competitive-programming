class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i : stones)
            pq.push(i);
        
        while(pq.size() > 1) {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if(f == s)
                continue;
            pq.push(max(f, s) - min(f, s));
        }
        
        if(pq.size() == 1)
            return pq.top();
        return 0;
    }
};
