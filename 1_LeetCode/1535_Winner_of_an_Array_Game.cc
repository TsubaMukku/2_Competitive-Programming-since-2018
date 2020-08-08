/**
 *    author:  Tsubasa Takamuku
 *    created: 2020-08-02 13:28 
 *    arrの要素をすべて1回チェックする. そのループの間にcnt==kとなれば, その時保持している値が答えとなる. そうならずにループが終了した場合, arrの最大値が答えとなる. while文を使いcnt==kまで待つ場合はTLEとなる.
**/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = (int)arr.size();
        int winner = arr[0];
        int cnt = 0;
        
        for (int i = 1; i < n; i++){
            if (winner > arr[i]){
                cnt++;
                if (cnt == k) return winner;
            }
            else{
                cnt = 1;
                winner = arr[i];
                if (cnt == k) return winner;
            }
        }
        
        return winner;
    }
};
