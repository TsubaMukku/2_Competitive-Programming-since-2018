class Solution {
public:
    /*
        関数の役割: 区間[1,n]の中で残される数字を求める.
        引数: int n: 配列の最大要素の値 bool is_going_to_right:left-> rightか否かを示す. trueであればleft->rightの動きを, falseであればright->leftの動きを表す.
        返り値: 区間[1,n]の中で残される数字を返す.
    */
    int LastRemaining(int n, bool is_going_to_right){
        
        // base case
        if ( n == 1 ) return 1;
        
        if ( (n % 2 == 1) && is_going_to_right) {
            
            // left->right && n:odd
            // 1 2 3 4 5 6 7 -> left: 2 4 6
            return LastRemaining( n / 2, !is_going_to_right) * 2;
            
        }
        else if ( (n % 2 == 0) && is_going_to_right){
            
            // left -> right && n:even
            // 1 2 3 4 5 6 -> left: 2 4 6
            return LastRemaining( n / 2, !is_going_to_right) * 2;  
            
        }
        else if ( (n % 2 == 1) && !is_going_to_right){
            
            // right -> left && n:odd
            // 1 2 3 4 5 6 7 -> left: 2 4 6
            return LastRemaining( n / 2, !is_going_to_right) * 2;

        }
        else{
            
            // right -> left && n:even
            // 1 2 3 4 5 6  -> left: 1 3 5 : 初項1, 公差2の等差数列である 一般項 2*n - 1
            return LastRemaining( n / 2, !is_going_to_right) * 2 - 1;
            
        }
        
    }
    
    int lastRemaining(int n) {
        return LastRemaining( n,true );
    }
};
