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


/*
    solution2: mask bit
    
    1. 32bitを16bitブロック*2へ分割する -> 前後を入れ替える
    2. 16bitを8bitブロック*2へ分割する -> 前後を入れ替える
    3. 繰り返す.
    4. 1bitのブロックになったら, 終了する
    
*/


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
