#include <string>
#include <map>

using namespace std;

std::string missing_alphabets(const std::string &s) {
  string ans = "";
  int repeat = 1;
  map<char,int> mp;
  
  for (char c : s){
    mp[c]++;
  }
  
  for (auto p : mp){
    repeat = max(repeat,p.second);
  }
    
    for (char i = 'a'; i <= 'z'; i++){
        
        while (mp[i] < repeat){
          ans += i;
          mp[i]++;
        }
        
    }
    
  return ans;
}
