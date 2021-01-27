

// 2021/01/27
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = (int)chars.size();
        
        // write to the element at i and read from the element at j
        int i = 0;
        int cnt = 1;
        for (int j = 1; j <= n; j++){
            if (j == n || chars[j] != chars[j-1]){
                chars[i] = chars[j-1];
                i++;
                
                if (cnt >= 2){
                    for (char c : to_string(cnt)){
                    chars[i] = c;
                    i++;
                    }
                }
                cnt = 1;
            }
            else cnt++;
        }
        return i;
    }
};
