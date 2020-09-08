class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int temp_sum = 0;
        int res = 0;
        
        int count = 0;
        int i = 0, j = 0;
        
        while (i < arr.size()){
            
            if (count < k){
                temp_sum += arr[i];
                count++;
                i++;
            }
            else{
                temp_sum -= arr[j];
                j++;
                count--;
            }
            if (count == k && temp_sum / k >= threshold) res++;
            
        }
        
        return res;
    }
};
