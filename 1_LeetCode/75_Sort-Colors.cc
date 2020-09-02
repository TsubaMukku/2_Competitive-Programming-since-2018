class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num_of_red = 0;
        int num_of_while = 0;
        int num_of_blue = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0) num_of_red++;
            else if (nums[i] == 1) num_of_while++;
            else num_of_blue++;
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (num_of_red > 0) nums[i] = 0, num_of_red--;
            else if (num_of_while > 0) nums[i] = 1, num_of_while--;
            else nums[i] = 2;
        }
        
        return;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int p0 = 0, cur = 0;
        
        int p2 = (int)nums.size() - 1;
        
        while (cur <= p2){
            
            if (nums[cur] == 0){
                swap(nums[cur],nums[p0]);
                cur++, p0++;
            }
            else if (nums[cur] == 2){
                swap(nums[cur],nums[p2]);
                p2--;
            }
            else cur++;
        }
        
        return;
    }
};
