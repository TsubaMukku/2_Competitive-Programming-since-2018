/*
    *Author: Tsubasa Takamuku
    *Date: 2020/08/09 9:21
*/

// 1: j > i の s[j] - s[i]の値をすべて調べる (brute-force)
// time complexity: O(N * N) space complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        if (n <= 1) return 0;
        
        int maxProfit = prices[1] - prices[0];
        for ( int i = 0; i <= n-2; i++ ){
            for ( int j = i + 1; j <= n - 1; j++ ){
                maxProfit = max ( maxProfit, prices[j] - prices[i] );
            }
        }
        
        return max( 0, maxProfit );
    }
};

// 2: その日までの価格の最小値を保持しておく
// 当日の値 - その日までの価格の最小値 > それまでの利益の最大値ならば
// 利益の最大値を当日の値 - その日までの価格の最小値 で更新する
// その日までの価格の最小値を必ず更新する
// time complexity: O(N) space complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ((int)prices.size() == 0) return 0;
        int min_price_so_far = prices[0];
        int max_profit = 0;
        
        for (int p : prices){
            int max_profit_sell_today = p - min_price_so_far;
            max_profit = max ( max_profit, max_profit_sell_today );
            min_price_so_far = min ( min_price_so_far, p );
        }
        
        return max_profit;
    }
};

