

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
