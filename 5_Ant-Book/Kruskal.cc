#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MAX =  100000;
const long long MAX_E = 100000;

class UnionFind{
public:

    //親の番号を格納する. Parentだった場合は−(the size)とする
    vector<int> Parent;
    
    //作るときはParentの値を全て-1にする
    //こうすると, すべての頂点が根となる
    UnionFind(int N){
        Parent = vector<int>(N, -1);
    }
    
    //Aがどのグループに属しているか調べる
    int root(int A){
        if (Parent[A] < 0) return A; //自分のグループにいる
        return Parent[A] = root(Parent[A]); //親をつなぎ替える
    }
    
    //size関数を作る
    //自分の所属するグループの頂点数を調べる
    long long size(int A){
        return -Parent[root(A)]; //親をとりたい
    }
    
    //AとBをくっつける
    bool connect(int A, int B){
        //AとBを直接繋がない
        //root(A) に root(B)をくっつける　
        //リーダー同士をくっつける
        
        A = root(A);
        B = root(B);
        
        if (A == B){
            return false; //すでにくっついてる
        }
            
        //大きい方に小さい方をくっつけたい
        //大小が逆だったらひっくり返す
            
        if(size(A) < size(B)) swap(A, B);
        
        //Aのサイズを更新する
        Parent[A] += Parent[B];
        
        //BのParentをAに変更する
        Parent[B] = A;
        
        return true; //くっついた
    }
    
};

struct edge{ int u, v, cost; };

bool comp(const edge &e1, const edge &e2){
    return e1.cost < e2.cost;
}

int V,E;
edge es[MAX_E];

/*
Kruskal method　: MSTを求めるアルゴリズムの一つである
(1) edgeをコストの小さい順に見る
(2) 閉路ができないならば, そのedgeを追加する
(3) u, vが同じ連結成分に属していないならば, ２辺を結ぶ辺を追加しても閉路はできない
*/

int kruskal(){
    
    sort(es, es+E, comp);
    
    UnionFind uni(V); // initialization
    
    int res = 0;
    
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        
        // u, vが同じ連結成分に属していないならば
        if (uni.root(e.u) != uni.root(e.v)) {
            uni.connect(e.u, e.v); // ２辺を結ぶ辺を追加しても閉路はできない
            res += e.cost; 
            
        }
    }
    return res;
}

int main(){
    
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        
        int s,t,w;
        cin >> s >> t >> w;
        
        es[i]=(edge){s, t, w};
    }
    
    
    cout << kruskal() << endl;
    return 0;
}







