
// solution1;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int index = 0;
        int n = (int)citations.size();
        
        for (int c : citations){
            if (c >= n - index) return n - index;
            else index++;
        }
        
        return 0;
    }
};


// solution2;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int index = 0, n = (int)citations.size();
        
        int left = 0;
        int right = n- 1;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if (citations[mid] == n - mid) return n - mid;
            else if (citations[mid] < n - mid) left = mid + 1;
            else right = mid - 1;
        }
        
        return n - left;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int index = 0, n = (int)citations.size();
        
        
        // left, rightのお気持ちがわからない・・・leftとrightはそれぞれ何を意味してるの・・
        int left = 0;
        int right = n- 1;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if (citations[mid] == n - mid) return n - mid;
            else if (citations[mid] < n - mid) left = mid + 1;
            else right = mid - 1;
        }
        
        return n - left;
    }
};
