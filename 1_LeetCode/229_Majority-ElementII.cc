class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1 = 0;
        int count2 = 0;
        
        long long  candidate1 = 0;
        long long  candidate2 = -1;
        
        for (int num : nums){
            
            if (candidate1 == num){
                count1++;
            }
            else if (candidate2 == num){
                count2++;
            }
            else if (count1 == 0){
                candidate1 = num;
                count1++;
            }
            else if (count2 == 0){
                candidate2 = num;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
            
        }
        
        vector<int> res;
        
        count1 = 0, count2 = 0;
        
        for (int num : nums){
            if (num == candidate1)count1++;
            if (num == candidate2)count2++;
        }
        
        int n = (int)nums.size();
        if (count1 > n/3) res.emplace_back(candidate1);
        if (count2 > n/3) res.emplace_back(candidate2);
        return res;
    }
};
