#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(){
    int n, m;
    std::cin >> n >> m;
    
    std::string s, t;
    std::cin >> s >> t;
    
    //dp tableを準備する
    //最大値を求める問題であるから, dp tableの値をすべて0で初期化しておく
    //dp[i][j]: s1...si, t1...tjに対するLCSの長さと定義する
    //dp[n][m]と定義すると, 配列の大きさが不足するため, RTEが生じることに注意せよ
    std::vector<std::vector<int>> dp(1010, std::vector<int>(1010));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            //例えば, abc, becと３番目の文字が共通である場合
            //文字列上で考えると, s[2] == t[2]の場合となるから
            //dp[3][3] = dp[2][2] + 1となる
            //添字の値がずれていることに注意せよ
            
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = std::max(dp[i+1][j], dp[i][j+1]);
        }
    }
    
    //求める答えは, dp[n][m]に記録されている
    //s1...sn, t1...tmに対するLCSの長さが, dp[n][m]に記録されている
    //これが求める答えである
    std::cout << dp[n][m] << std::endl;
    
    
}
