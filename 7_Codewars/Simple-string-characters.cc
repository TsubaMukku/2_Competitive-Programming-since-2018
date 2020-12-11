#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

std::vector<int> solve(std::string s){
    //..
  int upper = 0;
  int lower = 0;
  int num = 0;
  int special = 0;
  
  for (int i  = 0; i < (int)s.size(); i++){
    if ( isalpha(s[i]) ){
      if ( isupper(s[i]) ) upper++;
      else lower++;
    }
    else{
      if ('0' <= s[i] && s[i] <= '9') num++;
      else special++;
    }
    
  }
  vector<int> ans(4);
  ans[0] = upper, ans[1] = lower, ans[2] = num, ans[3] = special;
  
  return ans;
  
}
