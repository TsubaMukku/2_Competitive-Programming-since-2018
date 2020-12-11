//UnionFind

できること
・グループ分けの管理ができる
・２つの要素の属するグループの併合ができる
・２つの要素が同じグループに属するか否かの判定を行うことができる


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




























//older version
/*
class UnionFind {
public:
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

//https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
*/
