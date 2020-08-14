/*
    solution1: bit by bit
    -> index iの場所にある数値は, reverse bitsの後, 31 - i番目の場所へ移動する.
    -> この操作を実装すれば良い.
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans = 0, power = 31;
        
        while (n > 0){
            
            // index iの場所にある数値は, reverse bitsの後, 31 - i番目の場所へ移動する.
            ans += (n & 1) << power;
            
            // LSBを次のものへ移動させる.
            n >>= 1;
            
            // 次の移動先のindexは, 1小さくなる.
            power--;
        }
        
        return ans;
    }
};

