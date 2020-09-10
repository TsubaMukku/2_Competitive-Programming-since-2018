/*
    2020-09-11
    
*/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans = "";
        int largest_time = -1;
        int largest_hour = -1;
        int largest_minute = -1;
        
        sort(arr.begin(),arr.end());
        
        do{
            int hour = arr[0] * 10 + arr[1];
            int minute = arr[2] * 10 + arr[3];
            
            if (hour >= 24 || minute >= 60) continue;
            
            int comp = 60 * hour + minute;
            
            if (comp > largest_time){
                largest_hour = hour;
                largest_minute = minute;
                largest_time = comp;
            }
            
        } while (next_permutation(arr.begin(),arr.end()));
        
        if (largest_time == -1) return "";
        
        if (largest_hour < 10){
            ans = '0';
            ans += to_string(largest_hour);
            ans += ':';
        }
        else{
            ans = to_string(largest_hour);
            ans += ':';
        }
        
        if (largest_minute < 10){
            ans += '0';
            ans += to_string(largest_minute);
        }
        else{
            ans += to_string(largest_minute);
        }
        
        return ans; 
    }
};










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
