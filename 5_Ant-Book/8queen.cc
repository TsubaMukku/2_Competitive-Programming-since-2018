#include<bits/stdc++.h>
using namespace std;
 
char field[10][10];
bool row[10],column[10];
vector<int>order;
bool endFlag;
 
 
//check whether there exists a queen in a row, column, dpos, dneg.
bool check(){
    
    //行についてqueenの判定
    for(int i=0;i<8;i++){ 
        int cnt=0;
        
        //ある行に存在するqueenの数を数えている
        for(int j=0;j<8;j++)if(field[i][j]=='Q')cnt++; 
        
        //ある行に２つ以上queenが存在したらアウト
        if(cnt>1)return false; 
    }
    
    //列についてqueenの判定
    for(int j=0;j<8;j++){
        
        int cnt=0; 
        
        //ある列に存在するqueenの数を数えている
        for(int i=0;i<8;i++)if(field[i][j]=='Q')cnt++; 
        
        //ある列に２つ以上queenが存在したらアウト
        if(cnt>1)return false; 
    }
    
    //左上から右下への対角線より左側の領域について判定
    for(int i=0;i<8;i++){
        
        int cnt=0;
        
        for(int j=0;j<8-i;j++){ 
            if(field[i+j][j]=='Q')cnt++; 
        }
        
        //左斜に２つ以上queenが存在したらアウト
        if(cnt>1)return false; 
    }
    
    //左上から右下への対角線より右側の領域について判定
    for(int j=0;j<8;j++){
        
        int cnt=0;
        
        for(int i=0;i<8-j;i++){ 
            if(field[i][i+j]=='Q')cnt++;
        }
        
        //左斜に２つ以上queenが存在したらアウト
        if(cnt>1)return false; 
    }
    
    //右上から左下への対角線より右側の領域について判定
    for(int i=0;i<8;i++){
        
        int cnt=0;
        
        for(int j=0;j<8-i;j++){ 
            if(field[i+j][7-j]=='Q')cnt++;
        }
        
        //右斜に２つ以上queenが存在したらアウト
        if(cnt>1)return false; 
    }
    
    //右上から左下への対角線より左側の領域について判定
    for(int j=0;j<8;j++){
        
        int cnt=0;
        
        for(int i=0;i<=j;i++){ 
            if(field[i][j-i]=='Q')cnt++;
        }
        
        //右斜に２つ以上queenが存在したらアウト
        if(cnt>1)return false; 
    }
    
    //チェックを通過するならば,１つのqueenの配置に成功している
    return true;
}
 
void dfs(int t){
    
    if(endFlag)return; 
    
    if(t==8){
        if(check()){
            
            endFlag=true;
            
            for(int i=0;i<8;i++){
                for (int j = 0; j < 8; j++) cout << field[i][j];
                cout << endl;
            }
            
        }
        return;
    }
 
    if(row[t])dfs(t+1); //その行にqueenが配置済みならば,その行に新規のqueenを配置できない 
    else{ 
        //その行にはqueenがいない
    
        for(int i=0;i<8;i++){
            
            //その列にqueenが存在するならば,新規のqueenは配置できない 次へ行く
            if(column[i])continue; 
            
            column[i]=true; //その列にqueenを配置済みにする
            field[t][i]='Q'; //queenをあるマスに置いてみる
            dfs(t+1); //次の行の探索へ移動
            field[t][i]='.'; //探索に失敗したときは, queenを仮置したマスをもとに戻す
            column[i]=false; //列にはqueenがいない状態に戻す
        }
    }
    
}
 
int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++) field[i][j] = '.';
    }
    
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        field[x][y] = 'Q';
        column[y] = true;
        row[x] = true;
    }
 
    dfs(0);
    return 0;
}
