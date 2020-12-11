#include <vector>
#include <numeric>

using namespace std;

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
  //your code here
  vector<unsigned long long> res;
  unsigned long long total_sum = accumulate(ls.begin(),ls.end(),0);
  
  res.emplace_back(total_sum);
  
  for (int i = 0; i < (int)ls.size(); i++){
    total_sum -= ls[i];
    res.emplace_back(total_sum);
  }
  
  return res;
  
}
