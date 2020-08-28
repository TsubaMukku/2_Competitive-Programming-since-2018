class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        
        for (int i = 0; i < n; i++){
            int temp = i + 1;
            
            if (temp % 3 == 0 && temp % 5 == 0){
                ans[i] = "FizzBuzz";
            }
            else if (temp % 3 == 0){
                ans[i] = "Fizz";
            }
            else if (temp % 5 == 0){
                ans[i] = "Buzz";
            }
            else ans[i] = to_string(i+1);
        }
        
        return ans;
    }
};
