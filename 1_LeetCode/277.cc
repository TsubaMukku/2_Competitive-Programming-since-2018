
// 2021/02/24

class Solution {
private:
    bool isCelebrity(int i, int n){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            
            if (knows(i,j) || !knows(j,i)) return false;
        }
        return true;
    }
public:
    int findCelebrity(int n) {
        int candidate = 0;
        
        for (int i = 0; i < n; i++){
            if (knows(candidate,i)) candidate = i;
        }
        if (isCelebrity(candidate,n)) return candidate;
        else return -1;
    }
};

class Solution {
private:
    bool isCelebrity(int i, int n){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            
            if (knows(i,j) || !knows(j,i)) return false;
        }
        return true;
    }
public:
    int findCelebrity(int n) {
        for (int i = 0; i < n; i++){
            if (isCelebrity(i,n)) return i;
        }
        
        return -1;
    }
};


// 2020-09-28

class Solution {
private:
    int number;
public:
    bool isCelebrity(int x){
        for (int j = 0; j < number; j++){
            if (j == x) continue;
            if (knows(x,j) || !knows(j,x)) return false;
        }
        return true;
    }
    int findCelebrity(int n) {
        this->number = n;
        for (int i = 0; i < n; i++){
            if (isCelebrity(i)) return i;
        }
        return -1;
    }
};
