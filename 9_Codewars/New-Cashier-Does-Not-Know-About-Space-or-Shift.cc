#include <string>
#include <vector>

using namespace std;

vector<string> letters = {"", "Burger", "Fries", "Chicken", "Pizza", "Sandwich", "Onionrings", "Milkshake", "Coke"};
vector<int> appearance(9,0);
vector<int> go_next = {0,6,5,7,5,8,10,9,4};

std::string get_order(const std::string &order) {
  string ans = "";
  
  int i = 0;
  
  while (i < (int) order.size()){
    
    if (order[i] == 'b'){
      appearance[1]++;
      i += go_next[1];
    }
    else if (order[i] == 'f'){
      appearance[2]++;
      i += go_next[2];
    }
    else if (order[i] == 'c' && order[i+1] == 'h'){
      appearance[3]++;
      i += go_next[3];
    }
    else if (order[i] == 'p'){
      appearance[4]++;
      i += go_next[4];
    }
    else if (order[i] == 's'){
      appearance[5]++;
      i += go_next[5];
    }
    else if (order[i] == 'o'){
      appearance[6]++;
      i += go_next[6];
    }
    else if (order[i] == 'm'){
      appearance[7]++;
      i += go_next[7];
    }
    else {
      appearance[8]++;
      i += go_next[8];
    }
  }
  
  for (int i = 1; i <= 8; i++){
    while (appearance[i] > 0){
      ans +=letters[i];
      ans += " ";
      appearance[i]--;
    }
  }
  
  ans.erase(ans.size()-1);
  
  return ans;
}
