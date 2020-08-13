/*
    Author: Tsubasa Takamuku
    Date: 2020-08-13　10:45
    
    unit32_t: 32ビットの符号なし整数型を意味する.
    
*/

/*  solution1: brute-force

    time complexity: O(nの長さ)
    space complexity: O(1)
    
    pros: シンプルで単純である. バグを埋め込みにくい. 他人にも理解しやすい. 保守がしやすいと言える.
    
    cons:このアルゴリズムには無駄がある:
    ex1. n = 100000000000000000000の場合, 1つしかない1を数えるまでの時間が無駄になる.
    
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int number_of_1_bits = 0;
        
        while (n > 0){
            if (n & 1) number_of_1_bits++;
            n >>= 1;
        }
        return number_of_1_bits;
    }
};



