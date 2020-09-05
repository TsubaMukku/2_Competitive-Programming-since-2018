#include <string>

using namespace std;

bool is_prime(int n){
  for (int i = 2; i * i <= n; i++){
    if (n % i == 0) return false;
  }
  return true;
}


std::string solve(int a, int b)
{
    string prime_streaming = "";
  int i = 2;
  while (prime_streaming.size() <= 25000){
    if ( is_prime(i) ) prime_streaming += to_string(i);
      i++;
  }
  
    return prime_streaming.substr(a,b); //..
}
