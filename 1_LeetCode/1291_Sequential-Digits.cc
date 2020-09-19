class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string sample = "123456789";
        int n = 10;
        vector<int> res;
        
        int low_length = (int)(to_string(low)).size();
        int high_length = (int)(to_string(high)).size();
        
        // 桁数を動かす
        for (int l = low_length; l <= high_length; l++){
            
            // 部分文字列の開始地点を動かす
            for (int start = 0;start + l <= n-1; start++){
                
                string sub = sample.substr(start,l);
                int num = stoi(sub);
                
                if (low<= num && num <= high) res.emplace_back(num);
            }
        }
        return res;
    }
};
