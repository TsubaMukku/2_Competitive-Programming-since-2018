#include <string>
#include <vector>
using namespace std;

std::vector<std::string> uniq(const std::vector<std::string> &v) {
  
  vector<string> ans;
  int n = (int)v.size();
  
  if (n <= 1) return v;
  
  for (size_t i = 0; i +1 < v.size(); i++) if (v[i] != v[i + 1]) ans.emplace_back(v[i]);
  ans.emplace_back( v[n-1] );
  return ans;
}
