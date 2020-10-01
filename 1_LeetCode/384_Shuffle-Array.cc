/*
Shuffle a set of numbers without duplicates.

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();
*/

class Solution {
private:
    vector<int> nums;
    vector<int> copy;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->copy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());
        std::shuffle(this->nums.begin(), this->nums.end(), engine);
        return this->nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
