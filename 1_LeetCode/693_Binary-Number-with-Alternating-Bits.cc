class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int check;
        if (n & 1 == 1) check = 0;
        else check = 1;
        
        while (n > 0){
            
            if ( (n & 1) == 1 && check == 1) return false;
            else if ((n & 1) == 1 && check == 0){
                check = 1;
                n >>= 1;
            }
            else if ((n & 1) == 0 && check == 1){
                check = 0;
                n >>= 1;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
