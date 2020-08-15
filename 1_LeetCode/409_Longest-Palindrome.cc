/*
    Author: Tsubasa Takamuku
    Date: 2020-08-15　9:35
    
    solution1: using the characteristics of a palindrome string
    
    palindrome:  if and only if the number of a letter whose appearance time is odd is at most 1.
    -> ある文字の出現回数がevenならば, すべてそのまま使える. oddならば, 出現回数-1 個使い, 最後にstringの中央に1文字挿入すれば良い.
    
    time complexity: O(N log N)
    space complexityL O(N)
*/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        
        int n = (int)s.size();
        for (int i = 0; i < n; i++) mp[s[i]]++;
        
        int ans = 0;
        int max_odd_numbers = 0;
        
        for (auto p : mp){
            int temp = (int)p.second;
            if ((temp) % 2 == 0) ans += temp;
            else{
               int temp2 = (temp / 2) * 2;
                ans += temp2;
                max_odd_numbers = 1;
            } 
        }
        
        ans += max_odd_numbers;
        return ans;
    }
};
