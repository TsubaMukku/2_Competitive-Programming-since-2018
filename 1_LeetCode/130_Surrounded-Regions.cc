/*
    first, check the four border of the matrix: 
        if there is an element 'O', alter it and all its neighbor 'O' to '1'
    then alter all the ramaining 'O' to 'X'
    finally alter all '1' to original 'O'
*/

class Solution {
private:
    void dfs(vector<vector<char>> &board, int m, int n, int x, int y){
        
        if (x < 0 || m <= x || y < 0 || n <= y) return;
        if (board[x][y] != 'O') return;
        
        board[x][y] = 'G';
        
        dfs(board,m,n,x-1,y);
        dfs(board,m,n,x+1,y);
        dfs(board,m,n,x,y-1);
        dfs(board,m,n,x,y+1);
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int m = (int)board.size();
        
        if ( m == 0 ) return;
        
        int n = (int)board[0].size();
        
        
        for (int x = 0; x < m; x++){
            dfs(board,m,n,x,0);
            dfs(board,m,n,x,n-1);
        }
        
        for (int y = 0; y < n; y++){
            dfs(board,m,n,0,y);
            dfs(board,m,n,m-1,y);
        }
        
        for (int x = 0; x < m; x++){
            for (int y = 0; y < n; y++){
                
                if (board[x][y] == 'X') board[x][y] = 'X';
                else if (board[x][y] == 'O') board[x][y] = 'X';
                else board[x][y] = 'O';
            }
        }
        
        return;
    }
};
