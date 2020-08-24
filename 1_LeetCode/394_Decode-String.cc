
class Solution {
private:
    
    string DecodeString(string s, int &i){
        
        string res;
        
        while (i < (int)s.size() && s[i] != ']'){
            
            if ( !isdigit( s[i] ) ) res += s[i++]; // ex. s[i] == 'a'
            else{
                int n = 0;
                
                while (i < s.size() && isdigit(s[i])) n = n * 10 + s[i++] - '0';
                
                i++; // '['
                string temp = DecodeString(s,i);
                i++; // ']'
                
                while (n > 0){
                    res += temp;
                    n--;
                }
            }
            
        }
        
        return res;
    }
    
public:
    string decodeString(string s) {
        int i = 0;
        return DecodeString(s,i);
    }
};
