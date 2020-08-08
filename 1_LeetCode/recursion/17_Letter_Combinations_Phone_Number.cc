/*
  author: Tsubasa Takamuku
  date: 2020/08/07
  
  cf: EPI 15.2 compute all mnemonics for a phone number


*/

/* answer1: recursion */
class Solution {
private:
    const vector<string> mapping = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    
public:
    void findCombinations(string & digits, int digit, string temp,vector<string> &ans){
        if (digit == (int)digits.size()) {
            ans.push_back(temp);
        }
        else{
            for (char c : mapping[digits[digit] - '0']){
                string temp2 = temp + c;
                findCombinations(digits,digit+1,temp2,ans);
            }
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        if ((int)digits.size() == 0) return ans;
        findCombinations(digits,0,"",ans);
        return ans;
    }
};
