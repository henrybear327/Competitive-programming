typedef pair<int, int> ii;
class FirstUnique {
private:
    queue<int> q;
    map<int, int> seen;
public:
    FirstUnique(vector<int>& nums) {
        for(int i = 0; i < (int)nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        while(q.size() > 0) {
            if(seen[q.front()] > 1)
                q.pop();
            else
                break;
        }
        return q.size() == 0 ? -1 : q.front();
    }
    
    void add(int value) {
        seen[value]++;
        if(seen[value] == 1)
            q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
