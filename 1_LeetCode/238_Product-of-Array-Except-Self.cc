class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool exist_zero = false;
        bool more_than_two_zero = false;
        
        int product = 1;
        
        for (int i = 0; i < nums.size(); i++){
            
            if (exist_zero == false && nums[i] == 0){
                exist_zero = true;
            }
            else if (exist_zero == true && nums[i] == 0) more_than_two_zero = true;
            else{
                product *= nums[i];
            }
        }
        
        if (exist_zero == true && more_than_two_zero == false){
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] == 0) nums[i] = product;
                else nums[i] = 0;
            }
        }
        else if (exist_zero == true && more_than_two_zero == true){
            for (int i = 0; i < nums.size(); i++) nums[i] = 0;
        }
        else{
            for (int i = 0; i < nums.size(); i++){
                nums[i] = product / nums[i];
            }
        }
        
        return nums;
    }
};
