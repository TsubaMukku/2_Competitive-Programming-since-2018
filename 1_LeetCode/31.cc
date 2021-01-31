

// 2021/02/01
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1])i--;
        
        if (i == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int j = n - 1;
        while (j >= 0 && nums[i] >= nums[j])j--;
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};




// solution 1:

/*
  Author: Tsubasa Takamuku
  Date: 2020-08-11　9:49
*/

class Solution {
private:
    void reverse(vector<int> &nums,int start){
        int i = start, j = (int)nums.size()-1;

        while (i < j){
            swap(nums,i,j);
            i++;
            j--;
        }
        
    }
    
    void swap(vector<int> &nums,int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
public:
    void nextPermutation(vector<int>& nums) {
        int i = (int)nums.size() - 2;
        
        while ( i >= 0 && nums[i+1] <= nums[i]){
            i--;
        }
        
        if (i >= 0){
            int j = (int)nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) j--;
            swap(nums,i,j);
        }
        reverse(nums,i+1);
    }
};


/*
EPI:
if (i == -1) return vector<int>();
else reverse(nums,i+1)
*/



// solution 2:
/*
  Cited from https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
}; 


// 2020-12-25
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        
        int i = nums.size()-2;
        
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        
        if (i < 0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int j = nums.size()-1;
        
        while (j >= 0 && nums[i] >= nums[j]) j--;
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};
