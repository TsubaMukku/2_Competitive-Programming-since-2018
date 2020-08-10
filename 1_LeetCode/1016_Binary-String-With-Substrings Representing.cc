/*
    *Author: Tsubasa Takamuku
    *Date: 2020-08-10　9:31

    *N ~ 1 までのbinary representationを作り, それらがSの部分文字列として存在するかどうかを調べる
*/


class Solution {
public:
    bool queryString(string S, int N) {
        
        while ( N > 0 ){
            // Nのbinary representationをつくる -> std::bitsetを利用せよ
            // N <= 1e9 より Nは32bitに収まる
            bitset<32> s(N);
            N--; 
            
            // binary representationをstring型へ変換する
            // to_string()はbitsetのメソッドである
            string target = s.to_string();
            
            // targetの先頭から調べて, 1が一番最初に出てくる場所のindexを取得する
            // Nの部分文字列を得る
            // Sの中にNの部分文字列 target.substr( target.find( "1" ) が存在するか否かを調べる
            // npos: find()で文字列を見つけられない場合を示す
            if ( S.find ( target.substr( target.find( "1" ) ) ) ==  string::npos ) return false; // Nの部分文字列がSの中に存在しない
        }
        return true;
       
    }
};
