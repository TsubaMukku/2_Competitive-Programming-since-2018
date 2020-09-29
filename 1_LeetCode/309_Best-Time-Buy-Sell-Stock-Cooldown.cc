class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = INT_MIN;
        int cooldown = 0;
        
        for (int price : prices){
            int temp1 = buy;
            int temp2 = sell;
            
            buy = max(buy,cooldown-price);
            sell = temp1 + price;
            cooldown = max(cooldown,temp2);
        }
        
        return max(sell,cooldown);
    }
};
