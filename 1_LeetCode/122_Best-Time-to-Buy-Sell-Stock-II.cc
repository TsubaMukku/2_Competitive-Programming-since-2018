/*
    2020-09-16 
    今日の価格が前日の価格よりも大きいならば, 株を買って売れば良い
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = (int)prices.size();
        
        for (int i = 0; i +1 < n; i++ ){
            
            if (prices[i] < prices[i+1]) profit += (prices[i+1] - prices[i]);
        }

        return profit;
    }
};





/*
    *Author: Tsubasa Takamuku
    *Date: 2020/08/09 10:13
*/

// 1: brute-force approach
// TLE

// 2: keep on adding the difference between the consecutive numbers 
// prices[i] < prices[i+1]の場合のみ, 株を購入して売る
// i日目に株を買い, i+1日目に株を売却して利益を得る
// time complexity O(N), space complexity O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        for (int i = 0; i + 1 < (int)prices.size(); i++){
            if (prices[i] < prices[i+1]){
                max_profit += (prices[i+1] - prices[i]);
            }
        }
        
        return max_profit;
    }
};
