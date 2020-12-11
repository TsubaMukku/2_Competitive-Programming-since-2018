#include <stack>
#include <string> 
#include <algorithm>

using namespace std;

std::string cleanString(const std::string &s) {
    // your code here
  int n = (int)s.size();
    if (n == 0) return "";
  stack<char> st;
  for (char c : s){
    if ( c != '#') st.push(c);
    else if ( !st.empty() && c == '#') st.pop();
    else continue;
  }
  
  string ans = "";
  while (!st.empty()){
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(),ans.end());
  return ans;
}


std::string solve(std::string s){
  
  
  int start = 0, last = s.length()-1, temp_i, temp_j, cnt = 0; 
  
  
  while (start <= last) {
    temp_i = start, temp_j = last; 
    
    
    if (s[start] == s[last]) start++, last--; 
    else if (s[start] != s[last] && s[start+1] == s[last]){
      start++, cnt++; 
    } 
    else if (s[start] != s[last] && s[start] == s[last-1]){
      last--, cnt++; 
    } 
      
    if ((temp_i == start && temp_j == last) || cnt >= 2) return "not possible"; 
  }
  
  if (cnt == 0) return "OK";
  else return "remove one";
  
}
