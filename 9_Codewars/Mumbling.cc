#include <string>

using namespace std;

class Accumul
{
public:
    static std::string accum(const std::string &s){
      string ans = "";
      for (int i = 0; i < s.size(); i++){
        char temp = tolower(s[i]);
        
        for (int j = 0; j <= i; j++){
          if (j == 0) ans += toupper(temp);
          else ans += temp;
        }
        ans += "-";
      }
      
      return ans.substr(0, ans.size()-1);
    }
};
