
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        
        int i = 0;
        
        while (i < citations.size()){
            if (citations[citations.size()-1-i] > i) i++;
            else break;
        }
        
        return i;
    }
};
