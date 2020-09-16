/*
    2020-09-16
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        
        if (n == 0) return 0;
        
        int pos = 0; // [0,pos]の間はduplicateが除去されている
        
        for (int i = 1; i < n; i++){
            if (nums[pos] != nums[i]){
                pos++;
                nums[pos] = nums[i];
            }
        }
        
        // [0,0,1,1,2,2,3]
        // when finished, pos = 3, expected = 4
        return pos+1;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int slower = 0;
        
        for (int faster = 1; faster < n; faster++){
            if (nums[faster] != nums[slower]){
                slower++;
                nums[slower] = nums[faster];
            }
            
        }
        return slower + 1;
    }
};
