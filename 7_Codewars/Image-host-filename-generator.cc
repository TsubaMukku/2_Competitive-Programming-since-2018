#include <string>
#include <ctime>

using namespace std;

std::string generateName()
{
  // make sure to check the name is unique via the photoManager object
  
  string res = "******";
  
  for (int i = 0; i < 6; i++){
    if ( rand() % 2 == 0){
      res[i] = 'A' + rand() % 26;
    }
    else{
      res[i] = 'a' + rand() % 26;
    }
  }
  
  if (photoManager.nameExists(res) == false) return res;
  else generateName();
  
}

