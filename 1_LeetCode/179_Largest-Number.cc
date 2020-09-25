Given a list of non negative integers, arrange them such that they form the largest number.

class Solution {
public:
    string largestNumber(vector<int> &num) {
        
        vector<string> res;
        bool all_zero = true;
        
        for(auto x :num){
            res.push_back(to_string(x));
            if (x != 0) all_zero = false;
        }
        
        if (all_zero) return "0";
        
        sort(res.begin(), res.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        
        string ans;
        for(auto s : res) ans += s;
        return  ans;
    }
};
