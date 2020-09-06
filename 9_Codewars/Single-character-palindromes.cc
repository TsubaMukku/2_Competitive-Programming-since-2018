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
