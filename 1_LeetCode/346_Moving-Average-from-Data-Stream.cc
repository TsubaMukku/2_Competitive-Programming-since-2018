







class MovingAverage {
private: 
    int k;
    vector<int> nums;
    int sum;
    int i;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->k = size;
        this->sum = 0;
        this->i = 0;
    }
    
    double next(int val) {
        if (i < k){
            nums.emplace_back(val);
            sum += val;
            i++;
            return (double)sum / (double)i;
        }
        else{
            sum -= nums[i-k];
            nums.emplace_back(val);
            sum += val;
            i++;
            return (double)sum / (double)k;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
