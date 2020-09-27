/*
question:

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.


ex.
Input: seats = [1,0,0,0,1,0,1]
Output: 2

*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = (int)seats.size();
        int prev = -1, future = 0;
        int res = 0;
        
        for (int i = 0; i < n; i++){
            
            if (seats[i] == 1) {
                prev = i;
            }
            else{
                while ( (future < n && seats[future] == 0) || future < i){
                    future++;
                }
            }
            
            int left = prev == -1  ? n : i-prev;
            int right = future == n ? n : future-i;
            res = max(res, min(left,right));
        }
        
        return res;
    }
};
