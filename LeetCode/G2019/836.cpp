typedef pair<int, int> ii;
class Solution {
private: 
    bool hasOverlap(ii a, ii b)
    {
        if(a.first > b.first)
            swap(a, b);
        else if(a.first == b.first && a.second < b.second)
            swap(a, b);
    
        if(a.first < b.first && b.first < a.second)
            return true;
        if(a.first == b.first && a.first < b.second && b.second < a.second)
            return true;
        return false;
    }
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return hasOverlap({rec1[0], rec1[2]}, {rec2[0], rec2[2]}) && 
            hasOverlap({rec1[1], rec1[3]}, {rec2[1], rec2[3]});
    }
};
