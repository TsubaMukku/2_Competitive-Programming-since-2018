/*
  2020/09/16
*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        
        
        // reverse the whole string 
        reverse(s.begin(),s.end());
        
        int n = (int)s.size();
        int index = 0;
        
        for (int start = 0; start < n; start++){
            
            if (s[start] != ' '){
                
                // go to the beginning of the word
                if (index != 0) s[index++] = ' ';
                
                // go to the end of the word
                int end = start;
                while (end < n && s[end] != ' ')s[index++] = s[end++];
                
                // reverse the word
                reverse(s.begin()+index - (end -start), s.begin()+index);
                
                start = end;
            }
        }
    }
};
