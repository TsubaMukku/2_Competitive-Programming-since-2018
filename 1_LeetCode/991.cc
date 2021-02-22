
/*
LeetCode 991. Broken Calculator
https://leetcode.com/problems/broken-calculator/

On a broken calculator that has a number showing on its display, we can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.

Example 1:

Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.

*/

// 2021/02/22

class Solution {
private:
    int INF = 1e9;
    
    int bfs(int &x, int &y,vector<int> &d){
        
        queue<int> q;
        q.push(x);
        d[x] = 0;
        
        while(q.size()){
            int p = q.front();
            q.pop();
            
            if (p == y) break;
            
            if (p <= 0) continue;
            if (d[2*p] == INF){
                 d[2*p] = d[p] + 1;
                q.push(2*p);
            }
            if (d[p-1] == INF){
                d[p-1] = d[p] + 1;
                q.push(p-1);
            }
            
        }
        
        return d[y];
}
    
    
public:
    int brokenCalc(int X, int Y) {
        if (X == Y) return 0;
        vector<int> d(1000000008,INF);
        return bfs(X,Y,d);
    }
};

/*
error message
=================================================================
==31==ERROR: AddressSanitizer: allocator is out of memory trying to allocate 0xee6b2820 bytes
    #5 0x7f43da4e80b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
==31==HINT: if you don't care about these errors you may set allocator_may_return_null=1
==31==ABORTING
*/
