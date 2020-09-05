include <vector>

std::vector<int> two_oldest_ages(std::vector<int> ages)
{
    // your solution goes here
  vector<int> ans;
  sort(ages.rbegin(),ages.rend());
  ans.emplace_back(ages[1]);
  ans.emplace_back(ages[0]);
    return ans;
}
