class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        
        vector<int> secret_nums(10,0);
        vector<int> guess_nums(10,0);
        
        int n = (int)secret.size();
        if (n == 0) return "0A0B";
        
        for (int i = 0; i < n; i++){
            char temp1 = secret[i];
            char temp2 = guess[i];
            
            if (temp1 == temp2)bull++;
            else{
                secret_nums[temp1-'0']++;
                guess_nums[temp2-'0']++;
            }
        }
        
        for (int i = 0; i < 10; i++){
            cow += min(secret_nums[i],guess_nums[i]);
        }
        
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};
