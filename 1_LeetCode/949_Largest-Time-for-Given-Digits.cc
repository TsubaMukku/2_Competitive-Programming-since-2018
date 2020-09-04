/*
    2020/09/04
*/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        string ans = "";
        int time = 0;
        do{
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];
            
            if (hour >= 24 || minute >= 60) continue;
            
            if (time > hour * 60 + minute) continue;
            
            time = hour * 60 + minute;
            
            if (hour < 10){
                ans = "0";
                ans += to_string(hour);
                ans += ":"; 
            }
            else{
                ans = to_string(hour);
                ans += ":";
            }
            
            if (minute < 10){
                ans += "0";
                ans += to_string(minute);
            }
            else{
                ans += to_string(minute);
            }
            
            
        } while (next_permutation(A.begin(),A.end()));
        
        return ans;
    }
};






class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        
        int max_time = -1;
        string ans = "";
        
        sort(A.begin(),A.end());
        
        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];
            
            if (hour < 24 && minute < 60){
                int new_time = hour * 60 + minute;
                
                max_time = max(max_time,new_time);
            }
            
        } while (next_permutation(A.begin(),A.end()));
        
        if (max_time == -1) return "";
        else{
            
            int ans_hour = max_time / 60;
            if (ans_hour < 10){
                ans += '0';
                ans += to_string(ans_hour);
                ans += ":";
            }
            else{
                ans += to_string(ans_hour);
                ans += ":";
            }
            
            
            int ans_minute = max_time % 60;
            if (ans_minute < 10){
                ans += '0';
                ans += to_string(ans_minute);
            }
            else{
                ans += to_string(ans_minute);
            }
            
            return ans;
        }
        
    }
};
