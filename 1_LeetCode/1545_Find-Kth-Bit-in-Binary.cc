/*
    *Author: Tsubasa Takamuku
    *date: 2020-08-10 9:54
    
    *nの大きさが小さい　-> n = 1 ~ n = 20まで s_{n}をすべて作る
    *n = 21まで作れば, kは必ず k <= (s_{n}.size()) / 2 とできる.
    - > それまでに作ったsの結果を利用することができる
    
    k <= (s_{n}.size()) / 2 -> return s[k-1]; // 0-indexである
    k > (s_{n}.size()) / 2 -> s_{n+1}を作ってループを回す
    
*/


class Solution {
public:
    char findKthBit(int n, int k) {
        
        string s = "0";
        
        while (true){
            if ( k <= (int)s.size() ) return s[k-1];
        
            //  k > (s_{n}.size()) / 2 であるから s_{n+1}を作ってループを回す
            
            string later_part = s;
            reverse( later_part.begin(), later_part.end() );
            
            for (auto &c : later_part ){
                if ( c == '0' ) c = '1';
                else c = '0';
            }
            
            s = s + "1" + later_part;
        }
        
        
    }
};
